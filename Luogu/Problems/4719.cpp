#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e5+10;
int w[N],f[N][2],g[N][2];

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

namespace hpd {
    using PII=pair<int,int>;
    int id[N],rid[N],cnt;
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
        id[u]=++cnt,rid[id[u]]=u,top[u]=t;
        if(!hch[u]) return;
        dfs2(hch[u],t);
        for(int v:adj[u])
            if(v!=p[u]&&v!=hch[u]) dfs2(v,v);
    }

    void dfs3(int u,int fa) {
        f[u][1]=g[u][1]=w[u];
        for(int v:adj[u]) {
            if(v!=fa) {
                dfs3(v,u);
                f[u][0]+=max(f[v][0],f[v][1]);
                f[u][1]+=f[v][0];
                if(v!=hch[u]) {
                    g[u][0]+=max(f[v][0],f[v][1]);
                    g[u][1]+=f[v][0];
                }
            }
        }
    }

    void init() {
        dfs1(1,-1,1);
        dfs2(1,1);
        dfs3(1,-1);
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

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        Mtrx val,laz;
    } tr[MAXSIZE<<2];

    void pushup(int u) {

    }

    void pushdn(int u) {

    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) {}
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    int query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) {}
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            
            if(mid>=l) query(lch, l, r);
            if(mid<r) query(rch, l, r);
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

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1,u,v;i<n;i++) {
        cin>>u>>v;
        hpd::adj[u].push_back(v);
        hpd::adj[v].push_back(u);
    }
    hpd::init();
    sgt.build(1, 1, n);

    while(m--) {
        int x,y;
        cin>>x>>y;

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}