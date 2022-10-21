#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=2.5e5+10;
int a[N],b[N],c[N];

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
}; using Mtrx = Matrix<Mint, 3>;

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        Mtrx val,mul,add; 
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].val=tr[lch].val+tr[rch].val;
    }

    void update(Node &ch, const Node &p) {
        int len=ch.r-ch.l+1;
        ch.val*=p.mul;
        ch.val+=p.add*Mtrx(len);
        ch.mul*=p.mul;
        ch.add*=p.mul;
        ch.add+=p.add;
    }

    void pushdn(int u) {
        update(tr[lch], tr[u]);
        update(tr[rch], tr[u]);
        tr[u].mul.unit();
        tr[u].add.clear();
    }

    void modify_mul(int u,int l,int r,Mtrx val) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            tr[u].val*=val;
            tr[u].mul*=val;
            tr[u].add*=val;
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify_mul(lch, l, r, val);
            if(mid<r) modify_mul(rch, l, r, val);
            pushup(u);
        }
    }

    void modify_add(int u,int l,int r,Mtrx val) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            tr[u].val+=val*Mtrx(tr[u].r-tr[u].l+1);
            tr[u].add+=val;
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify_add(lch, l, r, val);
            if(mid<r) modify_add(rch, l, r, val);
            pushup(u);
        }
    }

    Mtrx query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) return tr[u].val;
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            Mtrx res;
            if(mid>=l) res+=query(lch, l, r);
            if(mid<r) res+=query(rch, l, r);
            pushup(u);
            return res;
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        tr[u].mul.unit();
        if(l==r) tr[u].val={{{{a[l],b[l],c[l]}}}};
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

Mtrx get(int type,int val) {
    Mtrx res;
    if(type==1) res.unit(),res[1][0]=1;
    else if(type==2) res.unit(),res[2][1]=1;
    else if(type==3) res.unit(),res[0][2]=1;
    else if(type==4) res[0][0]=val;
    else if(type==5) res.unit(),res[1][1]=val;
    else if(type==6) res.unit(),res[2][2]=0;
    else if(type==7) res[0][2]=val;
    return res;
}

void solve() {
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    sgt.build(1, 1, n);

    cin>>m;
    while(m--) {
        int op,l,r,v;
        cin>>op>>l>>r;
        if(op>=4&&op<=6) cin>>v;
        if(op<=3) sgt.modify_mul(1, l, r, get(op,0));
        else if(op==4) sgt.modify_add(1, l, r, get(4,v));
        else if(op==5) sgt.modify_mul(1, l, r, get(5,v));
        else if(op==6) {
            sgt.modify_mul(1, l, r, get(6,0));
            sgt.modify_add(1, l, r, get(7,v));
        }
        else {
            Mtrx res=sgt.query(1, l, r);
            cout<<res[0][0]<<' '<<res[0][1]<<' '<<res[0][2]<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}