#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int mod=1e9+7,N=2e3+10;
LL dp[N][N],melon[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(n==0){
        for(int i=1;i<=m;i++) cout<<0<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>melon[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(!dp[i][j]) dp[i][j]=dp[i-1][j];
            if(j-melon[i]>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-melon[i]])%mod;
            if(j-melon[i]/2>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-melon[i]/2])%mod;
        }
    }
    for(int i=1;i<=m;i++) cout<<dp[n][i]<<' ';
    return 0;
}