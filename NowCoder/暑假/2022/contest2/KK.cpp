#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=210,mod=1e9+7;
LL dp[N][N][N];
char s[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=0;i<=m;i++) 
        for(int j=0;j<=m;j++) 
            memset(dp[i][j], 0, sizeof(LL)*(n+1));
    dp[0][0][0]=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<=n;k++) {
                int a=s[k+1]=='(';
                int b=a==0;
                dp[i+1][j+1][min(k+a,n)]=(dp[i+1][j+1][min(k+a,n)]+dp[i][j][k])%mod;
                if(j) dp[i+1][j-1][min(k+b,n)]=(dp[i+1][j-1][min(k+b,n)]+dp[i][j][k])%mod;
            }
    cout<<dp[m][0][n]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}