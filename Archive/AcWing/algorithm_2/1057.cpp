#include<iostream>
#include<cstring>
using namespace std;

const int N=100010;
const int D=110;
const int INF=0x3f3f3f3f;
int dp[N][D][2];//在第i天，交易次数为j的最大值

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    memset(dp,0xcf,sizeof dp);
    for(int i=0;i<=n;i++) dp[i][0][0]=0;
    
    for(int i=1;i<=n;i++){//循环所有天数
        int price;
        cin>>price;
        for(int j=1;j<=k;j++){
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+price);
            dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-price);
        }
    }
    int ans=0;
    for(int i=1;i<=k;i++) ans=max(ans,dp[n][i][0]);
    cout<<ans;
    return 0;
}