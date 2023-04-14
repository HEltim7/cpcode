#include <map>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using ULL=unsigned long long;
constexpr int N=1e5+10;
vector<int> adj[N];

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

    Modint operator++(int) { auto res=*this; ++*this; return res; }
    Modint operator--(int) { auto res=*this; --*this; return res; }
    Modint &operator++() { v=v==mod-1?0:v+1; return *this; }
    Modint &operator--() { v=v?v-1:mod-1; return *this; }
    Modint operator-() { v=mod-v; return *this; }

    bool operator< (const Modint &x) const { return v< x.v; }
    bool operator> (const Modint &x) const { return v> x.v; }
    bool operator<=(const Modint &x) const { return v<=x.v; }
    bool operator>=(const Modint &x) const { return v>=x.v; }
    bool operator==(const Modint &x) const { return v==x.v; }
    bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    constexpr Modint(L x=0): v((x=abs(x)>=mod?x%mod:x)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,998244353>;

struct Hasher {
    ULL rnd;

    ULL operator()(ULL x) {
        x^=rnd;
        x^=x<<13;
        x^=x>>7;
        x^=x<<13;
        x^=rnd;
        return x;
    }

    Hasher() {
        mt19937 gen(random_device{}());
        rnd=gen();
    }
} hs;

int sz[N],centroid[2];
void get_centroid(int u,int fa,int tot) {
    int maxx=0;
    sz[u]=1;
    for(int v:adj[u]) {
        if(v!=fa) {
            get_centroid(v,u,tot);
            sz[u]+=sz[v];
            maxx=max(maxx,sz[v]);
        }
    }
    maxx=max(maxx,tot-sz[u]);
    if(maxx<=tot/2) centroid[centroid[0]!=0]=u;
}

pair<ULL,Mint> dfs(int u,int fa) {
    ULL hsh=1;
    Mint res=1;
    map<ULL,pair<Mint,int>> mp;
    for(int v:adj[u]) {
        if(v!=fa) {
            auto [hshv,resv]=dfs(v,u);
            auto &[tot,cnt]=mp[hshv];
            if(!cnt) tot=resv,cnt=1;
            else tot*=resv,cnt++;
            hsh+=hs(hshv);
        }
    }
    for(auto [_,x]:mp) {
        auto [tot,cnt]=x;
        res*=tot;
        for(int i=1;i<=cnt;i++) res*=i;
    }
    return {hsh,res};
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    get_centroid(1, -1, n);
    if(centroid[1]) {
        adj[0].push_back(centroid[0]);
        adj[0].push_back(centroid[1]);
        auto [x,y]=centroid;
        adj[x].erase(find(adj[x].begin(),adj[x].end(),y));
        adj[y].erase(find(adj[y].begin(),adj[y].end(),x));
        adj[x].push_back(0);
        adj[y].push_back(0);
        cout<<dfs(0,-1).second;
    }
    else cout<<dfs(centroid[0],-1).second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}