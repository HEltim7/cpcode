#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;
constexpr int N=2e5+10,INF=1e9;
vector<int> adj[N];
vector<TIII> edg;
int n,m,ind[N];

namespace scc {
    int dfn[N],low[N],id[N],sz[N],scc_cnt,tsp;
    vector<int> stk;
    bool ins[N];

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

    void init(int n) {
        if(tsp) {
            scc_cnt=tsp=0;
            for(int i=1;i<=n;i++) dfn[i]=sz[i]=0;
        }
        for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    }
} using scc::id,scc::sz,scc::scc_cnt;

bool check(int val) {
    for(int i=1;i<=n;i++) {
        ind[i]=0;
        adj[i].clear();
    }

    for(auto &[u,v,w]:edg) {
        adj[u].push_back(v);
        if(w<=val) adj[v].push_back(u);
    }
    scc::init(n);

    for(int i=1;i<=n;i++)
        for(int v:adj[i]) 
            if(id[v]!=id[i]) ind[id[v]]++;

    int cnt=0;
    for(int i=scc_cnt;i>=1;i--) if(ind[i]==0) cnt++;
    return cnt==1;
}

void solve() {
    cin>>n>>m;
    edg.resize(m);
    for(auto &[u,v,w]:edg) cin>>u>>v>>w;
    
    int l=0,r=INF+1;
    while(l<r) {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l==INF+1) cout<<-1<<endl;
    else cout<<l<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}