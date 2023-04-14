#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;

void solve() {
    int n;
    cin>>n;
    multiset<LL> st;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        st.insert(in);
    }
    LL maxx=*st.rbegin();
    LL minn=*st.begin();
    LL lim=maxx-minn;

    vector<LL> ans;
    set<LL> pre;
    pre.insert(0);
    LL tot=0;
    for(int i=1;i<=n;i++) {
        auto it=st.lower_bound(lim-(tot-*pre.begin()));
        if(it==st.begin()) {
            cout<<"No"<<endl;
            return;
        }
        it--;
        LL x=*it;
        debug(x);
        st.erase(it);
        ans.push_back(x);
        tot+=x;
        pre.insert(tot);
        
        if(tot-*pre.rbegin()<=-lim) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
    for(auto x:ans) cout<<x<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}