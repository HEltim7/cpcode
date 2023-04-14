#include<iostream>
#include<cstring>
using namespace std;

#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=110;
int matrix[N][N];
int dp[N][N];

int main(){
    memset(dp,0x3f,sizeof dp);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>matrix[i][j],dp[i][j]=0;
            
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+matrix[i][j];
            
    cout<<dp[n][n];
    return 0;
}