#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int root[N],id[N],w[N],nw[N];
vector<int> adj[N];

struct PersistentSegmentTree {

    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    constexpr static int MAX_SIZE=N*20*2;

    struct Node {
        int ch[2];
        int cnt;
    } tr[MAX_SIZE];
    int idx;

    int new_node() {
        assert(idx<MAX_SIZE);
        return ++idx;
    }

    void pushup(int u) {
        tr[u].cnt=tr[lch].cnt+tr[rch].cnt;
    }

    void modify(int &u,int v,int l,int r,int p) {
        u=new_node();
        tr[u]=tr[v];
        if(l==r) tr[u].cnt++;
        else {
            int mid=l+r>>1;
            if(p<=mid) modify(lch, tr[v].ch[0], l, mid, p);
            else modify(rch, tr[v].ch[1], mid+1, r, p);
            pushup(u);
        }
    }

    int kth(vector<pair<int,int>> &seg,int l,int r, int k) {
        if(l==r) return l;
        int lcnt=0,mid=l+r>>1;
        for(auto [v,u]:seg) lcnt+=tr[lch].cnt-tr[tr[v].ch[0]].cnt;
        if(lcnt>=k) {
            for(auto &[v,u]:seg) u=lch,v=tr[v].ch[0];
            return kth(seg,l,mid,k);
        }
        else {
            for(auto &[v,u]:seg) u=rch,v=tr[v].ch[1];
            return kth(seg,mid+1,r,k-lcnt);
        }
    }

    void build(int &u,int l,int r) {
        u=new_node();
        tr[u]={l,r};
        if(l!=r) {
            int mid=l+r>>1;
            build(lch,l,mid);
            build(rch,mid+1,r);
        }
    }

    #undef lch
    #undef rch

} sgt;

namespace hpd {
    using PII=pair<int,int>;
    int dep[N],sz[N],top[N],p[N],hch[N],cnt;

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

    void init() {
        // cnt,hch -> 0
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
    int n,m;
    cin>>n>>m;
    vector<int> num;
    for(int i=1;i<=n;i++) cin>>w[i],num.push_back(w[i]);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        w[i]=lower_bound(num.begin(),num.end(),w[i])-num.begin()+1;
    int maxv=num.size();

    for(int i=2;i<=n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    hpd::init();
    sgt.build(root[0], 1, maxv);
    for(int i=1;i<=n;i++) sgt.modify(root[i], root[i-1], 1, maxv, nw[i]);

    int last=0;
    while(m--) {
        int u,v,k;
        cin>>u>>v>>k;
        auto seg=hpd::decompose(u^last, v);
        for(auto &[x,y]:seg) x=root[x-1],y=root[y];
        last=num[sgt.kth(seg,1,maxv,k)-1];
        cout<<last<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}