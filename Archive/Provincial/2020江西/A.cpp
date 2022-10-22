#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
LL mod=998244353;

const int N=510;
LL dp[N][N*2];//第i列，当前走过1数量为j的方案数
int matrix[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,p,q;//0>=p&&1>=q
    cin>>n>>m>>p>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>matrix[i][j];

    if(matrix[1][1]) dp[1][1]=1;
    else dp[1][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(i==1&&j==1) continue;
            if(matrix[i][j])
                for(int k=N*2-1;k>=0;k--)
                    dp[j][k]=(dp[j][k-1]+dp[j-1][k-1])%mod;
            else
                for(int k=N*2-1;k>=0;k--)
                    dp[j][k]=(dp[j][k]+dp[j-1][k])%mod;
        }
    LL ans=0;
    for(int i=q;i<=n+m-1-p;i++) ans=(ans+dp[m][i])%mod;
    cout<<ans;
    return 0;
}