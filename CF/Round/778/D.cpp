#include<vector>
#include<iostream>
#include<algorithm>
#include<tuple>
#include<numeric>
#include<map>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;
using MII=unordered_map<int,int>;
const int N=2e5+10,M=2e5+10,mod=998244353;
vector<TIII> adj[N];
MII up,dn,num;
LL rate[N];
bool st[M];
int primes[M],minp[M],idx;

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void init(int n) {
    st[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!st[i]) primes[idx++]=i,minp[i]=i;
        for(int j=0;primes[j]<=n/i;j++) {
            st[primes[j]*i]=true;
            minp[primes[j]*i]=primes[j];
            if(i%primes[j]==0) break;
        }
    }
}

inline void get(int val,MII &mp) {
    while(val>1) {
        int t=minp[val];
        auto it=mp.emplace(t,1).first;
        val/=t;
        while(val%t==0) {
            it->second++;
            val/=t;
        }
    }
}

inline void merge(MII &cur,bool type){
    MII *aim,*dif;
    if(type) aim=&up,dif=&dn;
    else aim=&dn,dif=&up;
    vector<int> del;
    for(auto &[a,b]:cur){
        auto it=(*dif).find(a);
        if(it!=(*dif).end()){
            if(b==it->second) del.push_back(a);
            else{
                int minn=min(b,it->second);
                b-=minn,it->second-=minn;
            }
        }
    }
    for(auto x:del) cur.erase(x),(*dif).erase(x);
    for(auto [a,b]:cur) {
        if(!b) continue;
        auto it=(*aim).find(a);
        if(it==(*aim).end()) it=(*aim).emplace(a,b).first;
        else it->second+=b;
        if(!type) {
            auto itt=num.find(a);
            if(itt==num.end()) num.emplace(a,b);
            else itt->second=max(itt->second,it->second);
        }
    }
}

inline void merge(MII tup,MII tdn){
    merge(tup,1),merge(tdn,0);
    if(up.empty()) up.emplace(1,1);
    if(dn.empty()) dn.emplace(1,1);
}

void dfs(int u,int fa){
    for(auto[v,a,b]:adj[u]){
        if(v==fa) continue;
        MII tup,tdn;
        get(b,tup),get(a,tdn);
        merge(tup,tdn);
        rate[v]=rate[u]*b%mod*qpow(a,mod-2)%mod;
        dfs(v,u);
        merge(tdn,tup);
    }
}

namespace io {
    const int MAXBUF = 1e6;
    char buf[MAXBUF], *pl, *pr;

    #define gc() \
    (pl == pr && (pr = (pl = buf) + fread(buf, 1, MAXBUF, stdin), pl == pr) \
    ? EOF : *pl++)

    template<typename T>
    inline T rd(T &x) {
        x = 0;
        T f = 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') f = -1;
            c = gc();
        }
        while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
        return x = x * f;
    }

    #define read(x) io::rd(x)
}

void solve(){
    int n=read(n);
    num.clear(),up.clear(),dn.clear();
    for(int i=1;i<=n;i++) adj[i].clear();
    up.emplace(1,1);
    dn.emplace(1,1);
    rate[1]=1;
    for(int i=1;i<n;i++){
        int x,y,a,b;
        read(x),read(y),read(a),read(b);
        int t=gcd(a,b);
        a/=t,b/=t;
        adj[x].emplace_back(y,a,b);
        adj[y].emplace_back(x,b,a);
    }
    dfs(1,-1);
    
    LL one=1,ans=0;
    for(auto [a,b]:num) one=(one*qpow(a,b))%mod;
    for(int i=1;i<=n;i++) ans=(ans+one*rate[i]%mod)%mod;
    printf("%lld\n",ans);
}

int main() {
    init(M-1);
    int t=read(t);
    while(t--) solve();
    return 0;
}