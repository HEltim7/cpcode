#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
constexpr LL INF=1e18;
LL cost[N],cmd[N],dp[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) dp[i]=INF;
    dp[n]=0;

    for(int i=1;i<=m;i++) cin>>cost[i]>>cmd[i];
    for(int i=n;i>=2;i--) {
        for(int j=1;j<=m;j++) {
            if(cmd[j]<=i) {
                int cur=i-i%cmd[j];
                dp[cur]=min(dp[cur],dp[i]+cost[j]);
            }
        }
    }
    for(int i=1;i<=n;i++) if(dp[i]<INF) {
        cout<<dp[i];
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}