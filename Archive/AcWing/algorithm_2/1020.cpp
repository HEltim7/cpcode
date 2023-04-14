#include<iostream>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N =21+1,M=79+1;
int dp[N][M];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    int n,m,k;
    cin>>m>>n>>k;
    while(k--){
        int a,b,c;
        cin>>a>>b>>c;
        for(int i=N-1;i>=0;i--)
            for(int j=M-1;j>=0;j--)
                dp[i][j]=min(dp[i][j],dp[max(0,i-a)][max(0,j-b)]+c);
    }
    int ans=INF;
    for(int i=m;i<=N-1;i++) for(int j=n;j<=M-1;j++) ans=min(ans,dp[i][j]);
    cout<<ans;
    return 0;
}