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

namespace lpd {
    int id[N],ed[N],len[N],hch[N],dfn;
    vector<int> adj[N];

    void dfs1(int u,int fa) {
        for(int v:adj[u]) {
            if(v!=fa) {
                dfs1(v,u);
                if(len[hch[u]]<len[v]) hch[u]=v;
            }
        }
        len[u]=len[hch[u]]+1;
    }

    void dfs2(int u,int fa) {
        id[u]=++dfn;
        ed[u]=id[u]+len[u]-1;
        if(hch[u]) dfs2(hch[u],u);
        for(int v:adj[u]) if(v!=fa&&v!=hch[u]) dfs2(v,u);
    }

    void init() { dfs1(1,0),dfs2(1,0); }

    LL sum[N];
    int mn[N],mx[N],val[N];
    vector<tuple<int,int,int>> qry[N];
    vector<tuple<int,int,LL>> ans(N);
    void solve(int u,int fa) {
        mn[id[u]]=mx[id[u]]=sum[id[u]]=val[u];
        sgt.modify(id[u], {val[u],val[u],val[u]});
        if(hch[u]) solve(hch[u],u);
        for(int v:adj[u]) {
            if(v!=fa&&v!=hch[u]) {
                solve(v,u);
                for(int i=id[u]+1,j=id[v];j<=ed[v];i++,j++) {
                    mn[i]=min(mn[i],mn[j]);
                    mx[i]=max(mx[i],mx[j]);
                    sum[i]+=sum[j];
                    sgt.modify(i, {mn[i],mx[i],sum[i]});
                }
            }
        }
        for(auto [l,r,qid]:qry[u]) {
            auto [mn,mx,sum]=sgt.query(id[u]+l,id[u]+r);
            ans[qid]={mn,mx,sum};
        }
    }
}

void solve() {
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>lpd::val[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        lpd::adj[u].emplace_back(v);
        lpd::adj[v].emplace_back(u);
    }
    cin>>m;
    for(int i=1;i<=m;i++) {
        int x,l,r;
        cin>>x>>l>>r;
        lpd::qry[x].emplace_back(l,r,i);
    }
    sgt.build(1,n);
    lpd::init();
    lpd::solve(1, 0);
    for(int i=1;i<=m;i++) {
        auto [mn,mx,sum]=lpd::ans[i];
        cout<<mn<<' '<<mx<<' '<<sum<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}