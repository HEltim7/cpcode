#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e5+10,M=20;
vector<int> adj[N];
int id[N],ed[N],arr[N],idx;
int fa[N][M+1],dep[N]={0,1};

void getlca(int u,int p) {
    for(int v:adj[u]) {
        if(v==p) continue;
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        for(int i=1;i<=M;i++)
            fa[v][i]=fa[fa[v][i-1]][i-1];
        getlca(v,u);
    }
}

int lca(int a,int b) {
    if(dep[a]<dep[b]) swap(a,b);
    for(int k=M;~k;k--)
        if(dep[fa[a][k]]>=dep[b])
            a=fa[a][k];
    if(a==b) return a;
    for(int k=M;~k;k--)
        if(fa[a][k]!=fa[b][k])
            a=fa[a][k],b=fa[b][k];
    return fa[a][0];
}

struct SegmentTree {

    constexpr static int MAX_SIZE=1e5+10;
    struct Node {
        int l,r;
        int dis,laze;
    } tr[MAX_SIZE*4];
    
    void pushup(int u) {
        tr[u].dis=max(tr[u<<1].dis,tr[u<<1|1].dis);
    }

    void pushdn(int u) {
        tr[u<<1].dis+=tr[u].laze;
        tr[u<<1].laze+=tr[u].laze;
        tr[u<<1|1].dis+=tr[u].laze;
        tr[u<<1|1].laze+=tr[u].laze;
        tr[u].laze=0;
    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) tr[u].dis+=val,tr[u].laze+=val;
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(u<<1,l,r,val);
            if(mid<r) modify(u<<1|1,l,r,val);
            pushup(u);
        }
    }

    int query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) return tr[u].dis;
        pushdn(u);
        int mid=tr[u].l+tr[u].r>>1;
        int res=0;
        if(mid>=l) res=max(res,query(u<<1,l,r));
        if(mid<r) res=max(res,query(u<<1|1,l,r));
        return res;
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) tr[u].dis=arr[l];
        else {
            int mid=l+r>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }

} sgt;

struct LinkCutTree {
    
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    #define wch(u) (tr[tr[u].p].ch[1]==u)
    constexpr static int MAX_SIZE=1e5+10;

    struct Node {
        int ch[2],p;
    } tr[MAX_SIZE];
    int stk[MAX_SIZE];

    bool is_root(int u) {
        return tr[tr[u].p].ch[0]!=u&&tr[tr[u].p].ch[1]!=u;
    }

    void rotate(int x) {
        int y=tr[x].p,z=tr[y].p,k=wch(x);
        if(!is_root(y)) tr[z].ch[wch(y)]=x;
        tr[y].ch[k]=tr[x].ch[!k],tr[tr[y].ch[k]].p=y;
        tr[x].ch[!k]=y,tr[y].p=x,tr[x].p=z;
    }

    void splay(int u) {
        for(int fa;!is_root(u);rotate(u))
            if(!is_root(fa=tr[u].p)) rotate(wch(u)==wch(fa)?fa:u);
    }

    void access(int u) {
        int t=u;
        for(int v=0;u;v=u,u=tr[u].p) {
            splay(u);
            int x,y=rch;
            rch=0;
            if(y) {
                x=find_root(y);
                sgt.modify(1, id[x], ed[x], 1);
            }
            if(v) {
                x=find_root(v);
                sgt.modify(1, id[x], ed[x], -1);
                rch=x;
            }
        }
        splay(t);
    }

    int find_root(int u) {
        splay(u);
        while(lch) u=lch;
        splay(u);
        return u;
    }

    void build(int u,int fa) {
        id[u]=++idx;
        arr[id[u]]=arr[id[fa]]+1;
        for(int v:adj[u])
            if(v!=fa) tr[v].p=u,build(v,u);
        ed[u]=idx;
    }

    #undef lch
    #undef rch
    #undef wch

} lct;

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    getlca(1, -1);
    lct.build(1, 0);
    sgt.build(1, 1, n);
    while(m--) {
        int op,x,y;
        cin>>op>>x;
        if(op==1) lct.access(x);
        else if(op==2) {
            cin>>y;
            int p=lca(x,y);
            cout<<  sgt.query(1, id[x], id[x])+
                    sgt.query(1, id[y], id[y])-2*
                    sgt.query(1, id[p], id[p])+1
                <<  endl;
        }
        else cout<<sgt.query(1, id[x], ed[x])<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}