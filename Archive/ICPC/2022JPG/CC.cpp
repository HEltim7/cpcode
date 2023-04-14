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

template<typename cap,typename cost,int vertex,int edge> struct Flow {
    constexpr static int N=vertex,M=edge,INF=cap(1)<<(8*sizeof(cap)-2);
    int ne[M],e[M],idx;
    int h[N],q[N],pre[N];
    int S=0,T=N-1;
    cap f[M],mf[N];
    cost d[N],w[M];
    bool inq[N];

    void add_edge(int a,int b,cap c,cost d) {
        e[idx]=b,f[idx]=c,w[idx]=d,ne[idx]=h[a],h[a]=idx++;
        e[idx]=a,f[idx]=0,w[idx]=-d,ne[idx]=h[b],h[b]=idx++;
    }

    bool spfa() {
        memset(d,0x3f,sizeof d);
        memset(mf,0,sizeof mf);
        int hh=0,tt=1;
        q[0]=S,d[S]=0,mf[S]=INF;
        while(hh!=tt) {
            int u=q[hh++];
            if(hh==N) hh=0;
            inq[u]=0;

            for(int i=h[u];~i;i=ne[i]) {
                int v=e[i];
                if(f[i]&&d[v]>d[u]+w[i]) {
                    d[v]=d[u]+w[i];
                    pre[v]=i;
                    mf[v]=min(mf[u],f[i]);
                    if(!inq[v]){
                        q[tt++]=v;
                        if(tt==N) tt=0;
                        inq[v]=1;
                    }
                }
            }
        }
        return mf[T]>0;
    }

    pair<cap,cost> maxflow() {
        cap flow=0; cost val=0;
        while(spfa()) {
            flow+=mf[T],val+=mf[T]*d[T];
            for(int i=T;i!=S;i=e[pre[i]^1]) {
                f[pre[i]]-=mf[T];
                f[pre[i]^1]+=mf[T];
            }
        }
        return {flow,val};
    }

    void init() {
        idx=0;
        memset(h, -1, sizeof h);
    }

    Flow() { init(); }
};
Flow<int,LL,4*N,2*(2*N*2*N+4*N)> flow;

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

    for(int i=1;i<=idx;i+=2) flow.add_edge(flow.S, i, 1, 0);
    for(int i=2;i<=idx;i+=2) flow.add_edge(i, flow.T, 1, 0);
    for(int i=1;i<=idx;i+=2) {
        dijkstra(id[i]);
        for(int j=2;j<=idx;j+=2) flow.add_edge(i, j, 1, dist[id[j]]);
    }

    cout<<ans+flow.maxflow().second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}