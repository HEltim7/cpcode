#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e4+10,M=2e3+10;

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
Flow<int, N*2, N*200> flow;

using Box=tuple<int,int,int,int>;
vector<int> grid[M][M];
Box box[N];
int aera[N];

int cal(const Box &x,const Box &y) {
    const auto &[d1,l1,u1,r1]=x;
    const auto &[d2,l2,u2,r2]=y;
    return max(min(u1,u2)-max(d1,d2),0)*max(min(r1,r2)-max(l1,l2),0);
}

void solve() {
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        box[i]=Box(x1,y1,x2,y2);
        aera[i]=(x2-x1)*(y2-y1);
        grid[x1][y1].emplace_back(i);
    }

    flow.init();
    for(int i=1;i<=n;i++) flow.add_edge(flow.S, i, 1);
    for(int i=1;i<=m;i++) flow.add_edge(i+n, flow.T, 1);
    
    for(int i=1;i<=n;i++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        Box cur{x1,y1,x2,y2};
        for(int x=max(0,x1-4);x<=x2;x++)
            for(int y=max(0,y1-4);y<=y2;y++)
                for(int id:grid[x][y])
                    if(cal(cur,box[id])*2>=aera[id])
                        flow.add_edge(i, id+n, 1);
    }

    cout<<flow.maxflow()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}