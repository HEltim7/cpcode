#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=15,K=105;
LD dp[K][1<<N];
int w[K],req[N];

void solve() {
    int r,n;
    cin>>r>>n;
    for(int i=0;i<n;i++) {
        cin>>w[i];
        int in;
        while(cin>>in&&in) req[i]|=1<<(in-1);
    }

    auto bad=[&](int j,int k) -> bool {
        return (j^req[k])&req[k];
    };

    const LD p=LD(1)/n;
    for(int i=1;i<=r;i++) {
        for(int j=0;j<1<<n;j++) {
            for(int k=0;k<n;k++) {
                if(bad(j,k)) dp[i][j]+=p*dp[i-1][j];
                else dp[i][j]+=p*max(dp[i-1][j],dp[i-1][1<<k|j]+w[k]);
            }
        }
    }

    cout<<fixed<<setprecision(6)<<dp[r][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}