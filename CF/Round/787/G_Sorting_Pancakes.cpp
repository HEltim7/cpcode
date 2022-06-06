#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=255;
int dp[N][N][N];
int ddp[N][N];
int pre[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++) cin>>pre[i],pre[i]+=pre[i-1];

    for(int j=0;j<=m;j++)
        for(int k=0;k<=j;k++)
            dp[1][j][k]=min(dp[1][j][k],abs(pre[1]-j));

    for(int i=2;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=j;k++) 
                for(int p=k;p<=j-k;p++)
                    dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-k][p]+abs(pre[i]-j));

    int ans=0x3f3f3f3f;
    for(int i=0;i<=m;i++) ans=min(ans,dp[n][m][i]);
    cout<<ans;
    return 0;
}