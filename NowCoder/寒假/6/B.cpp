#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;

const int mod=998244353,N=1e5+10,INF=0x3f3f3f3f;
int a[N],cnt[N];

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

bool inline check(int x){
    if(a[x-1]==INF||a[x+1]==INF) return 1;
    return a[x]>a[x-1]&&a[x]>a[x+1]||
            a[x]<a[x-1]&&a[x]<a[x+1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(cnt,0,sizeof (int)*(n+1));
        for(int i=1;i<=n;i++) cin>>a[i];
        int end=0;
        for(int i=1;i<=n;i++)
            if(a[i]==a[end]) cnt[end]++;
            else a[++end]=a[i],cnt[end]=1;
        a[0]=a[end+1]=INF;
        LL ans=1;
        int req=0;
        for(int i=1;i<=end;i++)
            if(check(i)){
                req+=cnt[i];
                ans=(ans*(qpow(2,cnt[i])-1+mod)%mod)%mod;
            }
        ans=(ans*qpow(2,n-req))%mod;
        cout<<ans<<endl;
    }
    return 0;
}
//////////////////////