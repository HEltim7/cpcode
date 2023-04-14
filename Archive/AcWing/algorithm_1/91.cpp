#include<iostream>
#include<cstring>
using namespace std;

const int N=21;
const int M=1<<20;
int dp[M][N];
int matrix[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>matrix[i][j];

    memset(dp,0x3f,sizeof dp);
    dp[1][0]=0;

    for(int i=1;i<1<<n;i+=2){
        for(int j=0;j<n;j++){
            if(1<<j & i){//合法
                for(int k=0;k<n;k++){
                    if(1<<k & i && j!=k){
                        dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+matrix[k][j]);
                    }
                }
            }
        }
    }

    cout<<dp[(1<<n)-1][n-1];
    return 0;
}