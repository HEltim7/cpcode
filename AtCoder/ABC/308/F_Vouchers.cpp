#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
constexpr int N=2e5+10,INF=1e9;
vector<LL> vec[N];

void solve() {
    int n,m;
    cin>>n>>m;
    
    LL ans=0;
    vector<LL> p(n);
    for(auto &x:p) cin>>x,ans+=x;
    p.emplace_back(INF);
    sort(p.begin(),p.end());

    vector<pair<LL,LL>> v(m);
    for(auto &[l,d]:v) cin>>l;
    for(auto &[l,d]:v) cin>>d;
    
    for(auto [l,d]:v) {
        int le=lower_bound(p.begin(),p.end(),l)-p.begin();
        int idx=n-le;
        vec[idx].emplace_back(d);
    }
    
    multiset<LL,greater<>> st;
    for(int i=n;i>=1;i--) {
        for(auto x:vec[i]) st.insert(x);
        if(st.size()) {
            debug(i,st);
            ans-=*st.begin();
            st.erase(st.begin());
        }
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}