#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e3+10;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    auto dp=vector(5,vector(n+1,vector(k+1,LL(-1e18))));
    auto sign=vector<pair<int,int>>({
        {-1,1},{-1,-1},{1,1},{1,-1},
        {-1,1},{1,1},{-1,-1},{1,-1}
    });
    dp[4][0][0]=0;
    for(int i=1;i<=n;i++) {
        for(int t=0;t<4;t++) {
            auto [xl,yl]=sign[t];
            auto [xr,yr]=sign[t^4];
            for(int j=1;j<=k;j++) {
                dp[t][i][j]=max(
                    dp[t][i-1][j-1],
                    dp[4][i-1][j-1]+xl*a[i]+yl*b[i]
                );
            }

            for(int j=0;j<=k;j++) {
                dp[4][i][j]=max(dp[4][i][j],dp[4][i-1][j]);
                if(j) dp[4][i][j]=max({
                    dp[4][i][j],
                    dp[t][i-1][j-1]+xr*a[i]+yr*b[i],
                    dp[4][i-1][j-1]+abs(b[i]-a[i])+abs(b[i]-a[i])
                });
            }
        }
    }
    cout<<dp[4][n][k]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}