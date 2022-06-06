#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int mod=998244353,N=1e7+10;
LL faet[N],infaet[N],num[N];
LL sum,one,two,tot;

LL qpow(LL a,LL b){
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
    for(int i=2;i<=1e5;i++){
        faet[i]=faet[i-1]*i%mod;
        infaet[i]=infaet[i-1]*qpow(i,mod-2)%mod;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(num[i]==2) two++;
        else if(num[i]==1) one++;
        sum+=num[i];
        tot+=num[i];
    }
    if(k==1){
        cout<<sum<<endl;
        return 0;
    }
    else if(k==2){
        LL ans=qpow(sum,2);
        tot=(tot+two*2%mod)%mod;
        ans=(ans-tot+mod)%mod;
        ans=ans*qpow(2,mod-2)%mod;
        cout<<ans<<endl;
        return 0;
    }
    LL res=0;
    LL ssum=qpow(sum,k-2);
    LL cmb;
    LL cnt=4;
    LL ans=0;
    tot=(tot+two*2%mod)%mod;
    for(int i=k-2;i>=1;i--){
        cmb=faet[k]*infaet[i]%mod*infaet[k-i]%mod;
        res=(res+cmb*ssum%mod*tot%mod)%mod;
        tot=(tot+two*cnt%mod)%mod;
        cnt=cnt*2%mod;   
        ssum=ssum*qpow(sum,mod-2)%mod;
    }
    LL tmp=(qpow(2,k)-3-k+mod)%mod;
    ans=((qpow(sum,k)-res+mod)%mod+tmp*tot%mod)%mod;
    cout<<ans*infaet[k]%mod;
    return 0;
}