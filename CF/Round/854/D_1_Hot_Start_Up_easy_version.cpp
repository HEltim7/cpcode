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
constexpr int N=5e3+10;
LL dp[N][N];
int arr[N],cold[N],hot[N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=k;i++) cin>>cold[i];
    for(int i=1;i<=k;i++) cin>>hot[i];

    auto get=[&](int l,int r) {
        return l==r?hot[r]:cold[r];
    };

    for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=1e18;
    dp[0][0]=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=k;j++) {
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+get(arr[i],arr[i+1]));
            dp[i+1][arr[i]]=min(dp[i+1][arr[i]],dp[i][j]+get(j,arr[i+1]));
        }
    }
    
    LL ans=1e18;
    for(int i=0;i<=k;i++) ans=min(ans,dp[n][i]);
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