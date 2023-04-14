#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10,M=3e5;

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
}; using Mint=Modint<int,long long,998244353>;

template<typename T,int R,int C=R> struct Matrix {
    array<array<T,C>,R> v;

    template<int Rr,int Cr> Matrix<T,R,Cr> operator*(const Matrix<T,Rr,Cr> &r) {
        static_assert(C==Rr,"");
        array<array<T,Cr>,R> ans;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                T res{};
                for(int k=0;k<C;k++)
                    res+=v[i][k]*r[k][j];
                ans[i][j]=res;
            }
        }
        return ans;
    }

    Matrix operator+(const Matrix &r) {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) ans[i][j]=v[i][j]+r[i][j];
        return ans;
    }

    Matrix operator-(const Matrix &r) {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) ans[i][j]=v[i][j]-r[i][j];
        return ans;
    }

    Matrix &operator*=(const Matrix<T,C,C> &r) { return *this=*this*r; }
    Matrix &operator+=(const Matrix &r) { return *this=*this+r; }
    Matrix &operator-=(const Matrix &r) { return *this=*this-r; }

    Matrix pow(long long k) {
        Matrix res(1),x=*this;
        while(k) { if(k&1) res*=x; k>>=1; x*=x; }
        return res;
    }

    auto &operator[](int idx)       { return v[idx]; }
    auto &operator[](int idx) const { return v[idx]; }

    constexpr void clear() { v={}; }
    constexpr void unit(T x=1) { static_assert(R==C,""); clear(); for(int i=0;i<R;i++) v[i][i]=x; }

    constexpr Matrix() { clear(); }
    constexpr Matrix(T x) { unit(x); }
    constexpr Matrix(const array<array<T,C>,R> &x) { v=x; }
};

bool arr[N];

struct SegmentTree {

    #define lch (u<<1)
    #define rch (u<<1|1)

    static constexpr Matrix<Mint, 2> PX={{{{2,1},{2,1}}}};
    static constexpr Matrix<Mint, 2> NX={{{{2,1},{0,3}}}};

    struct Node {
        int l,r;
        Matrix<Mint, 1, 2> val;
        Matrix<Mint, 2, 2> laz;
        void operator*=(const Matrix<Mint, 2> &x) {
            val*=x;
            laz*=x;
        }
    } tr[N<<2];

    void pushup(int u) {
        tr[u].val=tr[lch].val+tr[rch].val;
    }

    void pushdn(int u) {
        tr[lch]*=tr[u].laz;
        tr[rch]*=tr[u].laz;
        tr[u].laz.unit();
    }

    void modify(int u,int l,int r,bool type) {
        if(tr[u].l>=l&&tr[u].r<=r) tr[u]*=type?PX:NX;
        else {
            int mid=tr[u].l+tr[u].r>>1;
            pushdn(u);
            if(mid>=l) modify(lch, l, r, type);
            if(mid<r) modify(rch, l, r, type);
            pushup(u);
        }
    }
    
    void build(int u,int l,int r) {
        tr[u]={l,r};
        tr[u].laz.unit();
        if(l==r) {
            if(arr[l]) tr[u].val[0][0]=1;
            else tr[u].val[0][1]=1;
        }
        else {
            int mid=l+r>>1;
            build(lch, l, mid);
            build(rch, mid+1, r);
            pushup(u);
        }
    }

    #undef lch
    #undef rch

} sgt;

int L[N],R[N];

void solve() {
    int n;
    cin>>n;
    int l,r,lmin=N,rmax=0;
    for(int i=1;i<=n;i++) {
        cin>>L[i]>>R[i];
        lmin=min(lmin,L[i]);
        rmax=max(rmax,R[i]);
    }
    for(int i=L[1];i<=R[1];i++) arr[i]=1;
    sgt.build(1, lmin, rmax);

    for(int i=2;i<=n;i++) {
        int l=L[i],r=R[i];
        sgt.modify(1, l, r, 1);
        if(l-1>=lmin) sgt.modify(1, lmin, l-1, 0);
        if(r+1<=rmax) sgt.modify(1, r+1, rmax, 0);
    }
    cout<<sgt.tr[1].val[0][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}