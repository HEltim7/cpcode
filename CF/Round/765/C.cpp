#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=510;
int pos[N],spd[N],dp[N][N];

void solve() {
    int n,l,k;
    cin>>n>>l>>k;
    for(int i=1;i<=n;i++) cin>>pos[i];
    for(int i=1;i<=n;i++) cin>>spd[i];
    memset(dp,0x3f,sizeof dp);
    k=n-k+1;
    pos[++n]=l;
    dp[1][1]=0;
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=n;j++) {
            for(int p=1;p<i;p++) {
                dp[i][j]=min(dp[i][j],dp[p][j-1]+spd[p]*(pos[i]-pos[p]));
            }
        }
    }

    int ans=dp[n][k];
    for(int i=k;i<=n;i++) ans=min(ans,dp[n][i]);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}