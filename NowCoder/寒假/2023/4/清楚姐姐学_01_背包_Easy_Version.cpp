#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
LL dp[N][N];
int w[N],v[N];

LL get_dp(int n,int m) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    return dp[n][m];
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];

    LL valmax=get_dp(n, m);
    for(int i=1;i<=n;i++) {
        swap(w[i],w[n]);
        swap(v[i],v[n]);
        if(get_dp(n-1,m)<valmax) cout<<0<<endl;
        else {
            LL cur=get_dp(n-1, m-w[n])+v[n];
            cout<<valmax-cur+1<<endl;
        }
        swap(w[i],w[n]);
        swap(v[i],v[n]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}