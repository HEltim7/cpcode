#include <vector>
#include <cassert>
#include <cstring>
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
#define lowbit(x) (x&(-x))
using LL=long long;
constexpr int M=17,N=(1<<M)+10;

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
        while(bfs()) F+=dfs(S,INF);
        return F;
    }

    void init() {
        idx=0;
        memset(h, -1, sizeof h);
    }

    Flow() { init(); }
};

int arr[N],val[N],lid[N],rid[N],rpos[N],idx=0;
bool mark[N];
Flow<int, N, N*5> flow;

void solve() {
    int n;
    cin>>n;
    int offset=n/2;
    for(int i=1;i<=n;i+=2) cin>>arr[i],mark[arr[i]]=1;
    for(int i=0;i<n;i++) if(!mark[i]) val[++idx]=i,lid[i]=idx;
    for(int i=1;i<=offset;i++) flow.add_edge(flow.S, i, 1);
    for(int i=1;i<=offset;i++) flow.add_edge(i+offset, flow.T, 1);

    for(int i=2;i<=n;i+=2) rid[i]=offset+i/2,rpos[rid[i]]=i;
    for(int i=2;i<n;i+=2) {
        int x=arr[i-1]^arr[i+1];
        int y=lowbit(x);
        x-=y;
        x=arr[i-1]^x;
        y=arr[i-1]^y;
        
        flow.add_edge(lid[x], rid[i], 1);
        flow.add_edge(lid[y], rid[i], 1);
    }

    for(int i=0;i<__lg(n);i++) {
        int x=arr[n-1]^(1<<i);
        flow.add_edge(lid[x], rid[n], 1);
    }

    assert(flow.maxflow()==n/2);

    for(int i=0;i<flow.idx;i+=2) {
        int t=flow.e[i],s=flow.e[i^1];
        if(flow.f[i^1]&&s>=1&&s<=offset&&t>offset&&t<=n) {
            debug(s,t,val[s],rpos[t]);
            arr[rpos[t]]=val[s];
        }
    }
    for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}