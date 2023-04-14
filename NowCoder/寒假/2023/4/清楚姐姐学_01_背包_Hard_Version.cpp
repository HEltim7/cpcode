#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e3+10;
LL pre[N][N],suf[N][N];
int w[N],v[N];

template<typename T> LL get_dp(int n,int m,T dp) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            if(j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }
    }
    return dp[n][m];
}

LL erase_dp(int m,int idx) {
    LL res=0;
    const auto &p=pre[idx-1],&s=suf[idx+1];
    for(int i=0;i<=m;i++) res=max(res,p[i]+s[m-i]);
    return res;
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];

    reverse(w+1,w+1+n);
    reverse(v+1,v+1+n);
    get_dp(n, m, suf);
    reverse(suf+1,suf+1+n);

    reverse(w+1,w+1+n);
    reverse(v+1,v+1+n);
    get_dp(n, m, pre);

    LL valmax=pre[n][m];
    for(int i=1;i<=n;i++) {
        if(erase_dp(m, i)<valmax) cout<<0<<endl;
        else {
            LL cur=erase_dp(m-w[i], i)+v[i];
            cout<<valmax-cur+1<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}