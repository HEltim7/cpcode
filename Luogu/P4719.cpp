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
constexpr int N=1e5+10,INF=1e9;
int f[N][2],g[N][2];
int ori[N];

template<typename T,int R,int C=R> struct Matrix {
    array<array<T,C>,R> v;

    template<int Rr,int Cr> Matrix<T,R,Cr> operator*(const Matrix<T,Rr,Cr> &r) {
        static_assert(C==Rr,"");
        array<array<T,Cr>,R> ans;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                T res=-INF;
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

#ifndef ONLINE_JUDGE
    friend ostream &operator<<(ostream &os,Matrix x) {
        debug::logv.print(x.v);
        return os;
    }
#endif

    Matrix() { clear(); }
    Matrix(T x) { unit(x); }
    Matrix(const array<array<T,C>,R> &x) { v=x; }
}; using Mat=Matrix<int, 2>;

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAX_SIZE=N;

    struct Node {
        int l,r;
        Mat val;
    } tr[MAX_SIZE<<2];
    int leaf[N];

    void pushup(int u) {
        tr[u].val=tr[lch].val*tr[rch].val;
    }

    void modify(int p,Mat val) {
        int u=leaf[p];
        tr[u].val=val;
        while(u>>=1) pushup(u);
    }

    Mat query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { return tr[u].val; }
        else {
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l&&mid<r) return query(lch,l,r)*query(rch,l,r);
            else if(mid>=l) return query(lch, l, r);
            else return query(rch, l, r);
        }
    }

    Mat get(int p) {
        int u=leaf[p];
        return tr[u].val;
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) {
            leaf[l]=u;
            tr[u].val[0]={g[ori[l]][0],g[ori[l]][0]};
            tr[u].val[1]={g[ori[l]][1],-INF};
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
    int id[N],w[N],nw[N],cnt;
    int dep[N],sz[N],top[N],bot[N],p[N],hch[N];
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
        id[u]=++cnt,ori[id[u]]=u,nw[cnt]=w[u],top[u]=t;
        bot[u]=u;
        if(!hch[u]) return;
        dfs2(hch[u],t);
        bot[u]=bot[hch[u]];
        for(int v:adj[u])
            if(v!=p[u]&&v!=hch[u]) dfs2(v,v);
    }

    void dfs3(int u) {
        for(int v:adj[u]) {
            if(v!=p[u]) {
                dfs3(v);
                if(v!=hch[u]) {
                    g[u][0]+=max(f[v][0],f[v][1]);
                    g[u][1]+=f[v][0];
                }
            }
        }
        g[u][1]+=w[u];
        f[u][0]=g[u][0]+max(f[hch[u]][0],f[hch[u]][1]);
        f[u][1]=g[u][1]+f[hch[u]][0];
    }

    int lca(int x,int y) {
        while(top[x]!=top[y]) {
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            x=p[top[x]];
        }
        if(dep[x]<dep[y]) swap(x,y);
        return y;
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

    int work(int u,int val) {
        Mat modi=sgt.get(id[u]);
        modi[1][0]+=val-w[u];
        w[u]=val;
        for(;;) {
            int tp=top[u];
            int bt=bot[u];
            Mat pre=sgt.query(1, id[tp], id[bt]);
            sgt.modify(id[u], modi);
            if(tp==1) break;
            Mat cur=sgt.query(1, id[tp], id[bt]);
            int pref0=pre[0][0];
            int pref1=pre[1][0];
            int curf0=cur[0][0];
            int curf1=cur[1][0];
            int addg0=max(curf0,curf1)-max(pref0,pref1);
            int addg1=curf0-pref0;
            
            u=p[tp];
            modi=sgt.get(id[u]);
            modi[0][0]+=addg0;
            modi[0][1]+=addg0;
            modi[1][0]+=addg1;
        }

        Mat res=sgt.query(1, id[top[1]], id[bot[1]]);
        return max(res[0][0],res[1][0]);
    }

    void init() {
        dfs1(1,-1,1); dfs2(1,1); dfs3(1);
    }

    void clear(int n) {
        cnt=0;
        fill(hch, hch+n+1, 0);
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>hpd::w[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        hpd::adj[u].push_back(v);
        hpd::adj[v].push_back(u);
    }
    hpd::init();
    sgt.build(1, 1, n);

    while(m--) {
        int u,val;
        cin>>u>>val;
        cout<<hpd::work(u, val)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}