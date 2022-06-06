#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
const int N=510,INF=0x3f3f3f3f;
typedef long long LL;
int ans,n,l,k;
int loc[N],speed[N];
PII dp[N][N];//dp[物品][拆数]={值,速度}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>l>>k;
    memset(dp,0x3f,sizeof dp);
    loc[n+1]=l;
    for(int i=1;i<=n;i++) cin>>loc[i];
    for(int i=1;i<=n;i++) cin>>speed[i];
    dp[1][0]={speed[1]*(loc[2]-loc[1]),speed[1]};
    for(int i=2;i<=n;i++)
        for(int j=0;j<=k;j++){
            auto &[x,y]=dp[i][j];
            y=speed[i];
            if(x>dp[i-1][j].first+y*(loc[i+1]-loc[i]))
                x=dp[i-1][j].first+y*(loc[i+1]-loc[i]);
            else if(x==dp[i-1][j].first+y*(loc[i+1]-loc[i]))
                y=min(y,dp[i-1][j].second);
            if(j&&dp[i-1][j-1].first!=INF&&x>=dp[i-1][j-1].first+dp[i-1][j-1].second*(loc[i+1]-loc[i]))
                x=dp[i-1][j-1].first+dp[i-1][j-1].second*(loc[i+1]-loc[i]),
                y=dp[i-1][j-1].second;
        }
    int ans=INF;
    for(int i=0;i<=k;i++) ans=min(ans,dp[n][i].first);
    cout<<ans;
    return 0;
}