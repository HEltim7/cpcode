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
constexpr int N=1e5+10;
constexpr LL INF=1e18;
LL val[N];

void solve() {
    int n;
    cin>>n;
    LL p,x,q,y;
    cin>>p>>x>>q>>y;
    LL sum=0;
    for(int i=1,in;i<=n;i++) cin>>in,sum+=in;
    for(int i=0;i<=n;i++) val[i]=INF;

    sum%=n;
    for(int i=0;i<n;i++) {
        LL t=(i*x)%n;
        val[t]=min(val[t],i*p);
    }

    LL ans=INF;
    y%=n;
    y=(n-y)%n;
    for(int i=0;i<n;i++) {
        LL t=(sum+y*i)%n;
        t=(n-t)%n;
        ans=min(ans,val[t]+i*q);
    }
    cout<<(ans==INF?-1:ans)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}