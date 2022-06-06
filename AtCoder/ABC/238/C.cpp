#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
typedef unsigned long long ULL;
int mod=998244353;

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

inline LL get(LL a,LL b){
    return ((((a+b)%mod)*((b-a+1)%mod))%mod*qpow(2,mod-2))%mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL n;
    cin>>n;
    LL cnt=0,ans=0;
    while(cnt<n){
        ULL tmp=cnt*10+9;
        if(tmp<=n) ans=(ans+get(1,tmp-cnt))%mod;
        else{
            ans=(ans+get(1,n-cnt))%mod;
            break;
        }
        cnt=tmp;
    }
    cout<<ans;
    return 0;
}