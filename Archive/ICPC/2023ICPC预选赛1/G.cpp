#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

namespace fastio {
    constexpr int MAXBUF=1<<20;
    char buf[MAXBUF],*pl,*pr;
    #define gc()\
    (pl==pr&&(pr=(pl=buf)+fread(buf,1,MAXBUF,stdin),pl==pr)?EOF:*pl++)

    template<typename T> T rd(T &x) {
        x=0;
        T f=1;
        char c=gc();
        while(!isdigit(c)) {
            if(c=='-') f=-1;
            c=gc();
        }
        while(isdigit(c)) x=x*10+(c^48),c=gc();
        return x=x*f;
    }

    template<typename... T> auto read(T&... x) { return (rd(x),...); }
    #undef gc
    
    struct IO {
        template<typename T> friend IO&
        operator>>(IO &io,T& x) { rd(x);return io; }
    } static io;
}
using fastio::read,fastio::io;

const int mod=998244353;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1000006;
int rt[N],siz[N];
int n;
int depth[N];
int father[N];
vector<int> edg[N];
ll qmi(ll a,ll b,ll mod)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int find(int x)
{
    if(rt[x]!=x) rt[x]=find(rt[x]);

    return rt[x];
}
bool merge(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(siz[fx]>siz[fy])
        swap(fx,fy);
    if(fx!=fy)
    {
        // if(depth[fy]>depth[fx]) swap(fx,fy);
        //fx->fy
        siz[fy]+=siz[fx];
        rt[fx]=fy;
        if(depth[fy]>depth[fx]) {
            depth[fy]=depth[fx];
            father[fy]=father[fx];
        }
        return true;
    }
    return false;
}
void dfs(int u,int fa)
{
    father[u]=fa;
    for(auto v:edg[u])
    {
        if(v==fa) continue;
        depth[v]=depth[u]+1;
        dfs(v,u);
    }
}
int inv[N];
void init_inv(int n)
{
    inv[0]=inv[1]=1;
    for(int i=2;i<=n;i++)
    {
        inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    }
}
int main()
{
    init_inv(N-1);
    read(n);
    for(int i=1;i<=n;i++) rt[i]=i,siz[i]=1;

    vector<pii> path;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        read(x,y);
        path.push_back({x,y});
    }
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        read(x,y);
        edg[x].push_back(y);
        edg[y].push_back(x);
    }
    dfs(1,-1);
    // auto Inv=[&](ll x){
    //     return qmi(x,mod-2,mod);
    // };
    int res=1;
    for(auto [x,y]:path)
    {
        int fx=find(x);
        int fy=find(y);
        if(father[fx]!=-1&&find(father[fx])==find(fy)||father[fy]!=-1&&find(father[fy])==find(fx))
        {
            int ans=1ll*inv[siz[find(x)]]*inv[siz[find(y)]]%mod;
            merge(x,y);
            res=1ll*res*ans%mod;
        }
        else
        {
            puts("0");
            return 0;
        }
    }
    printf("%d\n",res);
}