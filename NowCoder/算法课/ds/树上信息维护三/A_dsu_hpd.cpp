#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

template<class Info,int size> struct SegmentTree {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int L,R;
    constexpr static int node_size=4<<__lg(size)|1;
    array<Info, node_size> info;
    array<int, size+1> leaf;

    void pushup(int u) {
        info[u]=info[lch]+info[rch];
    }

    Info query(int u,int l,int r,int x,int y) {
        if(l>y||r<x) return {};
        if(l>=x&&r<=y) return info[u];
        int m=(l+r)/2;
        return query(lch,l,m,x,y)+query(rch,m+1,r,x,y);
    }
    Info query(int l,int r) { return query(1,L,R,l,r); }

    void modify(int p,const Info &v) {
        int u=leaf[p];
        info[u].update(v);
        while(u>>=1) pushup(u);
    }

    void build(int u,int l,int r) {
        info[u].init(l,r);
        if(l!=r) {
            int m=(l+r)/2;
            build(lch,l,m);
            build(rch,m+1,r);
            pushup(u);
        }
        else leaf[l]=u;
    }
    void build(int l=1,int r=size) { build(1,L=l,R=r); }

    #undef lch
    #undef rch
};

struct Info {
    int mn=1e9,mx=0;
    LL sum=0;

    void init(int l,int r) {
        if(l!=r) return;
        mx=1e9,mx=0,sum=0;
    }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.mn=min(l.mn,r.mn);
        res.mx=max(l.mx,r.mx);
        res.sum=l.sum+r.sum;
        return res;
    }

    void update(const Info &v) {
        *this=v;
    }
};

SegmentTree<Info, N> sgt;

namespace dsu {
    int id[N],ed[N],ori[N],sz[N],hch[N],idx;
    int val[N],dep[N],cnt[N],sidx[N];
    vector<int> adj[N];

    void init(int u,int fa) {
        sz[u]=1;
        id[u]=++idx;
        ori[id[u]]=u;
        dep[u]=dep[fa]+1;
        for(int v:adj[u]) {
            if(v!=fa) {
                init(v,u);
                if(sz[v]>sz[hch[u]]) hch[u]=v;
                sz[u]+=sz[v];
            }
        }
        ed[u]=idx;
    }

    void reindex(int n) {
        vector<int> off(n+1);
        for(int i=1;i<=n;i++) cnt[dep[i]]++;
        for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
        for(int i=1;i<=n;i++) sidx[i]=cnt[dep[i]-1]+1+(off[dep[i]]++);
    }

    tuple<int,int,LL> ans[N];
    vector<tuple<int,int,int>> qry[N];
    void solve(int u,int fa,bool keep) {
        auto add=[](int id) {
            int x=ori[id];
            sgt.modify(sidx[x], {val[x],val[x],val[x]});
        };

        auto del=[](int id) {
            int x=ori[id];
            sgt.modify(sidx[x], {});
        };
        
        for(int v:adj[u]) if(v!=fa&&v!=hch[u]) solve(v,u,0);
        if(hch[u]) solve(hch[u],u,1);
        for(int v:adj[u]) 
            if(v!=fa&&v!=hch[u]) 
                for(int i=id[v];i<=ed[v];i++) add(i);
        add(id[u]);
        
        for(auto [l,r,id]:qry[u]) {
            l+=dep[u],r+=dep[u];
            l=cnt[l-1]+1,r=cnt[r];
            auto [mn,mx,sum]=sgt.query(l,r);
            ans[id]={mn,mx,sum};
        }

        if(!keep) for(int i=id[u];i<=ed[u];i++) del(i);
    }

    void clear(int n=N-1) {
        idx=0;
        fill(hch,hch+n+1,0);
        for(int i=0;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>dsu::val[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        dsu::adj[u].emplace_back(v);
        dsu::adj[v].emplace_back(u);
    }
    cin>>m;
    for(int i=1;i<=m;i++) {
        int x,l,r;
        cin>>x>>l>>r;
        dsu::qry[x].emplace_back(l,r,i);
    }
    sgt.build(1,n);
    dsu::init(1, 0);
    dsu::reindex(n);
    dsu::solve(1, 0, 1);
    for(int i=1;i<=m;i++) {
        auto [mn,mx,sum]=dsu::ans[i];
        cout<<mn<<' '<<mx<<' '<<sum<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}