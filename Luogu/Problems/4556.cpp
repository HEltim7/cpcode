#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10,M=20,INF=0x3f3f3f3f;

struct Node {
    int l,r;
    int ch[2];
    int cnt;
} tr[4*20*N];
int idx;
int fa[N][M+1],dep[N];
int ans[N];
vector<int> adj[N];

void getlca(int u,int p){
    for(auto s:adj[u]){
        if(s==p) continue;
        dep[s]=dep[u]+1;
        fa[s][0]=u;
        for(int i=1;i<=M;i++)
            fa[s][i]=fa[fa[s][i-1]][i-1];
        getlca(s,u);
    }
}

int lca(int a,int b){
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

void pushup(int u) {
    assert(tr[u].ch[0]||tr[u].ch[1]);
    tr[u].cnt=-INF;
    if(tr[u].ch[0]) tr[u].cnt=max(tr[u].cnt,tr[tr[u].ch[0]].cnt);
    if(tr[u].ch[1]) tr[u].cnt=max(tr[u].cnt,tr[tr[u].ch[1]].cnt);
}

void modify(int u,int p,int v) {
    if(tr[u].l==tr[u].r) {
        tr[u].cnt+=v;
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    if(p<=mid) {
        if(!tr[u].ch[0]) tr[u].ch[0]=++idx,tr[idx]={tr[u].l,mid};
        modify(tr[u].ch[0], p, v);
    }
    else {
        if(!tr[u].ch[1]) tr[u].ch[1]=++idx,tr[idx]={mid+1,tr[u].r};
        modify(tr[u].ch[1], p, v);
    }
    pushup(u);
}

void merge(int u,int v) {
    if(!tr[u].ch[0]&&!tr[u].ch[1]&&!tr[v].ch[0]&&!tr[v].ch[1]) tr[u].cnt+=tr[v].cnt;
    else {
        for(int z=0;z<=1;z++) {
            if(!tr[u].ch[z]&&tr[v].ch[z]) tr[u].ch[z]=tr[v].ch[z];
            else if(tr[u].ch[z]&&tr[v].ch[z]) merge(tr[u].ch[z],tr[v].ch[z]);
        }
        pushup(u);
    }
}

int query(int u) {
    if(tr[u].cnt==0) return 0;
    if(!tr[u].ch[0]&&!tr[u].ch[1]) return tr[u].l;
    if(!tr[u].ch[0]) return query(tr[u].ch[1]);
    if(!tr[u].ch[1]) return query(tr[u].ch[0]);
    if(tr[tr[u].ch[0]].cnt>=tr[tr[u].ch[1]].cnt) return query(tr[u].ch[0]);
    return query(tr[u].ch[1]);
}

void dfs(int u) {
    for(int v:adj[u]) if(v!=fa[u][0]) dfs(v);
    ans[u]=query(u);
    if(fa[u][0]) merge(fa[u][0],u);
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) tr[++idx]={1,N-1};
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dep[1]=1;
    getlca(1, -1);
    while(m--) {
        int x,y,z;
        cin>>x>>y>>z;
        int p=lca(x,y);
        modify(x, z, 1);
        modify(y, z, 1);
        modify(p, z, -1);
        if(fa[p][0]) modify(fa[p][0], z, -1);
    }
    dfs(1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}