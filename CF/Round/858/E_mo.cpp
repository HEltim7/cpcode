#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

namespace mo {
    constexpr int N=1e5+10,Q=1e5+10,block=630;
    using Query=tuple<int,int,int,int>;
    vector<Query> query;
    vector<int> adj[N];
    int eid[N<<1],first[N],last[N],idx;
    bool odd[N];
    int w[N],cnt[N];
    LL prod[N],ans[Q],chain[N];
    
    namespace hpd {
        int dep[N],sz[N],top[N],p[N],hch[N];
    
        void dfs1(int u,int fa,int d) {
            dep[u]=d,p[u]=fa,sz[u]=1;
            for(int v:adj[u]) {
                if(v==fa) continue;
                dfs1(v,u,d+1);
                sz[u]+=sz[v];
                if(sz[hch[u]]<sz[v]) hch[u]=v;
            }
        }
    
        void dfs2(int u,int t) {
            top[u]=t;
            if(!hch[u]) return;
            dfs2(hch[u],t);
            for(int v:adj[u])
                if(v!=p[u]&&v!=hch[u]) dfs2(v,v);
        }
    
        int lca(int x,int y) {
            while(top[x]!=top[y]) {
                if(dep[top[x]]<dep[top[y]]) swap(x,y);
                x=p[top[x]];
            }
            if(dep[x]<dep[y]) swap(x,y);
            return y;
        }
    
        void init() {
            dfs1(1,-1,1); dfs2(1,1);
        }

        void clear(int n) {
            fill(hch, hch+n+1, 0);
        }
    }

    void dfs(int u,int fa) {
        chain[u]=chain[fa]+1LL*w[u]*w[u];
        eid[++idx]=u;
        first[u]=idx;
        for(int v:adj[u]) if(v!=fa) dfs(v,u);
        eid[++idx]=u;
        last[u]=idx;
    }

    void add_query(int u,int v,int id) {
        if(first[u]>first[v]) swap(u,v);
        int p=hpd::lca(u,v);
        int l,r,pidx;
        if(u==p) l=first[u],r=first[v],pidx=0;
        else l=last[u],r=first[v],pidx=first[p];
        query.emplace_back(l,r,pidx,id);
    }

    void solve() {
        auto getid=[](int x) {
            return x/block;
        };

        sort(query.begin(),query.end(),[&](const Query &x,const Query &y) {
            const auto &[l,r,_,__]=x;
            const auto &[L,R,___,____]=y;
            if(getid(l)!=getid(L)) return getid(l)<getid(L);
            return r<R;
        });

        LL res=0;
        auto _add=[&](int u) {
            int d=hpd::dep[u];
            prod[d]*=w[u];
            cnt[d]++;
            if(cnt[d]==2) res+=prod[d];
            else if(cnt[d]==3) res-=prod[d];
        };

        auto _del=[&](int u) {
            int d=hpd::dep[u];
            if(cnt[d]==3) res+=prod[d];
            else if(cnt[d]==2) res-=prod[d];
            prod[d]/=w[u];
            cnt[d]--;
        };

        auto extend=[&](int idx) {
            int u=eid[idx];
            if(odd[u]^=1) _add(u);
            else _del(u);
        };

        int l=1,r=0;
        for(auto [L,R,pidx,id]:query) {
            while(l<L) extend(l++);
            while(l>L) extend(--l);
            while(r<R) extend(++r);
            while(r>R) extend(r--);
            if(pidx) extend(pidx);
            if(l!=r) ans[id]=res+chain[eid[pidx]];
            else ans[id]=chain[eid[l]];
            if(pidx) extend(pidx);
        }
    }

    void init() {
        hpd::init();
        dfs(1,0);
    }

    void clear(int n) {
        idx=0;
        query.clear();
        fill(odd, odd+n+1, 0);
        for(int i=0;i<=n;i++) adj[i].clear();
        hpd::clear(n);
    }
}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>mo::w[i];
    for(int i=2;i<=n;i++) {
        int p;
        cin>>p;
        mo::adj[p].push_back(i);
    }
    mo::init();
    for(int i=1;i<=q;i++) {
        int u,v;
        cin>>u>>v;
        mo::add_query(u, v, i);
    }
    for(int i=1;i<=n;i++) mo::prod[i]=1;
    mo::solve();
    for(int i=1;i<=q;i++) cout<<mo::ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}