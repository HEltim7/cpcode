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

    Modint operator++(int) { auto res=*this; *this+=1; return res; }
    Modint operator--(int) { auto res=*this; *this-=1; return res; }
    Modint operator-  () { return *this*-1; }
    Modint &operator++() { return *this+=1; }
    Modint &operator--() { return *this-=1; }

    bool operator< (const Modint&x) { return v< x.v; }
    bool operator> (const Modint&x) { return v> x.v; }
    bool operator<=(const Modint&x) { return v<=x.v; }
    bool operator>=(const Modint&x) { return v>=x.v; }
    bool operator==(const Modint&x) { return v==x.v; }
    bool operator!=(const Modint&x) { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
    static_assert(0ULL+mod+mod-2<1ULL<<(sizeof(I)*8-1), "Modint overflow");
    static_assert(1ULL*(mod-1)*(mod-1)<1ULL<<(sizeof(L)*8-1), "Modint overflow");
    
}; using Mint=Modint<int,long long,998244353>;

template<typename T,int N> struct Matrix {
    array<array<T,N>,N> v;

    Matrix &operator*=(const Matrix &r) {
        array<array<T,N>,N> ans;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                T res{};
                for(int k=0;k<N;k++)
                    res+=v[i][k]*r[k][j];
                ans[i][j]=res;
            }
        }
        v=ans;
        return *this;
    }

    Matrix &operator+=(const Matrix &r) {
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) v[i][j]+=r[i][j];
        return *this;
    }

    Matrix &operator-=(const Matrix &r) {
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) v[i][j]-=r[i][j];
        return *this;
    }

    Matrix pow(long long k) {
        Matrix res(1),x=*this;
        while(k) { if(k&1) res*=x; k>>=1; x*=x; }
        return res;
    }

    friend Matrix operator*(Matrix l,const Matrix &r) { return l*=r; }
    friend Matrix operator+(Matrix l,const Matrix &r) { return l+=r; }
    friend Matrix operator-(Matrix l,const Matrix &r) { return l-=r; }

    auto &operator[](int idx) { return v[idx]; }
    auto &operator[](int idx) const { return v[idx]; }

    void clear() { v={}; }
    void unit(T x=1) { clear(); for(int i=0;i<N;i++) v[i][i]=x; }

    Matrix() {}
    Matrix(T x) { for(int i=0;i<N;i++) v[i][i]=x; }
    Matrix(const array<array<T,N>,N> &x) { v=x; }
};

bool arr[N];

struct SegmentTree {

    #define lch (u<<1)
    #define rch (u<<1|1)

    const Matrix<Mint, 2> PX={{{{2,1},{2,1}}}};
    const Matrix<Mint, 2> NX={{{{2,1},{0,3}}}};

    struct Node {
        int l,r;
        Matrix<Mint, 2> val,laz;
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