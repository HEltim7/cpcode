#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int mod=998244353;

const int N=1e3+10;
LL faet[N],infaet[N];

inline LL qpow(LL a,LL b){
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    init();
    while(t--){
        int n;
        cin>>n;
        if(n&1){
            cout<<0<<endl;
            continue;
        }
        LL ans=faet[n/2]*faet[n/2]%mod;
        cout<<ans<<endl;
    }
    return 0;
}