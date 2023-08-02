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
constexpr int N=2e5+10,INF=N;
int dp[N][3];

void solve() {
    int n;
    cin>>n;
    dp[0][1]=0;
    dp[0][0]=dp[0][2]=INF;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in==0) {
            dp[i][0]=min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=min(dp[i-1][1]+1,dp[i-1][2]);
            dp[i][2]=INF;
        }
        else if(in==1) {
            dp[i][0]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
            dp[i][1]=dp[i-1][0]+1;
            dp[i][2]=min(dp[i-1][1]+1,dp[i-1][2]);
        }
        else {
            dp[i][0]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
            dp[i][1]=INF;
            dp[i][2]=min({dp[i-1][0]+1,dp[i-1][1]+1,dp[i-1][2]});
        }
        debug(i,dp[i]);
    }
    cout<<min(dp[n][1],dp[n][2])<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}