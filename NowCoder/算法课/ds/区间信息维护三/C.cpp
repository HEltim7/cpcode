#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
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
constexpr int N=2e5+10;
int arr[N];

LL sqrt_dif(LL x) {
    return x-LL(sqrt(x));
}

struct Lazy {
    LL add;

    void clear() {
        add=0;
    }

    Lazy &operator+=(const Lazy &x) {
        add+=x.add;
        return *this;
    }
};

struct Info {
    bool final;
    int len;
    LL sum,maxx,minn;

    void init(int l,int r) {
        if(l!=r) return;
        final=1;
        len=r-l+1;
        sum=maxx=minn=arr[l];
    }
    void init(int l) { init(l,l); }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.len=l.len+r.len;
        res.sum=l.sum+r.sum;
        res.maxx=max(l.maxx,r.maxx);
        res.minn=min(l.minn,r.minn);
        res.final=sqrt_dif(res.maxx)==sqrt_dif(res.minn);
        return res;
    }

    Info &operator+=(const Lazy &x) {
        maxx+=x.add;
        minn+=x.add;
        sum+=x.add*len;
        final=sqrt_dif(maxx)==sqrt_dif(minn);
        return *this;
    }

    explicit operator bool() const { return final; }
};

template<class Info,class Lazy,int size> struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)

    struct Node {
        bool clean;
        int l,r;
        Info info;
        Lazy lazy;
        void init(int l,int r) {
            clean=1;
            this->l=l;
            this->r=r;
            info.init(l, r);
            lazy.clear();
        }
    };

    array<Node, 1<<__lg(size)<<2|1> tr;

    void pushup(int u) {
        tr[u].info=tr[lch].info+tr[rch].info;
    }

    void update(Node &ch, const Lazy &x) {
        ch.clean=0;
        ch.info+=x;
        ch.lazy+=x;
    }

    void pushdn(int u) {
        if(tr[u].clean) return;
        update(tr[lch],tr[u].lazy);
        update(tr[rch],tr[u].lazy);
        tr[u].clean=1;
        tr[u].lazy.clear();
    }

    Info query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { return tr[u].info; }
        else {
            pushdn(u);
            int mid=(tr[u].l+tr[u].r)/2;
            if(mid>=l&&mid<r) return query(lch,l,r)+query(rch,l,r);
            else if(mid>=l) return query(lch,l,r);
            return query(rch,l,r);
        }
    }
    Info query(int l,int r) { return query(1,l,r); }

    void modify(int u,int l,int r,const Lazy &v) {
        if(tr[u].l>=l&&tr[u].r<=r) { update(tr[u],v); }
        else {
            pushdn(u);
            int mid=(tr[u].l+tr[u].r)/2;
            if(mid>=l) modify(lch,l,r,v);
            if(mid<r) modify(rch,l,r,v);
            pushup(u);
        }
    }
    void modify(int l,int r,const Lazy &v) { modify(1,l,r,v); }

    void release(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r&&tr[u].info) {
            LL t=tr[u].info.maxx;
            LL d=LL(sqrt(t))-t;
            update(tr[u], Lazy{d});
        }
        else {
            pushdn(u);
            int mid=(tr[u].l+tr[u].r)/2;
            if(l<=mid) release(lch,l,r);
            if(r>mid) release(rch,l,r);
            pushup(u);
        }
    }
    void release(int l,int r) { release(1,l,r); }

    void build(int u,int l,int r) {
        tr[u].init(l,r);
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
            pushup(u);
        }
    }
    void build(int l=1,int r=size) { build(1,l,r); }

    #undef lch
    #undef rch
};
SegmentTree<Info, Lazy, N> sgt;

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sgt.build(1,n);
    while(m--) {
        int op,l,r,x;
        cin>>op>>l>>r;
        if(op==1) sgt.release(l,r);
        else if(op==2) {
            cin>>x;
            sgt.modify(l,r,Lazy{x});
        }
        else {
            auto res=sgt.query(l,r);
            cout<<res.sum<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}