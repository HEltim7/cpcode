#include<iostream>
using namespace std;

const int N=20;
int dp[N][N];
int volume[N][N];
int value[N][N];
int path[N];
int n,m;//m个公司，n台机器

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) cin>>value[i][j],volume[i][j]=j;

        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            for(int k=1;k<=n;k++)
                if(j-volume[i][k]>=0)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-volume[i][k]]+value[i][k]);
        }
    }
    cout<<dp[m][n]<<endl;

    int vol=n;
    for(int i=m;i>=1;i--){
        for(int j=1;j<=vol;j++){
            if(dp[i][vol]==dp[i-1][vol-volume[i][j]]+value[i][j]){
                path[i]=j;
                vol-=volume[i][j];
                break;
            }
        }
    }

    for(int i=1;i<=m;i++) cout<<i<<' '<<path[i]<<endl;

    return 0;
}