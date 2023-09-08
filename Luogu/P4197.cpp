#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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

namespace sgt {
    #define lch (tr[u].lc)
    #define rch (tr[u].rc)
    
    struct Node {
        int lc=0,rc=0;
        int cnt=0;
    };
    constexpr int M=N*__lg(N)*2;
    vector<Node> tr(M);
    int idx;

    int new_node() {
        assert(++idx<M);
        tr[idx]={};
        return idx;
    }

    void pushup(int u) {
        tr[u].cnt=tr[lch].cnt+tr[rch].cnt;
    }

    void pushdn(int u) {
        
    }
    
    void merge(int &u,int v,int l,int r) {
        if(!u||!v) u=u|v;
        else if(l==r) tr[u].cnt+=tr[v].cnt;
        else {
            pushdn(u),pushdn(v);
            int mid=(l+r)/2;
            merge(tr[u].lc, tr[v].lc, l, mid);
            merge(tr[u].rc, tr[v].rc, mid+1, r);
            pushup(u);
        }
    }

    int kth(int u,int l,int r,int k) {
        if(tr[u].cnt<k) return -1;
        if(l==r) return l;
        pushdn(u);
        int mid=(l+r)/2;
        if(tr[lch].cnt>=k) return kth(lch, l, mid, k);
        return kth(rch, mid+1, r, k-tr[lch].cnt);
    }

    void build(int &u,int l,int r,int p) {
        if(!u) u=new_node();
        if(l==r) tr[u].cnt++;
        else {
            pushdn(u);
            int mid=(l+r)/2;
            if(p<=mid) build(lch,l,mid,p);
            else build(rch,mid+1,r,p);
            pushup(u);
        }
    }

    #undef lch
    #undef rch
};

struct DisjointUnionSet {
    vector<int> fa,sz,rt;

    void init(int n) {
        fa.resize(n+1);
        sz.assign(n+1,1);
        rt.resize(n+1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }

    bool same(int x,int y) {
        return find(x)==find(y);
    }

    bool join(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        sz[x]+=sz[y];
        fa[y]=x;
        sgt::merge(rt[x], rt[y], 0, N);
        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }

    int root(int x) {
        return rt[find(x)];
    }

    DisjointUnionSet() = default;
    DisjointUnionSet(int n) { init(n); }
} dsu;

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> h(n+1),num;
    for(int i=1;i<=n;i++) cin>>h[i],num.emplace_back(h[i]);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) {
        h[i]=lower_bound(num.begin(),num.end(),h[i])-num.begin();
    }

    vector<int> ans(q);
    vector<tuple<int,int,int>> edg(m);
    vector<tuple<int,int,int,int>> qry(q);
    for(auto &[c,a,b]:edg) cin>>a>>b>>c;
    for(int i=0;i<q;i++) {
        auto &[x,v,k,id]=qry[i];
        cin>>v>>x>>k;
        id=i;
    }
    sort(edg.begin(),edg.end());
    sort(qry.begin(),qry.end());

    DisjointUnionSet dsu(n);
    for(int i=1;i<=n;i++) {
        sgt::build(dsu.rt[i], 0, N, h[i]);
    }

    int idx=0;
    for(auto [x,v,k,id]:qry) {
        while(idx<m) {
            auto [c,a,b]=edg[idx];
            if(c>x) break;
            dsu.join(a, b);
            idx++;
        }
        if(k<=0||k>dsu.size(v)) ans[id]=-1;
        else {
            k=dsu.size(v)-k+1;
            int rt=dsu.root(v);
            ans[id]=num[sgt::kth(rt, 0, N, k)];
        }
    }

    for(int x:ans) cout<<x<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}