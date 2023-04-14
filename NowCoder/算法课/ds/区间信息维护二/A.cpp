#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
int arr[N];

struct Lazy {
    int add;
    void clear() {
        add=0;
    }

    Lazy operator+(const Lazy &x) const {
        Lazy res;
        res.add=add+x.add;
        return res;
    }

    Lazy operator+=(const Lazy &x) { return *this=*this+x; }
};

struct Info {
    int minn;
    void init(int l,int r) {
        if(l!=r) return;
        minn=arr[l];
    }
    void init(int l) { init(l,l); }

    Info operator+(const Info &r) const {
        Info res;
        res.minn=min(minn,r.minn);
        return res;
    }

    Info operator+(const Lazy &x) const {
        Info res;
        res.minn=minn-x.add;
        return res;
    }

    Info operator+=(const Lazy &x) { return *this=*this+x; }

    Info()=default;
    Info(int l) { init(l); }
    Info(int l,int r) { init(l,r); }
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

    void build(int u,int l,int r) {
        tr[u].init(l,r);
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
            pushup(u);
        }
    }
    void build(int l,int r) { build(1,l,r); }

    #undef lch
    #undef rch
};
SegmentTree<Info, Lazy, N> sgt;

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sgt.build(1,n);
    for(int i=1;i<=m;i++) {
        int d,s,t;
        cin>>d>>s>>t;
        if(sgt.query(s,t).minn<d) {
            cout<<-1<<endl;
            cout<<i<<endl;
            return;
        }
        else sgt.modify(s,t,Lazy{d});
    }
    cout<<0<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}