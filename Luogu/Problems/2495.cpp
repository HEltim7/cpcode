#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=2.5e5+10,M=20,INF=0x3f3f3f3f;

vector<PII> adj[N],vtr[N];
int fa[N][M+1],cost[N][M+1],dep[N]={0,1};
int id[N],idx=0;
bool key[N];
LL dp[N];

void getlca(int u,int p){
    for(auto [v,w]:adj[u]){
        if(v==p) continue;
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        cost[v][0]=w;
        for(int i=1;i<=M;i++) {
            fa[v][i]=fa[fa[v][i-1]][i-1];
            cost[v][i]=min(cost[v][i-1],cost[fa[v][i-1]][i-1]);
        }
        getlca(v,u);
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

int cal(int u,int v) {
    if(dep[u]>dep[v]) swap(u,v);
    int res=INF;
    for(int k=M;~k;k--)
        if(dep[fa[v][k]]>=dep[u])
            res=min(res,cost[v][k]),v=fa[v][k];
    return res;
}

void relable(int u,int p) {
    id[u]=++idx;
    for(auto [v,w]:adj[u]) if(v!=p) relable(v,u);
}

int stk[N],top;
void build(vector<int> &x) {
    sort(x.begin(),x.end(),[](int x,int y){
        return id[x]<id[y];
    });

    auto clear=[](int x) {
        dp[x]=key[x]=0;
        vtr[x].clear();
    };

    auto add_edge=[](int u,int v) {
        vtr[u].emplace_back(v,cal(u,v));
    };

    clear(1);
    stk[top=0]=1;
    for(int u:x) {
        assert(u!=1);
        int lc=lca(u,stk[top]);
        if(lc!=stk[top]) {
            while(id[lc]<id[stk[top-1]]) 
                add_edge(stk[top-1],stk[top]),top--;
            if(id[lc]!=id[stk[top-1]]) 
                clear(lc),add_edge(lc,stk[top]),stk[top]=lc;
            else add_edge(lc,stk[top--]);
        }
        clear(u);
        stk[++top]=u;
        key[u]=1;
    }

    for(int i=0;i<top;i++) add_edge(stk[i],stk[i+1]);
}

void dfs(int u,int p) {
    for(auto [v,w]:vtr[u]) {
        if(v==p) continue;
        dfs(v,u);
        if(key[v]) dp[u]=dp[u]+w;
        else dp[u]=dp[u]+min(dp[v],w*1LL);
    }
}

void solve() {
    int n,m;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    getlca(1, -1);
    relable(1, -1);

    cin>>m;
    while(m--) {
        vector<int> cur;
        int k,u;
        cin>>k;
        for(int i=1;i<=k;i++) cin>>u,cur.push_back(u);
        build(cur);
        dfs(1,-1);
        cout<<dp[1]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}