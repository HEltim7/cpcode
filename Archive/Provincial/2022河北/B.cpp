#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

#define endl '\n'
using namespace std;
using LL=long long;
constexpr int N=1e9,M=1e9+10,P=1e6+10,mod=1e9+7;

LL pre[P];

void init() {
    for(LL i=1;i*i<=N;i++) {
        LL len=(i+1)*(i+1)-i*i;
        pre[i]=(2*len*i-i)%mod;
        pre[i]=(pre[i-1]+pre[i])%mod;
    }
}

void solve() {
    LL n;
    cin>>n;
    LL sq=sqrt(n);
    LL len=n-sq*sq+1;
    // cerr<<sq<<' '<<len<<endl;
    LL ans=(pre[sq-1]+2*len*sq%mod-min(len,sq)+mod)%mod;
    cout<<ans<<endl;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}