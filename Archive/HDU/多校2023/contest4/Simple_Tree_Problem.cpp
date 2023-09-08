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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
vector<pair<int,int>> adj[N];
int k[N],w[N],dn[N],up[N];

template<class Info,int size> struct SegmentTree {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int rng_l,rng_r;
    constexpr static int node_size=1<<__lg(size)<<2|1;
    array<Info, node_size> info;
    array<int, size+1> leaf;

    void pushup(int u) {
        info[u]=info[lch]+info[rch];
    }

    Info query(int u,int l,int r,int x,int y) {
        if(l>y||r<x) return {};
        if(l>=x&&r<=y) return info[u];
        int mid=(l+r)/2;
        return query(lch,l,mid,x,y)+query(rch,mid+1,r,x,y);
    }
    Info query(int l,int r) { return query(1,rng_l,rng_r,l,r); }

    void modify(int p,const Info &v) {
        int u=leaf[p];
        info[u]+=v;
        while(u>>=1) pushup(u);
    }

    template<class F>
    int find_first(int u,int l,int r,int x,int y,F check) {
        if(l>y||r<x||l>=x&&r<=y&&!check(info[u])) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        int res=find_first(lch,l,mid,x,y,check);
        if(res==-1) res=find_first(rch,mid+1,r,x,y,check);
        return res;
    }
    template<class F> int find_first(int l,int r,F check) {
        return find_first(1,rng_l,rng_r,l,r,check);
    }

    template<class F>
    int find_last(int u,int l,int r,int x,int y,F check) {
        if(l>y||r<x||l>=x&&r<=y&&!check(info[u])) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        int res=find_last(rch,mid+1,r,x,y,check);
        if(res==-1) res=find_last(lch,l,mid,x,y,check);
        return res;
    }
    template<class F> int find_last(int l,int r,F check) {
        return find_last(1,rng_l,rng_r,l,r,check);
    }

    void build(int u,int l,int r) {
        info[u].init(l,r);
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
            pushup(u);
        }
        else leaf[l]=u;
    }
    void build(int l=1,int r=size) { build(1,rng_l=l,rng_r=r); }

    #undef lch
    #undef rch
};

struct Info {
    int maxx=0;

    void init(int l,int r) {
        if(l!=r) return;
        maxx=0;
    }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.maxx=max(l.maxx,r.maxx);
        return res;
    }

    Info &operator+=(const Info &v) {
        maxx+=v.maxx;
        return *this;
    }
};

SegmentTree<Info, N> dns,ups;

int sgt_mx;
namespace dsu {
    int id[N],ed[N],ori[N],sz[N],hch[N],hkid[N],idx;

    void init(int u,int fa) {
        sz[u]=1;
        id[u]=++idx;
        ori[id[u]]=u;
        for(auto [v,kid]:adj[u]) {
            if(v!=fa) {
                init(v,u);
                if(sz[v]>sz[hch[u]]) hch[u]=v,hkid[u]=kid;
                sz[u]+=sz[v];
            }
        }
        ed[u]=idx;
    }

    void solve(int u,int fa,bool keep,int kid) {
        auto add=[](int id) {
            int x=ori[id];
            dns.modify(w[x], Info{1});
            ups.modify(w[x], Info{-1});
        };

        auto del=[](int id) {
            int x=ori[id];
            dns.modify(w[x], Info{-1});
            ups.modify(w[x], Info{1});
        };
        
        for(auto [v,kid]:adj[u]) if(v!=fa&&v!=hch[u]) solve(v,u,0,kid);
        if(hch[u]) solve(hch[u],u,1,hkid[u]);
        for(auto [v,_]:adj[u]) 
            if(v!=fa&&v!=hch[u]) 
                for(int i=id[v];i<=ed[v];i++) add(i);
        add(id[u]);
        
        auto check=[&](Info x) {
            return x.maxx>=k[kid];
        };
        
        dn[kid]=dns.find_last(0,sgt_mx,check);
        up[kid]=ups.find_last(0,sgt_mx,check);

        if(!keep) for(int i=id[u];i<=ed[u];i++) del(i);
    }

    void clear(int n=N-1) {
        idx=0;
        fill(hch,hch+n+1,0);
        for(int i=0;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n;
    cin>>n;
    dsu::clear(n);
    vector<int> num;
    for(int i=1;i<=n;i++) cin>>w[i],num.emplace_back(w[i]);
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v>>k[i];
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
    }
    if(n==1) return;

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        w[i]=lower_bound(num.begin(),num.end(),w[i])-num.begin();
    
    sgt_mx=num.size()-1;
    vector<int> cnt(sgt_mx+1);
    for(int i=1;i<=n;i++) cnt[w[i]]++;
    dns.build(0,sgt_mx);
    ups.build(0,sgt_mx);
    for(int i=0;i<=sgt_mx;i++) if(cnt[i]) ups.modify(i, Info{cnt[i]});

    dsu::init(1, 0);
    dsu::solve(1, 0, 1, 0);
    for(int i=1;i<n;i++) {
        int x=dn[i]==-1?0:num[dn[i]];
        int y=up[i]==-1?0:num[up[i]];
        cout<<max(x,y)<<endl;
    }
}

int main() {
    int size(512<<20); // 512M
    // __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    // ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    // exit(0);
    return 0;
}