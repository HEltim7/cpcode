#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int mod=1e9+7;

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
    LL n,m;
    cin>>n>>m;
    LL sum=0,pre=0,suf=0;
    for(int i=1;i<=n;i++) {
        LL in;
        cin>>in;
        sum+=in;
        pre+=in*(n-i+1);
        suf+=in*i;
    }
    sum%=mod,pre%=mod,suf%=mod;
    LL cnt=qpow(2,m);
    LL tot=(cnt*(cnt-1)/2)%mod;
    LL ans=(tot*n%mod)*sum%mod;
    // cerr<<cnt<<' '<<tot<<' '<<sum<<' '<<ans<<endl;

    ans=max(
        (ans+pre*cnt)%mod,
        (ans+pre*cnt%mod*qpow(2,mod-2)+suf*cnt%mod*qpow(2,mod-2))%mod
    );
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}