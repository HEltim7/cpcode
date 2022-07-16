#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e3+10,mod=998244353;
LL dp[N][N];

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    dp[1][0]=m;
    for(int i=2;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i-1][j-1]*(m-1)%mod)%mod;
        }
    }
    cout<<dp[n][k]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}