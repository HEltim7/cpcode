#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=2e3+10;
LD dp[N][N],pw[N];

void solve() {
    int n,m,k;
    LD p1,p2,p3,p4;
    cin>>n>>m>>k>>p1>>p2>>p3>>p4;
    LD _p1=1-p1,px=p2/_p1;
    pw[0]=1;
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*px;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++)
            dp[i][i]+=pw[i-j]*(p3*dp[i-1][j-1])/_p1;
        for(int j=1;j<=min(k,i);j++)
            dp[i][i]+=pw[i-j]*p4/_p1;
        dp[i][i]=dp[i][i]/(1-pw[i]);

        dp[i][1]=px*dp[i][i]+p4/_p1;
        for(int j=2;j<=min(i,k);j++)
            dp[i][j]=px*dp[i][j-1]+(p3*dp[i-1][j-1]+p4)/_p1;
        for(int j=k+1;j<i;j++)
            dp[i][j]=px*dp[i][j-1]+(p3*dp[i-1][j-1])/_p1;
    }

    cout<<fixed<<setprecision(5)<<dp[n][m]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}