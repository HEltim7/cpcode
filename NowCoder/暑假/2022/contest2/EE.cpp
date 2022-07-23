#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10,A=26,mod=998244353;
LL dp[2][N][3];

void solve() {
    int n;
    cin>>n;
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++) {
        int t=i&1;
        for(int j=0;j<=i/3;j++) {
            dp[t][j][0]=((A-1)*dp[!t][j][0]+(A-2)*dp[!t][j][1]+(A-2)*dp[!t][j][2])%mod;
            if(j) dp[t][j][0]=(dp[t][j][0]+dp[!t][j-1][2])%mod;
            dp[t][j][1]=(dp[!t][j][0]+dp[!t][j][1]+dp[!t][j][2])%mod;
            dp[t][j][2]=dp[!t][j][1];
        }
    }
    for(int i=0;i<=n;i++) cout<<(dp[n&1][i][0]+dp[n&1][i][1]+dp[n&1][i][2])%mod<<" ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}