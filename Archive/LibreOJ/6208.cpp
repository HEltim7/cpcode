#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e5+10;

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

    Matrix() { clear(); }
    Matrix(T x) { unit(x); }
    Matrix(const array<array<T,N>,N> &x) { v=x; }
}; using Mtrx=Matrix<int,2>;

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        Mtrx val,mul=Mtrx(1),add;
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].val=tr[lch].val+tr[rch].val;
    }

    void update(Node &ch,const Node &p) {
        int len=ch.r-ch.l+1;
        ch.val*=p.mul;
        ch.val+=p.add*len;
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
            tr[u].mul*=val;
            tr[u].add*=val;
            tr[u].val*=val;
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
            int len=tr[u].r-tr[u].l+1;
            tr[u].val+=val*len;
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

    int query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) return tr[u].val[0][1];
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) return query(lch, l, r);
            else return query(rch, l, r);
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) {}
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

namespace hpd {
    using PII=pair<int,int>;
    int id[N],cnt;
    int dep[N],sz[N],top[N],p[N],hch[N];
    vector<int> adj[N];

    void dfs1(int u,int fa,int d) {
        dep[u]=d,p[u]=fa,sz[u]=1;
        for(int v:adj[u]) {
            if(v==fa) continue;
            dfs1(v,u,d+1);
            sz[u]+=sz[v];
            if(sz[hch[u]]<sz[v]) hch[u]=v;
        }
    }

    void dfs2(int u,int t) {
        id[u]=++cnt,top[u]=t;
        if(!hch[u]) return;
        dfs2(hch[u],t);
        for(int v:adj[u])
            if(v!=p[u]&&v!=hch[u]) dfs2(v,v);
    }

    void init() {
        dfs1(1,-1,1); dfs2(1,1);
    }

    vector<PII> decompose(int x,int y) {
        vector<PII> res;
        while(top[x]!=top[y]) {
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            res.emplace_back(id[top[x]],id[x]);
            x=p[top[x]];
        }
        if(dep[x]<dep[y]) swap(x,y);
        res.emplace_back(id[y],id[x]);
        return res;
    }

    PII decompose(int x) {
        return { id[x],id[x]+sz[x]-1 };
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1,u,v;i<n;i++) {
        cin>>u>>v;
        hpd::adj[u].push_back(v);
        hpd::adj[v].push_back(u);
    }
    hpd::init();
    sgt.build(1, 1, n);
    
    int m;
    cin>>m;
    while(m--) {
        int opt,x,d;
        cin>>opt>>x;
        if(opt<=2) cin>>d;
        if(opt==1) {
            auto seg=hpd::decompose(1,x);
            Mtrx val{{{{d,0}}}};
            for(auto [l,r]:seg) sgt.modify_add(1, l, r, val);
        }
        else if(opt==2) {
            auto seg=hpd::decompose(1,x);
            Mtrx val{{{{1,d},{0,1}}}};
            for(auto [l,r]:seg) sgt.modify_mul(1, l, r, val);
        }
        else cout<<sgt.query(1, hpd::id[x], hpd::id[x])<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}