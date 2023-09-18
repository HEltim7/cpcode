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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

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
    int maxx=0,minn=N;

    void init(int l,int r) {
        if(l!=r) return;
        maxx=0,minn=N;
    }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.maxx=max(l.maxx,r.maxx);
        res.minn=min(l.minn,r.minn);
        return res;
    }

    Info &operator+=(const Info &v) {
        maxx=max(maxx,v.maxx);
        minn=min(minn,v.minn);
        return *this;
    }
};

SegmentTree<Info, N> sgt;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n+1),l(k+1),r(k+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector<bool> mark(k+1);
    
    sgt.build(1,k);
    for(int i=1;i<=n;i++) {
        if(mark[arr[i]]) continue;
        mark[arr[i]]=1;
        sgt.modify(arr[i], {i,i});
        l[arr[i]]=sgt.query(arr[i],k).minn;
    }
    sgt.build(1,k);
    mark=vector<bool>(k+1);
    for(int i=n;i>=1;i--) {
        if(mark[arr[i]]) continue;
        mark[arr[i]]=1;
        sgt.modify(arr[i], {i,i});
        r[arr[i]]=sgt.query(arr[i],k).maxx;
    }

    for(int i=1;i<=k;i++) {
        if(l[i]==0) cout<<0<<" \n"[i==k];
        else cout<<2*(r[i]-l[i]+1)<<" \n"[i==k];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}