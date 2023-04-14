#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
vector<pair<int,int>> adj[N];
int w[N],to[N],id[N],ed[N],idx;
LL dis[N];

namespace hpd {
    using PII=pair<int,int>;
    constexpr int N=2e5+10;
    int id[N],w[N],nw[N],cnt;
    int dep[N],sz[N],top[N],p[N],hch[N];

    void dfs1(int u,int fa,int d) {
        dep[u]=d,p[u]=fa,sz[u]=1;
        for(auto [v,_]:adj[u]) {
            if(v==fa) continue;
            dfs1(v,u,d+1);
            sz[u]+=sz[v];
            if(sz[hch[u]]<sz[v]) hch[u]=v;
        }
    }

    void dfs2(int u,int t) {
        id[u]=++cnt,nw[cnt]=w[u],top[u]=t;
        if(!hch[u]) return;
        dfs2(hch[u],t);
        for(auto [v,_]:adj[u])
            if(v!=p[u]&&v!=hch[u]) dfs2(v,v);
    }

    void init() {
        // cnt,hch -> 0
        dfs1(1,-1,1); dfs2(1,1);
    }

    int lca(int x,int y) {
        while(top[x]!=top[y]) {
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            x=p[top[x]];
        }
        if(dep[x]<dep[y]) swap(x,y);
        return y;
    }

    vector<PII> decompose(int x,int y) {
        vector<PII> res;
        while(top[x]!=top[y]) {
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            res.emplace_back(id[top[x]],id[x]);
            x=p[top[x]];
        }
        if(dep[x]<dep[y]) swap(x,y);
        res.emplace_back(id[y],id[x]);
        return res;
    }

    PII decompose(int x) {
        return { id[x],id[x]+sz[x]-1 };
    }
}

template<typename T=int> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim+=val; }

    void add(int pos,T val) {
        pos++;
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        pos++;
        T res{};
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int size):size(size) { tr.resize(size+1); }
};
Fenwick<LL> tr(N);

void init(int u,int fa) {
    id[u]=++idx;
    for(auto [v,i]:adj[u]) {
        if(v!=fa) {
            to[i]=v;
            dis[idx+1]=dis[id[u]]+w[i];
            init(v,u);
        }
    }
    ed[u]=idx;
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v>>w[i];
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
    }
    init(1,0);
    hpd::init();
    for(int i=n;i>=1;i--) dis[i]-=dis[i-1],tr.add(i,dis[i]);

    int q;
    cin>>q;
    while(q--) {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1) {
            int z=y-w[x];
            tr.add(id[to[x]],z);
            tr.add(ed[to[x]]+1,-z);
            w[x]=y;
        }
        else {
            cout<<tr.query(id[x])+tr.query(id[y])-2*tr.query(id[hpd::lca(x,y)])<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}