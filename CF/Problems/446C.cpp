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
constexpr int N=3e5+10;

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
}; using Mint=Modint<int,long long,int(1e9)+9>;

template<typename T,int R,int C=R> struct Matrix {
    array<array<T,C>,R> v;
    
    template<int Rr,int Cr> constexpr Matrix<T,R,Cr> 
    operator*(const Matrix<T,Rr,Cr> &r) const {
        static_assert(C==Rr,"");
        array<array<T,Cr>,R> ans;
        for(int i=0;i<R;i++) {
            for(int k=0;k<C;k++) {
                // if(v[i][k]==0) continue;
                for(int j=0;j<Cr;j++) {
                    ans[i][j]+=v[i][k]*r[k][j];
                }
            }
        }
        return ans;
    }

    constexpr Matrix operator+(const Matrix &r) const {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                ans[i][j]=v[i][j]+r[i][j];
        return ans;
    }

    constexpr Matrix operator-(const Matrix &r) const {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                ans[i][j]=v[i][j]-r[i][j];
        return ans;
    }

    constexpr Matrix &operator*=(const Matrix<T,C,C> &r) { return *this=*this*r; }
    constexpr Matrix &operator+=(const Matrix &r) { return *this=*this+r; }
    constexpr Matrix &operator-=(const Matrix &r) { return *this=*this-r; }

    constexpr Matrix pow(long long k) const {
        Matrix res(1),x=*this;
        while(k) { if(k&1) res*=x; k>>=1; x*=x; }
        return res;
    }

    constexpr auto &operator[](int idx) { return v[idx]; }
    constexpr auto &operator[](int idx) const { return v[idx]; }

    constexpr void clear() { v={}; }
    constexpr void unit(T x=1) {
        static_assert(R==C,"");
        clear(); for(int i=0;i<R;i++) v[i][i]=x;
    }

    constexpr Matrix() { clear(); }
    constexpr Matrix(T x) { unit(x); }
    constexpr Matrix(const array<array<T,C>,R> &x): v(x) {}
};
constexpr Matrix<Mint,3> one({{{0,1,1},{1,1,1},{0,0,1}}});
constexpr Matrix<Mint,1,3> f1({0,1,1});
LL pre[N];
Matrix<Mint,3> pw[N];

struct Info {
    int len;
    Matrix<Mint,1,3> v;

    void init(int l,int r) {
        if(l!=r) return;
        len=r-l+1;
    }
    void init(int l) { init(l,l); }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.len=l.len+r.len;
        res.v=l.v*pw[r.len]+r.v;
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

    void modify(int p,const Matrix<Mint,1,3> &v) {
        int u=leaf[p];
        tr[u].info.v+=v;
        while(u>>=1) pushup(u);
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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>pre[i],pre[i]+=pre[i-1];
    sgt.build(1,n);

    while(m--) {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1) {
            sgt.modify(l, f1);
            if(r+1<=n) {
                auto sub=Matrix<Mint,1,3>()-f1*pw[r-l+1];
                sub[0][2]=sub[0][1];
                sgt.modify(r+1, sub);
            }
        }
        else {
            Mint ans=pre[r]-pre[l-1];
            auto cal=[&](int x) {
                if(x<1) return Mint();
                auto res=sgt.query(1,x).v;
                return res[0][2];
            };
            ans+=cal(r)-cal(l-1);
            cout<<ans<<endl;
        }
    }
}

int main() {
    pw[0].unit();
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*one;
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}