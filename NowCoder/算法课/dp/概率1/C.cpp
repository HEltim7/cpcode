#include <iomanip>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=110;
LD dp[N];
int a[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[n]=a[n];
    for(int i=n-1;i>=1;i--) {
        LD p=LD(1)/min(6,n-i);
        for(int j=i+1;j<=min(n,i+6);j++) dp[i]+=dp[j];
        dp[i]=dp[i]*p+a[i];
    }
    cout<<fixed<<setprecision(12);
    cout<<dp[1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}