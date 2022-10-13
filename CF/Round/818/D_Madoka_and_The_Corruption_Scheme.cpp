#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e5+10,mod=1e9+7;
LL faet[N],infaet[N];

LL qpow(LL a,LL b){
    LL  res=1;
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
    for(int i=2;i<N;i++){
        faet[i]=faet[i-1]*i%mod;
        infaet[i]=infaet[i-1]*qpow(i,mod-2)%mod;
    }
}

LL get(int a,int b){
    return faet[a]*infaet[a-b]%mod*infaet[b]%mod;
}

void solve() {
    int n,k;
    cin>>n>>k;
    k=min(k,n);
    n++,k++;
    LL ans=0;
    for(int i=1;i<=k;i++) {
        ans=(ans+get(n-1, i-1))%mod;
    }
    cout<<ans;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}