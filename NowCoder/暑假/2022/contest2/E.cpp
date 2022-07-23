#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e3+10,A=26,mod=998244353;
LL dp[N][N][3];

void solve() {
    int n;
    cin>>n;
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i/3;j++) {
            dp[i][j][0]=((A-1)*dp[i-1][j][0]+(A-2)*dp[i-1][j][1]+(A-2)*dp[i-1][j][2])%mod;
            if(j) dp[i][j][0]=(dp[i][j][0]+dp[i-1][j-1][2])%mod;
            dp[i][j][1]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%mod;
            dp[i][j][2]=dp[i-1][j][1];
        }
    for(int i=0;i<=n;i++) cout<<(dp[n][i][0]+dp[n][i][1]+dp[n][i][2])%mod<<" ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}