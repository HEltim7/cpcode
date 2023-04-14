#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
vector<int> adj[N],adjj[N],stk;
int dfn[N],low[N],id[N],sz[N],scc_cnt,tsp;
bool ins[N],mark[N];
int f[N],g[N];

void tarjan(int u) {
    dfn[u]=low[u]=++tsp;
    stk.push_back(u),ins[u]=1;
    for(int v:adj[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]) {
        scc_cnt++;
        int x;
        do {
            x=stk.back();
            stk.pop_back();
            ins[x]=0;
            id[x]=scc_cnt;
            sz[scc_cnt]++;
        } while(x!=u);
    }
}

void solve() {
    int n,m,mod;
    cin>>n>>m>>mod;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=scc_cnt;i++) f[i]=sz[i],g[i]=1;

    for(int i=1;i<=n;i++)
        for(int v:adj[i]) 
            if(id[i]!=id[v]) 
                adjj[id[i]].push_back(id[v]);

    for(int i=1;i<=scc_cnt;i++) {
        adj[i].clear();
        for(int v:adjj[i]) {
            if(!mark[v]) {
                adj[i].push_back(v);
                mark[v]=1;
            }
        }
        for(int v:adj[i]) mark[v]=0;
    }

    int maxx=0,cnt=0;
    for(int i=1;i<=scc_cnt;i++) f[i]=sz[i],g[i]=1;
    for(int i=scc_cnt;i>=1;i--) {
        maxx=max(maxx,f[i]);
        for(int v:adj[i]) {
            if(f[v]<f[i]+sz[v]) {
                f[v]=f[i]+sz[v];
                g[v]=g[i];
            }
            else if(f[v]==f[i]+sz[v]) g[v]=(g[v]+g[i])%mod;
        }
    }

    for(int i=1;i<=scc_cnt;i++) if(f[i]==maxx) cnt=(cnt+g[i])%mod;
    cout<<maxx<<endl<<cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}