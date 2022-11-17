#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using ll=long long;
constexpr int mod=998244353;
constexpr int N=1e5+10;

int pre[N],inpre[N];

LL qpow(LL a,LL b) {
    LL res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
ll C(int n,int m)
{
    return 1ll*pre[n]*inpre[m]%mod*inpre[n-m]%mod;
}
void solve() {
    LL n,m;
    cin>>n>>m;
    cout<<pre[n]*C(n-1,m-1)%mod<<endl;
}

int main() {
    pre[0]=1;
    inpre[0]=1;
    for(int i=1;i<N;i++) pre[i]=1ll*pre[i-1]*i%mod,inpre[i]=qpow(pre[i], mod-2);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}