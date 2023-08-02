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
constexpr int N=1e6+10;
LL a[N],b[N];

void solve() {
    int n;
    cin>>n;
    LL ans=0,tot=0;
    vector<pair<LL,LL>> vec;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) tot+=abs(a[i]-b[i]);
    for(int i=1;i<=n;i++) vec.emplace_back(min(a[i],b[i]),max(a[i],b[i]));
    ans=tot;

    LL maxx=0;
    sort(vec.begin(),vec.end());
    debug(vec);
    for(auto [a,b]:vec) {
        LL r=min(maxx,b);
        ans=min(ans,tot-max(0LL,r-a)*2);
        maxx=max(maxx,b);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}