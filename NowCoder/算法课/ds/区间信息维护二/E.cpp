#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int arr[N];

int mod=1;
template<typename I,typename L,const I &mod> struct Modint {
    I v;
    I pow(L b) const {
        L res=1,a=v;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }
    I inv() const { return pow(mod-2); }

    Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=L(1)*v*x.inv()%mod; return *this; }

    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }

    Modint operator++(int) { auto res=*this; ++*this; return res; }
    Modint operator--(int) { auto res=*this; --*this; return res; }
    Modint &operator++() { v=v==mod-1?0:v+1; return *this; }
    Modint &operator--() { v=v?v-1:mod-1; return *this; }
    Modint operator-() { v=mod-v; return *this; }

    bool operator< (const Modint &x) const { return v< x.v; }
    bool operator> (const Modint &x) const { return v> x.v; }
    bool operator<=(const Modint &x) const { return v<=x.v; }
    bool operator>=(const Modint &x) const { return v>=x.v; }
    bool operator==(const Modint &x) const { return v==x.v; }
    bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    constexpr Modint(L x=0): v((x=abs(x)>=mod?x%mod:x)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,mod>;

struct Lazy {
    Mint add,mul;
    void init() {
        add=0;
        mul=1;
    }
    Lazy operator+(const Lazy &x) const {
        Lazy res;
        res.mul=mul*x.mul;
        res.add=add*x.mul+x.add;
        return res;
    }
    Lazy operator+=(const Lazy &x) { return *this=*this+x; }
};

struct Info {
    int len;
    Mint sum,sum2;
    void init(int l,int r) {
        len=r-l+1;
        if(l==r) sum=arr[l];
    }
    Info operator+(const Info &r) const {
        Info res;
        res.len=len+r.len;
        res.sum=sum+r.sum;
        res.sum2=sum2+r.sum2+sum*r.sum;
        return res;
    }
    Info operator+(const Lazy &x) const {
        Info res;
        res.len=len;
        res.sum=sum*x.mul+len*x.add;
        res.sum2=sum2*x.mul*x.mul+sum*(len-1)*x.add*x.mul+1LL*len*(len-1)/2*x.add*x.add;
        return res;
    }
    Info operator+=(const Lazy &x) { return *this=*this+x; }
};

template<int size,class Info,class Lazy> struct SegmentTree {
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
            lazy.init();
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
        tr[u].lazy.init();
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
SegmentTree<N, Info, Lazy> sgt;

void solve() {
    int n,m;
    cin>>n>>m>>mod;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sgt.build(1, n);
    while(m--) {
        int op,l,r;
        LL v;
        cin>>op>>l>>r;
        if(op<=2) cin>>v;
        if(op==1) sgt.modify(l, r, Lazy{v,1});
        else if(op==2) sgt.modify(l, r, Lazy{0,v});
        else cout<<sgt.query(l, r).sum2<<endl;
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