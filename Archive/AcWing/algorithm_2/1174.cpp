#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e4+10;
vector<int> adj[N],stk;
int dfn[N],low[N],id[N],sz[N],scc_cnt,tsp;
bool ins[N];
int oud[N];

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
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++) for(int v:adj[i]) oud[id[i]]+=id[i]!=id[v];
    
    int cnt=0,ans=0;
    for(int i=1;i<=scc_cnt;i++) if(!oud[i]) cnt++,ans+=sz[i];
    cout<<ans*(cnt==1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}