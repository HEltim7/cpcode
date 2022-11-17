#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;

template<typename I,typename L,I mod> struct Modint {
    I v;
    I pow(L b) const {
        L res=1,a=v;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }
    I inv() const { return pow(mod-2); }

    Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=L(1)*v*x.inv()%mod; return *this; }

    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }

    Modint operator++(int) { auto res=*this; *this+=1; return res; }
    Modint operator--(int) { auto res=*this; *this-=1; return res; }
    Modint operator-  () { return *this*-1; }
    Modint &operator++() { return *this+=1; }
    Modint &operator--() { return *this-=1; }

    bool operator< (const Modint&x) { return v< x.v; }
    bool operator> (const Modint&x) { return v> x.v; }
    bool operator<=(const Modint&x) { return v<=x.v; }
    bool operator>=(const Modint&x) { return v>=x.v; }
    bool operator==(const Modint&x) { return v==x.v; }
    bool operator!=(const Modint&x) { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
    static_assert(0ULL+mod+mod-2<1ULL<<(sizeof(I)*8-1), "Modint overflow");
    static_assert(1ULL*(mod-1)*(mod-1)<1ULL<<(sizeof(L)*8-1), "Modint overflow");
    
}; using Mint=Modint<int,long long,int(1e9+7)>;

Mint f[N][N],g[N][N],a[N],p[N],ans[N];
vector<int> adj[N];
int siz[N];

void dfs(int u,int fa) {
    siz[u]=1;
    g[u][1]=1;
    f[u][1]=a[u];
    for(int v:adj[u]) if(v!=fa) {
        dfs(v,u);
        for(int i=siz[u]+siz[v];i>=2;i--) {
            g[u][i]*=(1-p[v]);
            f[u][i]*=(1-p[v]);
            for(int j=max(1,i-siz[v]);j<=min(i-1,siz[u]);j++) {
                f[u][i]+=f[u][j]*g[v][i-j]*p[v];
                f[u][i]+=g[u][j]*f[v][i-j]*p[u];
                g[u][i]+=g[u][j]*g[v][i-j]*p[v];
            }
        }
        siz[u]+=siz[v];
        g[u][1]*=(1-p[v]);
        f[u][1]*=(1-p[v]);
    }
    for(int i=1;i<=siz[u];i++) ans[i]+=f[u][i]*(1-p[fa]);
}

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Mint sum;
    for(int i=1;i<=n;i++) {
        Mint b,c;
        cin>>a[i]>>b>>c;
        p[i]=b/c;
        sum+=a[i];
    }
    for(int i=1;i<=n;i++) a[i]=a[i]/sum;

    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}