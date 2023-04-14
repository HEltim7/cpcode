#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
constexpr LL INF=1e18;
LL val[N][3];
char type[N];

template<typename T,int R,int C=R> struct Matrix {
    array<array<T,C>,R> v;
    
    template<int Rr,int Cr> Matrix<T,R,Cr> 
    operator*(const Matrix<T,Rr,Cr> &r) const {
        static_assert(C==Rr,"");
        array<array<T,Cr>,R> ans;
        for(auto &x:ans) for(auto &y:x) y=INF;
        for(int i=0;i<R;i++) {
            for(int k=0;k<C;k++) {
                for(int j=0;j<Cr;j++) {
                    ans[i][j]=min(ans[i][j],v[i][k]+r[k][j]);
                }
            }
        }
        return ans;
    }

    Matrix operator+(const Matrix &r) const {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                ans[i][j]=v[i][j]+r[i][j];
        return ans;
    }

    Matrix operator-(const Matrix &r) const {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                ans[i][j]=v[i][j]-r[i][j];
        return ans;
    }

    Matrix &operator*=(const Matrix<T,C,C> &r) { return *this=*this*r; }
    Matrix &operator+=(const Matrix &r) { return *this=*this+r; }
    Matrix &operator-=(const Matrix &r) { return *this=*this-r; }

    Matrix pow(long long k) const {
        Matrix res(1),x=*this;
        while(k) { if(k&1) res*=x; k>>=1; x*=x; }
        return res;
    }

    auto &operator[](int idx) { return v[idx]; }
    auto &operator[](int idx) const { return v[idx]; }

    constexpr void clear() { v={}; }
    constexpr void unit(T x=1) {
        static_assert(R==C,"");
        clear(); for(int i=0;i<R;i++) v[i][i]=x;
    }

    constexpr Matrix() { clear(); }
    constexpr Matrix(T x) { unit(x); }
    constexpr Matrix(const array<array<T,C>,R> &x): v(x) {}
};

struct Info {
    Matrix<LL, 2> mat;
    void init(int l,int r) {
        if(l!=r) return;
        mat[0]={val[l][0],type[l]=='/'?val[l][2]:INF};
        mat[1]={type[l]=='\\'?val[l][2]:INF,val[l][1]};
    }

    Info operator+(const Info &r) const {
        Info res;
        res.mat=mat*r.mat;
        return res;
    }
};

template<int size,class Info> struct SegmentTree {
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
SegmentTree<N, Info> sgt;

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++) cin>>type[i];
    for(int i=1;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>val[i][j];
    sgt.build(1,n);
    while(m--) {
        int op;
        cin>>op;
        if(op==0) {
            int h;
            cin>>h>>type[h];
            Info v;
            v.init(h,h);
            sgt.modify(h,v);
        }
        else if(op==1) {
            int h;
            cin>>h;
            for(int i=0;i<3;i++) cin>>val[h][i];
            Info v;
            v.init(h,h);
            sgt.modify(h,v);
        }
        else {
            int hs,ht,ps,pt;
            cin>>hs>>ht>>ps>>pt;
            auto res=sgt.query(hs,ht-1).mat;
            Matrix<LL,1,2> ans;
            ans[0][ps]=0;
            ans[0][ps^1]=INF;
            ans*=res;
            cout<<(ans[0][pt]>=INF?-1:ans[0][pt])<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}