#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e3+10;
constexpr LL INF=1e18;
vector<pair<int,int>> adj[N],nrg[N];
LL dp[N],pre[N];

namespace scc {
    int dfn[N],low[N],id[N],sz[N],scc_cnt,tsp;
    vector<int> stk;
    bool ins[N];

    void tarjan(int u) {
        dfn[u]=low[u]=++tsp;
        stk.push_back(u),ins[u]=1;
        for(auto [v,_]:adj[u]) {
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

    void init(int n) {
        if(tsp) {
            scc_cnt=tsp=0;
            for(int i=1;i<=n;i++) dfn[i]=sz[i]=0;
        }
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    }
} using scc::id,scc::sz,scc::scc_cnt;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            int in;
            cin>>in;
            if(in>0) adj[i].emplace_back(j,in);
            else adj[j].emplace_back(i,-in);
        }
    }

    scc::init(n);
    for(int i=1;i<=n;i++) 
        for(auto [v,l]:adj[i]) 
            nrg[id[v]].emplace_back(id[i],l);

    for(int i=1;i<=scc_cnt;i++) dp[i]=INF;
    dp[scc_cnt]=0;

    for(int i=scc_cnt-1;i>=1;i--) {
        pre[i+1]=dp[i+1];
        for(int j=i+2;j<=scc_cnt;j++)
            pre[j]=min(pre[j-1],dp[j]);
        for(auto [v,l]:nrg[i]) {
            dp[i]=min(dp[i],pre[v]+l);
        }
    }

    cout<<dp[1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}