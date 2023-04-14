#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10,M=110;
int dp[M][N];
int l[N],h[N],v[N],w[N],lim[N];

void solve() {
    int n,m;
    cin>>n>>m;
    cin>>v[m+1]>>w[m+1];
    lim[m+1]=N;
    for(int i=1;i<=m;i++) cin>>l[i]>>h[i]>>v[i]>>w[i],lim[i]=l[i]/h[i];
    int ans=0;
    for(int i=1;i<=m+1;i++) {
        for(int j=0;j<=n;j++) {
            for(int k=0;k<=lim[i];k++) {
                if(j-k*v[i]>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i]);
                ans=max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}