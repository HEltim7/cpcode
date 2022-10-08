#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=510,INF=0x3f3f3f3f;
int diss[N],dist[N],mind[N];
bool vis[N];
int edge[N][N];
int n,m;

void bfs(int u,int dis[]) {
    queue<pair<int,int>> q;
    q.push({u,0});
    memset(vis+1, 0, sizeof (bool)*n);
    vis[u]=1;
    
    while(q.size()) {
        auto [u,step]=q.front();
        dis[u]=step;
        q.pop();
        for(int v=1;v<=n;v++)
            if(!vis[v]&&edge[u][v]!=INF)
                vis[v]=1,q.push({v,step+1});
    }
}

int bfs(int u) {
    queue<pair<int,int>> q;
    q.push({u,1});
    memset(vis+1, 0, sizeof (bool)*n);
    vis[u]=1;
    
    int res=INF;
    while(q.size()) {
        auto[u,step]=q.front();
        res=min(res,diss[u]+dist[u]+step);
        q.pop();
        for(int v=1;v<=n;v++)
            if(!vis[v]&&edge[u][v]!=INF)
                vis[v]=1,q.push({v,step+1});
    }
    return res+1;
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) edge[i][j]=INF;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edge[u][v]=min(edge[u][v],w);
        edge[v][u]=min(edge[v][u],w);
    }
    bfs(1,diss);
    bfs(n,dist);
    for(int i=1;i<=n;i++) mind[i]=bfs(i);

    LL ans=1e18;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(edge[i][j]!=INF) {
                int len=min(diss[i]+dist[j],dist[i]+diss[j])+1;
                ans=min(ans,len*1LL*edge[i][j]);
                ans=min(ans,min(mind[i],mind[j])*1LL*edge[i][j]);
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}