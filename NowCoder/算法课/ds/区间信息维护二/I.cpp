#include <algorithm>
#include <array>
#include <cassert>
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
constexpr int N=1e5+10,D=3;

template<typename I,typename L,I mod> struct Modint {
    I v;
    constexpr I pow(L b) const {
        L res=1,a=v;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }
    constexpr I inv() const { return pow(mod-2); }

    constexpr Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    constexpr Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    constexpr Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    constexpr Modint &operator/=(const Modint &x) { v=L(1)*v*x.inv()%mod; return *this; }

    friend constexpr Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend constexpr Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend constexpr Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend constexpr Modint operator/(Modint l,const Modint &r) { return l/=r; }
    friend constexpr Modint operator-(Modint r) { r.v=mod-r.v; return r; }

    Modint operator++(int) { auto res=*this; ++*this; return res; }
    Modint operator--(int) { auto res=*this; --*this; return res; }
    Modint &operator++() { v=v==mod-1?0:v+1; return *this; }
    Modint &operator--() { v=v?v-1:mod-1; return *this; }

    constexpr bool operator< (const Modint &x) const { return v< x.v; }
    constexpr bool operator> (const Modint &x) const { return v> x.v; }
    constexpr bool operator<=(const Modint &x) const { return v<=x.v; }
    constexpr bool operator>=(const Modint &x) const { return v>=x.v; }
    constexpr bool operator==(const Modint &x) const { return v==x.v; }
    constexpr bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    constexpr Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,int(1e9)+7>;

struct Lazy {
    array<Mint,D> add;

    void clear() {
        add={};
    }

    Lazy &operator+=(const Lazy &x) {
        for(int i=0;i<D;i++) add[i]+=x.add[i];
        return *this;
    }
};

struct Info {
    int len;
    Mint sum3;
    array<Mint,D> sum2,sum1;

    void init(int l,int r) {
        if(l!=r) return;
        len=r-l+1;
        sum3=r-l+1;
        fill(sum1.begin(),sum1.end(),r-l+1);
        fill(sum2.begin(),sum2.end(),r-l+1);
    }
    void init(int l) { init(l,l); }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.len=l.len+r.len;
        res.sum3=l.sum3+r.sum3;
        for(int i=0;i<D;i++) res.sum2[i]=l.sum2[i]+r.sum2[i];
        for(int i=0;i<D;i++) res.sum1[i]=l.sum1[i]+r.sum1[i];
        return res;
    }

    Info &operator+=(const Lazy &x) {
        for(int i=0;i<D;i++) {
            sum1[i]+=len*x.add[i];
            for(int j=0;j<D;j++) {
                if(i!=j) sum2[j]+=sum1[3-j-i]*x.add[i];
                else sum3+=sum2[j]*x.add[i];
            }
        }
        return *this;
    }

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
    sgt.build(1,n);
    while(m--) {
        char op;
        cin>>op;
        int idx=-1;
        if(op=='x') idx=0;
        else if(op=='y') idx=1;
        else if(op=='z') idx=2;

        if(idx==-1) {
            int l,r;
            cin>>l>>r;
            cout<<sgt.query(l,r).sum3<<endl;
        }
        else {
            int l,r,v;
            cin>>l>>r>>v;
            Lazy laz;
            laz.add[idx]=v;
            sgt.modify(l,r,laz);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}