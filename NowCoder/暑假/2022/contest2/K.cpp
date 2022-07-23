#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=210,mod=1e9+7;
LL dp[N][N][N],f[N][N];
int n,m;
char s[N];
int pmt[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

void get_next() {
    for(int i=2,j=0;i<=n;i++) {
        while(j&&s[i]!=s[j+1]) j=pmt[j];
        if(s[i]==s[j+1]) j++;
        pmt[i]=j;
    }
}

int match(int k,char c) {
    while(k&&s[k+1]!=c) k=pmt[k];
    if(s[k+1]==c) k++;
    return k;
}

LL get_all(int len) {
    for(int i=1;i<=len;i++) memset(f[i], 0, sizeof (LL)*(len+1));
    f[0][0]=1;
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++) {
            f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%mod;
            if(j) f[i+1][j-1]=(f[i+1][j-1]+f[i][j])%mod;
        }
    return f[len][0];
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=0;i<=m;i++) 
        for(int j=0;j<=m;j++) 
            for(int k=0;k<=n;k++) 
                dp[i][j][k]=0;
    get_next();
    dp[0][0][0]=1;
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<n;k++) {
                if(dp[i][j][k]) {
                    int t=match(k, '(');
                    if(t<n) dp[i+1][j+1][t]=(dp[i+1][j+1][t]+dp[i][j][k])%mod;
                    t=match(k,')');
                    if(j&&t<n) dp[i+1][j-1][t]=(dp[i+1][j-1][t]+dp[i][j][k])%mod;
                }
            }
        }
    }
    LL ans=get_all(m);
    for(int i=0;i<n;i++) ans=(ans-dp[m][0][i]+mod)%mod;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}