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
constexpr int N=2e5+10;

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
    int mx=0;
    void init(int l,int r) {
        if(l!=r) return;
        mx=0;
    }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.mx=max(l.mx,r.mx);
        return res;
    }

    Info &operator+=(const Info &v) {
        mx=v.mx;
        return *this;
    }
};

SegmentTree<Info, N> sgt;

template<int size,typename T=int> struct SparseTable {
    constexpr static int M=__lg(size)+1;
    T st[M][size];
    
    T merge(const T &x,const T &y) {
        return max(x,y);
    }

    void build(int n) {
        // for(int i=1;i<=n;i++) st[0][i]=arr[i]; // todo
        for(int k=1,t=1<<k;k<M;k++,t<<=1)
            for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++)
                st[k][i]=merge(st[k-1][i],st[k-1][mid]);
    }

    T query(int l,int r) {
        if(r<l) return 0;
        int k=__lg(r-l+1);
        return merge(st[k][l],st[k][r-(1<<k)+1]);
    }
};
SparseTable<N> lef,rig,sam;

void solve() {
    int n;
    cin>>n;
    vector<int> h(n+1);
    vector<LL> w(n+1);
    vector<int> ne(n+1),last(n+1);
    vector<pair<int,int>> pos;
    for(int i=1;i<=n;i++) {
        cin>>h[i];
        pos.emplace_back(h[i],i);
        if(last[h[i]]) ne[last[h[i]]]=i;
        last[h[i]]=i;
    }
    for(int i=1;i<=n;i++) cin>>w[i];
    sgt.build(1,n);
    for(int i=1;i<=n;i++) {
        int ge=sgt.query(h[i],n).mx;
        int le=sgt.query(1,h[i]).mx;
        int sa=sgt.query(h[i],h[i]).mx;
        lef.st[0][i]=ge;
        rig.st[0][i]=le;
        sam.st[0][i]=sa;
        sgt.modify(h[i], Info{i});
    }
    lef.build(n),rig.build(n),sam.build(n);

    partial_sum(w.begin(),w.end(),w.begin());
    vector<int> mark(n+1);
    sort(pos.begin(),pos.end(),greater<>());

    auto find_right=[&](int L,int R) {
        int l=R,r=n;
        while(l<r) {
            int mid=(l+r+1)/2;
            if(rig.query(R, mid)>=L) r=mid-1;
            else l=mid;
        }
        return l;
    };

    auto find_left=[&](int L,int R) {
        int l=1,r=L;
        while(l<r) {
            int mid=(l+r)/2;
            if(lef.query(mid, L)>=mid) l=mid+1;
            else r=mid;
        }
        return l;
    };

    LL ans=0;
    for(int z=0;z<pos.size();z++) {
        auto [v,i]=pos[z];
        int L=find_left(i, i);
        int R=find_right(i, i);
        int idx=sam.query(i, R);
        ans=max({ans,w[i]-w[L-1],w[R]-w[i-1]});
        if(idx>=L) {
            int l=idx,r=ne[idx];
            ans=max({ans,w[R]-w[l],w[r-1]-w[L-1]});
        }
        else ans=max(ans,w[R]-w[L-1]);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}