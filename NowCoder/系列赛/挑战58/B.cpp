#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const LL mod=1e9+7;
const LL N=1e6+10;
LL faet[N],infaet[N];

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void init(){
    faet[1]=1,faet[0]=1;
    infaet[1]=1,infaet[0]=1;
    for(int i=2;i<=1e6;i++){
        faet[i]=faet[i-1]*i%mod;
        infaet[i]=infaet[i-1]*qpow(i,mod-2)%mod;
    }
}

inline LL get(LL a,LL b){
    return faet[a]*infaet[a-b]%mod*infaet[b]%mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    LL n,m;
    cin>>n>>m;
    const LL A=(qpow(2,n)-1+mod)%mod;
    const LL B=qpow(2,(n-1)*m);
    const LL C=(qpow(2,m)-1+mod)%mod;
    LL ans=0;
    for(LL i=0;i<=m;i++){
        LL val=0;
        if(i==0) val=1;
        else val=(get(m-1,(i-1))*C%mod+get(m,i))%mod;
        LL res=qpow(A,i)*val%mod;
        ans=(ans+res)%mod;
    }
    cout<<ans*B%mod;
    return 0;
}