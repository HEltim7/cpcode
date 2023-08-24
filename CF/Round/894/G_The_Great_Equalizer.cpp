#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n+1);
    multiset<int> st,dif;

    auto ins=[&](int x) {
        auto it=st.emplace(x);
        if(it!=st.begin()&&next(it)!=st.end())
            dif.erase(dif.find(*next(it)-*prev(it)));
        if(it!=st.begin()) dif.emplace(x-*prev(it));
        if(next(it)!=st.end()) dif.emplace(*next(it)-x);
    };

    auto del=[&](int x) {
        auto it=st.find(x);
        if(it!=st.begin()) dif.erase(dif.find(x-*prev(it)));
        if(next(it)!=st.end()) dif.erase(dif.find(*next(it)-x));
        if(it!=st.begin()&&next(it)!=st.end())
            dif.emplace(*next(it)-*prev(it));
        st.erase(it);
    };

    for(int i=1;i<=n;i++) cin>>arr[i],ins(arr[i]);

    int q;
    cin>>q;
    while(q--) {
        int p,x;
        cin>>p>>x;
        del(arr[p]);
        ins(arr[p]=x);
        if(n==1) cout<<*st.rbegin()<<' ';
        else cout<<*st.rbegin()+*dif.rbegin()<<' ';
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}