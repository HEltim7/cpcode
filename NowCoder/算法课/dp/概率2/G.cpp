#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=1e5+10;
LD dp[N],len[N],p[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) {
        dp[i]=dp[i-1]+p[i]*(len[i-1]*2+1);
        len[i]=p[i]*(len[i-1]+1);
    }
    cout<<fixed<<setprecision(15)<<dp[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}