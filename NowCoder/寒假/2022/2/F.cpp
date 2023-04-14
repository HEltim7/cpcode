#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=1e6+10,mod=1e9+7;

int id[N],n,q;
LL sum[N],num[N],ans;

LL qpow(LL a,LL b){
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
    cin>>n>>q;
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>num[i];
    int idx=0;
    for(int i=1;i<s.size();i++){
        if(s[i]=='*'){
            int j;
            sum[++idx]=1;
            for(j=i;j<s.size();j++){
                id[j]=idx,sum[idx]=sum[idx]*num[j]%mod;
                if(s[j+1]!='*') break;
            }
            id[j+1]=idx,sum[idx]=sum[idx]*num[j+1]%mod;
            i=j;
        }
    }
    for(int i=1;i<=n;i++) if(id[i]==0) ans=(ans+num[i])%mod;
    for(int i=1;i<=idx;i++) ans=(ans+sum[i])%mod;

    while(q--){
        LL x,y;
        cin>>x>>y;
        int pid=id[x];
        if(pid){
            LL bak=sum[pid];
            sum[pid]=sum[pid]*qpow(num[x],mod-2)%mod;
            sum[pid]=sum[pid]*y%mod;
            ans=(ans+(sum[pid]-bak+mod)%mod)%mod;
        }
        else ans=(ans+(y-num[x]+mod)%mod)%mod;
        num[x]=y;
        cout<<ans<<endl;
    }
    return 0;
}