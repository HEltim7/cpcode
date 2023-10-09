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
    string s;
    LL pos;
    cin>>s>>pos;
    int n=s.size();
    vector<bool> del(n);
    set<int> st;
    map<int,char> mp;
    mp[-1]=char('a'-1);
    for(int i=0;i<n;i++) mp[i]=s[i];
    mp[n]=char('z'+1);

    for(int i=0;i<n;i++) {
        if(mp[i]>mp[i+1]) st.emplace(i);
    }
    for(int len=n;len>=1;len--) {
        if(pos<=len) break;
        int idx;
        if(st.empty()) {
            idx=next(mp.rbegin())->first;
        }
        else {
            idx=*st.begin();
            st.erase(st.begin());
        }

        auto it=mp.find(idx);
        auto lit=prev(it);
        auto rit=next(it);
        bool x=lit->second>it->second;
        bool y=lit->second>rit->second;
        if(x!=y) {
            if(x) st.erase(lit->first);
            else st.insert(lit->first);
        }
        mp.erase(it);
        pos-=len;
    }

    auto it=mp.begin();
    for(int i=1;i<=pos;i++) it=next(it);
    cout<<it->second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}