#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10,INF=1e9;
vector<pair<int,int>> adj[N];
bool mark[N];
int dis[N];

void bfs(int n) {
    queue<int> q;
    q.push(n);
    for(int i=1;i<n;i++) dis[i]=INF;
    while(q.size()) {
        int u=q.front();
        q.pop();
        if(mark[u]) continue;
        mark[u]=1;
        for(auto [w,v]:adj[u]) dis[v]=min(dis[v],dis[u]+1),q.push(v);
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(w,v);
        adj[v].emplace_back(w,u);
    }
    bfs(n);
    
    int ans=INF;
    if(dis[1]==n-1&&m+1==n) for(auto [w,v]:adj[1]) ans=min(ans,w+dis[v]);
    else ans=dis[1];
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}