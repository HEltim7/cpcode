#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
vector<pair<int,int>> adj[N*N];
int id[N*4];
bool vis[N*N];
LL dist[N*N],cost[N*4][N*4],dp[N*4][N*4];

void dijkstra(int s) {
    using PLI=pair<LL,int>;
    priority_queue<PLI,vector<PLI>,greater<>> heap;
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[s]=0;
    heap.emplace(dist[s],s);
    while(heap.size()) {
        auto [d,u]=heap.top();
        heap.pop();
        if(vis[u]) continue;
        for(auto [v,l]:adj[u]) {
            if(d+l<dist[v]) {
                dist[v]=d+l;
                heap.emplace(dist[v],v);
            }
        }
    }
}

void solve() {
    int h,w;
    cin>>h>>w;

    LL ans=0;
    auto getid=[&](int r,int c) {
        return (r-1)*w+c;
    };

    for(int i=1;i<h;i++)
        for(int j=1;j<=w;j++) {
            int in;
            cin>>in;
            ans+=in;
            int u=getid(i,j),v=getid(i+1,j);
            adj[u].emplace_back(v,in);
            adj[v].emplace_back(u,in);
        }

    for(int i=1;i<=h;i++)
        for(int j=1;j<w;j++) {
            int in;
            cin>>in;
            ans+=in;
            int u=getid(i,j),v=getid(i,j+1);
            adj[u].emplace_back(v,in);
            adj[v].emplace_back(u,in);
        }
    
    int idx=0;
    for(int j=2;j<=w-1;j++) id[++idx]=getid(1,j);
    for(int i=2;i<=h-1;i++) id[++idx]=getid(i,w);
    for(int j=w-1;j>=2;j--) id[++idx]=getid(h,j);
    for(int i=h-1;i>=2;i--) id[++idx]=getid(i,1);

    for(int i=1;i<=idx;i++) {
        dijkstra(id[i]);
        for(int j=1;j<=idx;j++) cost[i][j]=dist[id[j]];
    }

    for(int len=2;len<=idx;len+=2) {
        for(int i=1,j=i+len-1;j<=idx;i++,j++) {
            dp[i][j]=dp[i+1][j-1]+cost[i][j];
            for(int k=i+1;k<=j;k+=2)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }

    cout<<ans+dp[1][idx];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}