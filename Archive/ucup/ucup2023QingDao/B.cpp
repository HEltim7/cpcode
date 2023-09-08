#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e5+10,M=__lg(N);
int fa[N][M+1],dep[N];
LL cost[N],dis[N][M+1];
vector<pair<int,LL>> adj[N];

void lca_init(int u,int p) {
    dep[u]=dep[p]+1;
    for(auto [v,w]:adj[u]) {
        if(v==p) continue;
        fa[v][0]=u;
        dis[v][0]=w;
        for(int i=1;i<=M;i++) {
            fa[v][i]=fa[fa[v][i-1]][i-1];
            dis[v][i]=dis[fa[v][i-1]][i-1]+dis[v][i-1];
        }
        lca_init(v,u);
    }
}

int lca(int u,int v) {
    if(dep[u]<dep[v]) swap(u,v);
    for(int k=M;~k;k--)
        if(dep[fa[u][k]]>=dep[v])
            u=fa[u][k];
    if(u==v) return u;
    for(int k=M;~k;k--)
        if(fa[u][k]!=fa[v][k])
            u=fa[u][k],v=fa[v][k];
    return fa[u][0];
}

LL get_len(int u,int p) {
    LL res=0;
    if(dep[u]<dep[p]) swap(u,p);
    for(int k=M;~k;k--)
        if(dep[fa[u][k]]>=dep[p])
            res+=dis[u][k],u=fa[u][k];
    return res;
}

bool red[N];
void init_cost(int u,int fa,LL up) {
    if(red[u]) up=0;
    cost[u]=up;
    for(auto [v,w]:adj[u]) {
        if(v!=fa) {
            init_cost(v, u, up+w);
        }
    }
}

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) adj[i].clear();
    memset(red, 0, sizeof(bool)*(n+1));
    for(int i=1,in;i<=m;i++) cin>>in,red[in]=1;
    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    init_cost(1, 0, 0);
    lca_init(1, 0);

    while(q--) {
        int k;
        cin>>k;
        vector<pair<LL,int>> key(k);
        for(auto &[cos,u]:key) cin>>u,cos=cost[u];
        sort(key.begin(),key.end(),greater<>());
        key.emplace_back(0,0);
        auto [ans,p]=key.front();
        LL max_len=0;
        for(int i=0;i<k;i++) {
            int u=key[i].second;
            int lc=lca(p,u);
            max_len=max(max_len+get_len(p, lc),get_len(u, lc));
            ans=min(ans,max(max_len,key[i+1].first));
            p=lc;
        }
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}