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
constexpr int N=5e2+10,INF=0x3f3f3f3f;
LL dp[N][N]; //dp[l][r]=线段为[l,r]时无法缩成1的最小代价 *假的，可以先扩展再收缩
int cost[2][N][N];

void solve() {
    memset(cost, 0x3f, sizeof cost);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int l,r;
        char d;
        cin>>l>>r>>d;
        int x=d=='R';
        cin>>cost[x][l][r];
    }

    for(int i=1;i<=n;i++) dp[i][i]=INF;
    for(int i=1;i<n;i++) dp[i][i+1]=cost[0][i][i+1]+cost[1][i][i+1];
    for(int len=3;len<=n;len++) {
        for(int l=1,r=len;r<=n;l++,r++) {
            // LR限制
            dp[l][r]=LL(cost[0][l][r]+cost[1][l][r]);
            // L限制
            dp[l][r]=min(dp[l][r],cost[0][l][r]+dp[l][r-1]);
            // R限制
            dp[l][r]=min(dp[l][r],cost[1][l][r]+dp[l+1][r]);
            // 无限制
            dp[l][r]=min(dp[l][r],dp[l+1][r]+dp[l][r-1]);
        }
    }

    if(dp[1][n]>=INF) cout<<-1<<endl;
    else cout<<dp[1][n]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}