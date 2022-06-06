#include<iostream>
#include<numeric>
using namespace std;

#define endl '\n'
const int mod=1e9+7;
typedef long long LL;

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        LL n,m;
        cin>>n>>m;
        LL b=m*(qpow(2,n)-2+mod)%mod;
        LL a=qpow(2,n);
        LL tmp=gcd(a,b);
        b/=tmp,a/=tmp;
        if(a==1) cout<<b%mod<<endl;
        else cout<<b*qpow(a,mod-2)%mod<<endl;
    }
    return 0;
}