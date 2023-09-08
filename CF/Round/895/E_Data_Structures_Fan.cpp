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

template<class Info,class Tag,int size> struct SegmentTree {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int rng_l,rng_r;
    constexpr static int node_size=1<<__lg(size)<<2|1;
    array<Tag, node_size> tag;
    array<Info, node_size> info;
    array<bool, node_size> clean;

    void pushup(int u) {
        info[u]=info[lch]+info[rch];
    }

    void update(int u, const Tag &t) {
        info[u]+=t;
        tag[u]+=t;
        clean[u]=0;
    }

    void pushdn(int u) {
        if(clean[u]) return;
        update(lch, tag[u]);
        update(rch, tag[u]);
        clean[u]=1;
        tag[u].clear();
    }

    Info query(int u,int l,int r,int x,int y) {
        if(l>y||r<x) return {};
        if(l>=x&&r<=y) return info[u];
        pushdn(u);
        int mid=(l+r)/2;
        return query(lch,l,mid,x,y)+query(rch,mid+1,r,x,y);
    }
    Info query(int l,int r) { return query(1,rng_l,rng_r,l,r); }

    void modify(int u,int l,int r,int x,int y,const Tag &t) {
        if(l>y||r<x) return;
        if(l>=x&&r<=y) update(u, t);
        else {
            pushdn(u);
            int mid=(l+r)/2;
            if(mid>=x) modify(lch,l,mid,x,y,t);
            if(mid<y) modify(rch,mid+1,r,x,y,t);
            pushup(u);
        }
    }
    void modify(int l,int r,const Tag &t) { modify(1,rng_l,rng_r,l,r,t); }

    template<class F>
    int find_first(int u,int l,int r,int x,int y,F check) {
        if(l>y||r<x||l>=x&&r<=y&&!check(info[u])) return -1;
        if(l==r) return l;
        pushdn(u);
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
        pushdn(u);
        int mid=(l+r)/2;
        int res=find_last(rch,mid+1,r,x,y,check);
        if(res==-1) res=find_last(lch,l,mid,x,y,check);
        return res;
    }
    template<class F> int find_last(int l,int r,F check) {
        return find_last(1,rng_l,rng_r,l,r,check);
    }

    void build(int u,int l,int r) {
        clean[u]=1;
        info[u].init(l,r);
        tag[u].clear();
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
            pushup(u);
        }
    }
    void build(int l=1,int r=size) { build(1,rng_l=l,rng_r=r); }

    #undef lch
    #undef rch
};

struct Tag {
    bool flip=false;
    void clear() {
        flip=false;
    }

    Tag &operator+=(const Tag &t) {
        flip^=t.flip;
        return *this;
    }
};

int a[N];
struct Info {
    LL sum0=0,sum1=0;

    void init(int l,int r) {
        if(l!=r) return;
        sum0=a[l];
        sum1=0;
    }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.sum0=l.sum0^r.sum0;
        res.sum1=l.sum1^r.sum1;
        return res;
    }

    Info &operator+=(const Tag &t) {
        if(t.flip) swap(sum0,sum1);
        return *this;
    }
};

SegmentTree<Info, Tag, N> sgt;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sgt.build(1,n);
    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        if(in=='1') sgt.modify(i,i,{true});
    }

    int q;
    cin>>q;
    while(q--) {
        int op;
        cin>>op;
        if(op==1) {
            int l,r;
            cin>>l>>r;
            sgt.modify(l,r,{true});
        }
        else {
            int g;
            cin>>g;
            auto [x,y]=sgt.query(1,n);
            cout<<(g?y:x)<<' ';
        }
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}