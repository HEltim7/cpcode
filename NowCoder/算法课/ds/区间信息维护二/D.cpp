#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e4+10;
int arr[N];

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

    auto &operator[](int idx) { return v[idx]; }
    auto &operator[](int idx) const { return v[idx]; }

    void clear() { v={}; }
    void unit(T x=1) { static_assert(R==C,""); clear(); for(int i=0;i<R;i++) v[i][i]=x; }

    Matrix() { clear(); }
    Matrix(T x) { unit(x); }
    Matrix(const array<array<T,C>,R> &x) { v=x; }
}; using Mtrx=Matrix<int, 2>;

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAX_SIZE=N;

    struct Node {
        int l,r;
        Matrix<LL,1,3> val;
        Matrix<LL,3> laz=Matrix<LL, 3>(1);
        bool clean=1;
    } tr[MAX_SIZE<<2];

    void pushup(int u) {
        tr[u].val=tr[lch].val+tr[rch].val;
    }

    void pushdn(int u) {
        if(tr[u].clean) return;
        tr[lch].val*=tr[u].laz;
        tr[lch].laz*=tr[u].laz;
        tr[rch].val*=tr[u].laz;
        tr[rch].laz*=tr[u].laz;
        tr[u].laz.unit();
        tr[u].clean=1;
        tr[lch].clean=0;
        tr[rch].clean=0;
    }

    void modify(int u,int l,int r,const Matrix<LL,3> &val) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            tr[u].val*=val;
            tr[u].laz*=val;
            tr[u].clean=0;
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    Matrix<LL,1,3> query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { return tr[u].val; }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            Matrix<LL,1,3> res;
            if(mid>=l) res+=query(lch, l, r);
            if(mid<r) res+=query(rch, l, r);
            return res;
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) { tr[u].val[0]={r-l+1,arr[l],arr[l]*arr[l]}; }
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

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sgt.build(1, 1, n);
    while(m--) {
        int op,l,r;
        LL v;
        cin>>op>>l>>r;
        if(op>=3) cin>>v;
        if(op<=2) {
            auto res=sgt.query(1, l, r);
            cout<<res[0][op]<<endl;
        }
        else if(op==3) {
            if(v==1) continue;
            Matrix<LL,3> val({{{1,0,0},{0,v,0},{0,0,v*v}}});
            sgt.modify(1, l, r, val);
        }
        else {
            Matrix<LL,3> val({{{1,v,v*v},{0,1,2*v},{0,0,1}}});
            sgt.modify(1, l, r, val);
        }
        debug(sgt.query(1, 1, n)[0]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}