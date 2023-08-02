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
constexpr LL INF=1e15;
LL arr[N],dp[N][4];
bool lid[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>lid[i];

    dp[0][1]=dp[0][2]=dp[0][3]=-INF;
    for(int i=1;i<=n;i++) {
        if(lid[i]) {
            dp[i][0]=dp[i-1][0]+arr[i-1];
            dp[i][1]=max({dp[i-1][0]+arr[i],dp[i-1][1]+arr[i],dp[i-1][3]+arr[i]});
            dp[i][2]=max(dp[i-1][2]+arr[i],dp[i-1][1]-arr[i-1]+arr[i]);
            dp[i][3]=-INF;
        }
        else {
            dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][3]});
            dp[i][1]=-INF;
            dp[i][2]=-INF;
            dp[i][3]=max(dp[i-1][2]+arr[i],dp[i-1][1]-arr[i-1]+arr[i]);
        }
    }

    cout<<max({dp[n][0],dp[n][1],dp[n][3]})<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}