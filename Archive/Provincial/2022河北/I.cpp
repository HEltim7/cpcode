#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using LL=long long;
constexpr int mod=1e9+7,N=1e6+10;
LL dp[N][2];

void solve() {
    int n;
    LL m;
    cin>>n>>m;
    dp[1][0]=m;
    for(int i=2;i<=n;i++) {
        dp[i][1]=dp[i-1][0];
        dp[i][0]=(dp[i-1][1]*(m-1-(i>=4?1:0))%mod+dp[i-1][0]*(m-1-(i>=3?1:0))%mod)%mod;
    }
    cout<<(dp[n][1]+dp[n][0])%mod<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}