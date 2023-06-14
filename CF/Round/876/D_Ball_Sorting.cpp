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

constexpr int N=5e3+10;
int dp[N][N],arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n+1;i++) memset(dp[i], 0x3f, sizeof(int)*(n+1));
    for(int i=1;i<=n;i++) cin>>arr[i];
    arr[n+1]=N;

    for(int i=1;i<=n+1;i++) {
        for(int j=0;j<=i;j++) {
            if(arr[i]>arr[i-1]) dp[i][j]=dp[i-1][j];
            if(!j) continue;
            for(int k=0;k<i;k++) {
                if(arr[i]>arr[k])
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+i-k-1);
            }
            dp[i][j]=min(dp[i][j],dp[i][j-1]);
        }
    }

    for(int i=1;i<=n;i++) cout<<dp[n+1][i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}