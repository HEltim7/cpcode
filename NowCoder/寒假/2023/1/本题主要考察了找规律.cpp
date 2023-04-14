#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=510;
LD dp[N][N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=m;j++) {
            for(int k=0;k+j<=m;k++) {
                if(j+k) dp[i+1][j+k]=max(dp[i+1][j+k],dp[i][j]+LD(1)*k/(k+j));
            }
        }
    }
    cout<<fixed<<setprecision(12);
    cout<<dp[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}