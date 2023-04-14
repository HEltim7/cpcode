#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e3+10;
int a[N],b[N],ida[N],idb[N],sz[N*2],idx;
vector<int> vec[N*2];

template<typename cap,int vertex,int edge> struct Flow {
    constexpr static int N=vertex,M=edge;
    constexpr static cap INF=cap(1)<<(8*sizeof(cap)-2);
    int e[M],ne[M],idx;
    int h[N],q[N],arc[N],d[N];
    cap f[M];
    int S,T=vertex-1;

    void add_edge(int a,int b,cap c) {
        e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
        e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
    }

    cap dfs(int u,cap lim) {
        if(u==T) return lim;
        cap flow=0;
        for(int i=arc[u];~i&&flow<lim;i=ne[i]){
            int v=e[i];
            arc[u]=i;
            if(f[i]&&d[v]==d[u]+1){
                cap t=dfs(v,min(f[i],lim-flow));
                if(!t) d[v]=-1;
                f[i]-=t,f[i^1]+=t,flow+=t;
            }
        }
        return flow;
    }

    bool bfs() {
        memset(d,-1,sizeof d);
        q[0]=S,arc[S]=h[S],d[S]=0;
        int hh=0,tt=1;
        while(hh<tt) {
            int ver=q[hh++];
            for(int i=h[ver];~i;i=ne[i]) {
                int t=e[i];
                if(f[i]&&d[t]==-1) {
                    d[t]=d[ver]+1;
                    arc[t]=h[t];
                    if(t==T) return 1;
                    q[tt++]=t;
                }
            }
        }
        return 0;
    }

    cap maxflow() {
        cap F=0,flow=0;
        while(bfs()) while(flow=dfs(S,INF)) F+=flow;
        return F;
    }

    void init() {
        idx=0;
        memset(h, -1, sizeof h);
    }

    Flow() { init(); }
};
Flow<int, 3*N, N*N> flow;

void dfs(int u,int arr[],int id[]) {
    if(id[u]) return;
    id[u]=idx;
    sz[idx]++;
    dfs(arr[u],arr,id);
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) if(!ida[i]) idx++,dfs(i,a,ida);
    int t=idx;
    for(int i=1;i<=n;i++) if(!idb[i]) idx++,dfs(i,b,idb);
    
    for(int i=1;i<=t;i++) if(sz[i]>1) flow.add_edge(flow.S, i, sz[i]-1);
    for(int i=1;i<=n;i++) flow.add_edge(ida[i], idx+i, 1);
    for(int i=1;i<=n;i++) flow.add_edge(idx+i, idb[i], 1);
    for(int i=t+1;i<=idx;i++) if(sz[i]>1) flow.add_edge(i, flow.T, sz[i]-1);
    flow.maxflow();
    vector<int> res;
    for(int i=0;i<flow.idx;i+=2) {
        int u=flow.e[i]-idx;
        if(u>=1&&u<=n) {
            if(flow.f[i^1]) res.push_back(u);
            else {
                vec[ida[u]].push_back(u);
                vec[idb[u]].push_back(u);
            }
        }
    }
    for(int i=1;i<=idx;i++) {
        vec[i].pop_back();
        for(auto x:vec[i]) res.push_back(x);
    }
    cout<<res.size()<<endl;
    for(auto x:res) cout<<x<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}