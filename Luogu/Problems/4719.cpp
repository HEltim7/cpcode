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

constexpr int N=1e5+10,INF=-1e7;
int w[N],f[N][2],g[N][2],id[N],ed[N],rid[N];

template<typename T,int R,int C=R> struct Matrix {
    array<array<T,C>,R> v;

    template<int Rr,int Cr> Matrix<T,R,Cr> operator*(const Matrix<T,Rr,Cr> &r) {
        static_assert(C==Rr,"");
        array<array<T,Cr>,R> ans;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                T res=-1e7;
                for(int k=0;k<C;k++)
                    res=max(res,v[i][k]+r[k][j]);
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
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        Mtrx val;
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].val=tr[lch].val*tr[rch].val;
    }

    void pushdn(int u) {
        
    }

    void modify(int u,int l,int r,Mtrx val) {
        if(tr[u].l>=l&&tr[u].r<=r) tr[u].val=val;
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    Mtrx query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) return tr[u].val;
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l&&mid<r) return query(lch, l, r)*query(rch ,l ,r);
            else if(mid>=l) return query(lch, l, r);
            else return query(rch, l, r);
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) {
            int x=rid[u];
            tr[u].val={{{{g[x][0],g[x][1]},{g[x][1],INF}}}};
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

namespace hpd {
    using PII=pair<int,int>;
    int dep[N],sz[N],top[N],p[N],hch[N],cnt;
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
        if(!hch[u]) {
            ed[u]=id[u];
            return;
        }
        dfs2(hch[u],t);
        for(int v:adj[u])
            if(v!=p[u]&&v!=hch[u]) dfs2(v,v);
        ed[u]=ed[hch[u]];
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
        dfs1(1,0,1);
        dfs2(1,1);
        dfs3(1,0);
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

    void modify(int u,int val) {
        vector<int> stk;
        vector<Mtrx> pre;
        while(u) {
            pre.push_back(sgt.query(1, id[top[u]], ed[u]));
            stk.push_back(u);
            u=p[top[u]];
        }
        debug(stk);

        u=stk[0];
        Mtrx cur=sgt.query(1, id[u], id[u]);
        cur[1][0]=val;
        sgt.modify(1, id[u], id[u], cur);
        for(int i=1;i<stk.size();i++) {
            int u=stk[i-1],fa=stk[i];
            cur=sgt.query(1, id[top[u]], ed[u]);
            auto &old=pre[i];
            int f0add=max(cur[0][0],cur[0][1])-max(old[0][0],old[0][1]);
            int f1add=max(cur[1][0],cur[1][1])-max(old[1][0],old[1][1]);
            Mtrx upd=sgt.query(1, id[fa], id[fa]);
            upd[0][0]=upd[0][1]+=f0add;
            upd[1][0]+=f1add;
            sgt.modify(1, id[fa], id[fa], upd);
        }
    }
}

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
    debug(f[1][0],f[1][1]);

    while(m--) {
        int x,y;
        cin>>x>>y;
        // hpd::modify(x, y);
        debug(sgt.query(1, id[1], ed[1]).v);
        auto res=sgt.query(1, id[1], ed[1])*Matrix<int,2,1>();
        cout<<max(res[0][0],res[1][0])<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}