#include<iostream>
using namespace std;

const int N=110;
int dp[N][N];//从前n组物品选，体积不超过j的最大价值
int volume[N][N];//物品体积
int value[N][N];//物品价值
int n,v,s;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>v;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=s;j++) cin>>volume[i][j]>>value[i][j];
        
        for(int j=1;j<=v;j++){
            //枚举每个物品
            dp[i][j]=dp[i-1][j];
            for(int k=1;k<=s;k++)
                if(j-volume[i][k]>=0)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-volume[i][k]]+value[i][k]);
        }
    }
    cout<<dp[n][v];
    return 0;
}