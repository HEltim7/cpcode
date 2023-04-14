#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e3+10,mod=1e9+7;
LL dp[N][N],p[N],fp[N];

LL qpow(LL a,LL b) {
    LL res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void solve() {
    LL ans=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>p[i];
        fp[i]=(100-p[i])*qpow(100,mod-2)%mod;
        p[i]=p[i]*qpow(100,mod-2)%mod;
    }
    fp[n+1]=dp[0][0]=1;
    for(int i=1;i<=n+1;i++)
        for(int j=0;j<i;j++) {
            dp[i][j+1]=(dp[i][j+1]+dp[i-1][j]*p[i]%mod)%mod;
            dp[i][0]=(dp[i][0]+dp[i-1][j]*fp[i]%mod)%mod;
            ans=(ans+dp[i-1][j]*fp[i]%mod*qpow(j,m)%mod)%mod;
        }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}