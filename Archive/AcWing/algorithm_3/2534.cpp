#pragma GCC optimize("O2")
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

namespace mo {
    constexpr int N=4e4+10,M=1e5+10,len=320;
    using Query=tuple<int,int,int,int>;
    vector<Query> query;
    vector<int> adj[N];
    int eid[N<<2],first[N],last[N],idx;
    bool odd[N];
    int w[N],cnt[N],ans[M];
    
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
            // cnt,hch -> 0
            dfs1(1,-1,1); dfs2(1,1);
        }
    }

    void dfs(int u,int fa) {
        eid[++idx]=u;
        first[u]=idx;
        for(int v:adj[u]) if(v!=fa) dfs(v,u);
        eid[++idx]=u;
        last[u]=idx;
    }

    void add_query(int u,int v,int id) {
        if(first[u]>first[v]) swap(u,v);
        int p=hpd::lca(u,v);
        int l,r,ex;
        if(u==p) l=first[u],r=first[v],ex=0;
        else l=last[u],r=first[v],ex=first[p];
        query.emplace_back(l,r,ex,id);
    }

    void solve() {
        auto getid=[](int x) {
            return x/len;
        };

        sort(query.begin(),query.end(),[&](const Query &x,const Query &y) {
            const auto &[l,r,_,__]=x;
            const auto &[L,R,___,____]=y;
            if(getid(l)!=getid(L)) return getid(l)<getid(L);
            return getid(l)&1?r<R:r>R;
        });

        int res=0;

        auto _add=[&](int u) {
            if(++cnt[w[u]]==1) res++;
        };

        auto _del=[&](int u) {
            if(--cnt[w[u]]==0) res--;
        };

        auto extend=[&](int idx) {
            int u=eid[idx];
            if(odd[u]^=1) _add(u);
            else _del(u);
        };

        int l=1,r=0;
        for(auto [L,R,ex,id]:query) {
            while(l>L) extend(--l);
            while(r<R) extend(++r);
            while(l<L) extend(l++);
            while(r>R) extend(r--);
            if(ex) extend(ex);
            ans[id]=res;
            if(ex) extend(ex);
        }
    }

    void init() {
        hpd::init();
        dfs(1,-1);
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> num;
    for(int i=1;i<=n;i++) cin>>mo::w[i],num.push_back(mo::w[i]);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        mo::w[i]=lower_bound(num.begin(),num.end(),mo::w[i])-num.begin()+1;
    
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        mo::adj[u].push_back(v);
        mo::adj[v].push_back(u);
    }

    mo::init();
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        mo::add_query(u, v, i);
    }
    mo::solve();
    for(int i=1;i<=m;i++) cout<<mo::ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}