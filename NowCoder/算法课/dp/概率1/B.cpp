#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=1e3+10;
LD dp[N][N];

void solve() {
    cout<<fixed<<setprecision(12);
    int n,s;
    cin>>n>>s;
    dp[n][s]=0;
    for(int i=n;i>=0;i--) {
        for(int j=s-(i==n);j>=0;j--) {
            LD pn=LD(i)/n,_pn=1-pn;
            LD ps=LD(j)/s,_ps=1-ps;
            dp[i][j]=(
                pn*ps+
                _pn*ps*(dp[i+1][j]+1)+
                pn*_ps*(dp[i][j+1]+1)+
                _pn*_ps*(dp[i+1][j+1]+1)
            )/(1-pn*ps);
        }
    }
    cout<<dp[0][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}