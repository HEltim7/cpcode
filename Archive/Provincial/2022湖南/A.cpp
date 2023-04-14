#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=8e4+10,INF=2e9;

namespace hpd {
    using PII=pair<int,int>;
    int id[N],w[N],nw[N],cnt;
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
        id[u]=++cnt,nw[cnt]=w[u],top[u]=t;
        if(!hch[u]) return;
        dfs2(hch[u],t);
        for(int v:adj[u])
            if(v!=p[u]&&v!=hch[u]) dfs2(v,v);
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

    void init() {
        dfs1(1,-1,1); dfs2(1,1);
    }

    void clear(int n) {
        cnt=0;
        for(int i=1;i<=n;i++) adj[i].clear();
        fill(hch, hch+n+1, 0);
    }
}

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAX_SIZE=N;

    struct Node {
        int l,r;
        int val,laz;
    } tr[MAX_SIZE<<2];

    void pushup(int u) {
        tr[u].val=min(tr[lch].val,tr[rch].val);
    }

    void pushdn(int u) {
        tr[lch].laz+=tr[u].laz;
        tr[lch].val+=tr[u].laz;
        tr[rch].laz+=tr[u].laz;
        tr[rch].val+=tr[u].laz;
        tr[u].laz=0;
    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            tr[u].val+=val;
            tr[u].laz+=val;
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    int query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { return tr[u].val; }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            int res=INF;
            if(mid>=l) res=min(res,query(lch, l, r));
            if(mid<r) res=min(res,query(rch, l, r));
            return res;
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) { tr[u].val=hpd::nw[l]; }
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
    while(cin>>n>>m) {
        hpd::clear(n*2);
        for(int i=1;i<n;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            hpd::adj[u].push_back(i+n);
            hpd::adj[i+n].push_back(u);
            hpd::adj[v].push_back(i+n);
            hpd::adj[i+n].push_back(v);
            hpd::w[u]=hpd::w[v]=INF;
            hpd::w[i+n]=w;
        }
        hpd::init();
        sgt.build(1, 1, n*2);

        int ans=0;
        while(m--) {
            int a,b,k;
            cin>>a>>b>>k;
            
            auto &&v=hpd::decompose(a,b);
            int minn=INF;
            for(auto [l,r]:v) 
                minn=min(minn,sgt.query(1, l, r));
            if(minn>=k) {
                for(auto [l,r]:v)
                    sgt.modify(1, l, r, -k);
                ans+=k;
            }
        }
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}