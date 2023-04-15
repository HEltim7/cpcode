#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;
int maxm,maxk;

struct Info {
    int m,k;
    void init(int l,int r) {
        if(l!=r) return;
        m=maxm;
        k=maxk;
    }
    void init(int l) { init(l,l); }

    Info operator+(const Info &r) const {
        Info res;
        res.m=max(m,r.m);
        res.k=max(k,r.k);
        return res;
    }

    Info()=default;
    Info(int l) { init(l); }
    Info(int l,int r) { init(l,r); }
};

template<class Info,int size> struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)

    struct Node {
        int l,r;
        Info info;
        void init(int l,int r) {
            this->l=l;
            this->r=r;
            info.init(l, r);
        }
    };

    array<Node, 1<<__lg(size)<<2|1> tr;
    array<int, size+1> leaf;

    void pushup(int u) {
        tr[u].info=tr[lch].info+tr[rch].info;
    }

    Info query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { return tr[u].info; }
        else {
            int mid=(tr[u].l+tr[u].r)/2;
            if(mid>=l&&mid<r) return query(lch,l,r)+query(rch,l,r);
            else if(mid>=l) return query(lch,l,r);
            return query(rch,l,r);
        }
    }
    Info query(int l,int r) { return query(1,l,r); }

    void modify(int p,const Info &v) {
        int u=leaf[p];
        tr[u].info=v;
        while(u>>=1) pushup(u);
    }

    int modify(int cnt) {
        int u=1;
        if(tr[1].info.m<cnt||tr[1].k<=0) return false;
        while(tr[u].l!=tr[u].r) {
            if(tr[lch].info.m>=cnt&&tr[lch].info.k) u=lch;
            else u=rch;
        }
    }

    void build(int u,int l,int r) {
        tr[u].init(l,r);
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
            pushup(u);
        }
        else leaf[l]=u;
    }
    void build(int l,int r) { build(1,l,r); }

    #undef lch
    #undef rch
};
SegmentTree<Info, N> sgt;

void solve() {
    int n;
    cin>>n>>maxm>>maxk;
    sgt.build(1,n);
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}