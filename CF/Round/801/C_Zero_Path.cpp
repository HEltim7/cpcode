#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e3+10;
int grid[N][N];
using PII=pair<int,int>;
int dp[2][N][N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            cin>>grid[i][j];
            dp[0][i][j]=max(dp[0][i-1][j],dp[0][i][j-1]);
            dp[1][i][j]=max(dp[1][i-1][j],dp[1][i][j-1]);
            if(grid[i][j]==1) dp[1][i][j]++;
            else dp[0][i][j]++;
        }
    if((n+m-1)%2==1||dp[0][n][m]<(n+m-1)/2||dp[1][n][m]<(n+m-1)/2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}