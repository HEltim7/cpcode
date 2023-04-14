#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
using PLL=pair<LL,LL>;
constexpr int N=2e5+10;
constexpr LL INF=2e18;
vector<PLL> adj[N];
bool mark[N],ok[N],valid;
LL ans[N];
PLL expr[N];
int id[N],idx;
LL X[N];

PLL get(PLL x,LL val) {
    x.first*=-1;
    x.second=val-x.second;
    return x;
}

LL check(PLL x,PLL y,LL val) {
    auto [sx,bx]=x;
    auto [sy,by]=y;
    if(sx+sy==0) {
        if(bx+by!=val) return INF;
        else return 0;
    }
    else {
        return (val-bx-by)/(sx+sy);
    }
}

void dfs(int u,int p) {
    debug(u,expr[u]);
    mark[u]=1;
    id[u]=idx;
    for(auto [v,w]:adj[u]) {
        if(v==p) continue;
        if(mark[v]) {
            LL res=check(expr[u],expr[v],w);
            if(res==INF) valid=0;
            else if(!ok[id[u]]) {
                X[id[u]]=res;
                if(res) ok[id[u]]=1;
            }
        }
        else {
            expr[v]=get(expr[u], w);
            dfs(v,u);
        }
    }
}

void solve() {
    valid=1;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) mark[i]=ok[i]=0,X[i]=0,id[i]=0,expr[i]={},ans[i]=0;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }

    idx=0;
    for(int i=1;i<=n;i++) {
        if(!mark[i]) {
            expr[i]={1,0};
            idx++;
            dfs(i,0);
        }
    }
    if(valid) {
        for(int i=1;i<=n;i++) ans[i]=expr[i].first*X[id[i]]+expr[i].second;
        for(int i=1;i<=n;i++) {
            for(auto [v,w]:adj[i]) {
                if(ans[i]+ans[v]!=w) {
                    cout<<-1<<endl;
                    return;
                }
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    }
    else cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}