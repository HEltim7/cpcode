#include <vector>
#include <cassert>
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
constexpr int N=2e5+10;
LL dp[N][2];
LL arr[N];

void solve() {
    int n;
    LL s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    auto get=[&](int i) {
        LL x=s,y=arr[i]-s;
        if(x>y) swap(x,y);
        if(x*y<0) {
            y-=-x;
            x=0;
        }
        assert(x+y==arr[i]&&x*y>=0);
        return make_pair(x,y);
    };

    auto [x,y]=get(2);
    dp[2][0]=x*arr[1];
    dp[2][1]=y*arr[1];
    for(int i=3;i<n;i++) {
        auto [px,py]=get(i-1);
        auto [x,y]=get(i);
        dp[i][0]=min(dp[i-1][0]+py*x,dp[i-1][1]+px*x);
        dp[i][1]=min(dp[i-1][0]+py*y,dp[i-1][1]+px*y);
    }

    auto [px,py]=get(n-1);
    LL ans=min(dp[n-1][0]+py*arr[n],dp[n-1][1]+px*arr[n]);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}