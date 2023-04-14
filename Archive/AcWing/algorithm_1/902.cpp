#include<iostream>
using namespace std;

const int N=1e3+10;
int dp[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    string a,b;

    cin>>n>>a;
    cin>>m>>b;
    a=' '+a,b=' '+b;

    for(int i=1;i<=n;i++) dp[i][0]=i;
    for(int i=1;i<=m;i++) dp[0][i]=i;

    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) 
            dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+(a[i]!=b[j]?1:0));

    cout<<dp[n][m];
    return 0;
}