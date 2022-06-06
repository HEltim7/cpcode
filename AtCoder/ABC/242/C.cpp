#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e6+10,mod=998244353;
LL dp[N][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=9;i++) dp[1][i]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=9;j++){
            dp[i][j]+=dp[i-1][j];
            if(j>=2) dp[i][j]+=dp[i-1][j-1];
            if(j<=8) dp[i][j]+=dp[i-1][j+1];
            dp[i][j]%=mod;
        }
    LL ans=0;
    for(int i=1;i<=9;i++) ans=(ans+dp[n][i])%mod;
    cout<<ans;
    return 0;
}