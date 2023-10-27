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
constexpr int N=505;

template<typename cap,int vertex,int edge> struct Flow {
    constexpr static int N=vertex,M=edge;
    constexpr static cap INF=cap(1)<<(8*sizeof(cap)-2);
    int e[M],ne[M],idx;
    int h[N],q[N],arc[N],d[N];
    cap f[M];
    int S,T=N-1;

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
Flow<int, N*2+10, (N*N+N*2)*2> flow;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) flow.add_edge(flow.S, i, 1);
    for(int i=1;i<=n;i++) flow.add_edge(i+n, flow.T, 1);

    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(gcd(a[i],b[j])==1) {
                flow.add_edge(i, j+n, 1);
            }
        }
    }

    if(flow.maxflow()==n) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}