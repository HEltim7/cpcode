#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
vector<pair<int,int>> adj[N],g[N];
vector<int> stk;
int dfn[N],low[N],id[N],sz[N],scc_cnt,tsp;
bool ins[N];
int dp[N];

void tarjan(int u) {
    dfn[u]=low[u]=++tsp;
    stk.push_back(u),ins[u]=1;
    for(auto [v,w]:adj[u]) {
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
        int t,u,v;
        cin>>t>>u>>v;
        if(t==1) adj[u].emplace_back(v,0),adj[v].emplace_back(u,0);
        else if(t==2) adj[u].emplace_back(v,1);
        else if(t==3) adj[v].emplace_back(u,0);
        else if(t==4) adj[v].emplace_back(u,1);
        else adj[u].emplace_back(v,0);
    }
    for(int i=1;i<=n;i++) adj[0].emplace_back(i,1);
    for(int i=0;i<=n;i++) if(!dfn[i]) tarjan(i);

    bool inf=0;
    for(int i=0;i<=n;i++) 
        for(auto [v,w]:adj[i]) 
            if(id[i]!=id[v])
                g[id[i]].emplace_back(id[v],w);
            else if(w) inf=1;

    LL ans=0;
    dp[scc_cnt]=0;
    for(int i=scc_cnt;i>=1;i--) {
        ans+=1LL*dp[i]*sz[i];
        for(auto [v,w]:g[i]) 
            dp[v]=max(dp[v],dp[i]+w);
    }

    cout<<(inf?-1:ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}