#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
vector<int> adj[N],stk;
int dfn[N],low[N],id[N],sz[N],scc_cnt,tsp;
bool ins[N];
int ind[N],oud[N];

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
    int n;
    cin>>n;
    for(int i=1,in;i<=n;i++)
        while(cin>>in&&in) 
            adj[i].push_back(in);

    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=n;i++) 
        for(int v:adj[i]) {
            ind[id[v]]+=id[i]!=id[v];
            oud[id[i]]+=id[i]!=id[v];
        }
    
    int in=0,out=0;
    for(int i=1;i<=scc_cnt;i++) in+=ind[i]==0,out+=oud[i]==0;
    cout<<in<<endl;
    if(scc_cnt==1) cout<<0;
    else cout<<max(in,out);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}