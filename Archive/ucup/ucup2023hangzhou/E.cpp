#include <algorithm>
#include <array>
#include <cstring>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

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

constexpr int N=55;
Flow<int, N*N, N*N*N> flow;
int grid[N][N],mvr[]={1,-1,0,0},mvc[]={0,0,1,-1};
bool mark[N][N],side[N][N];
string ans[N*2];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1,idx=0;i<=n;i++) {
        cin>>ans[++idx];
        ans[idx]=" "+ans[idx];
        for(int j=1;j<=m;j++) {
            grid[i][j]=ans[idx][j*2-1]-'0';
        }
        cin>>ans[++idx];
        ans[idx]=" "+ans[idx];
    }

    int cnt=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            bool x=i==1||i==n;
            bool y=j==1||j==m;
            if(x&&y) mark[i][j]=grid[i][j]<3;
            else if(x||y) mark[i][j]=grid[i][j]<5;
            else mark[i][j]=grid[i][j]<8;
            cnt+=mark[i][j];
            if(x||y) side[i][j]=1;
        }
    }
    if(cnt&1) {
        cout<<"NO"<<endl;
        return;
    }
    debug(cnt);

    auto uni=[&](int x,int y) {
        return x*N+y;
    };
    auto dec=[&](int x) {
        int r=x/N;
        int c=x-r*N;
        return make_pair(r,c);
    };
    auto get=[&](int _) {
        auto [x,y]=dec(_);
        x=(x-1)*2+1;
        y=(y-1)*2+1;
        return make_pair(x,y);
    };
    auto check=[&](int x,int y) {
        return x>=1&&x<=n&&y>=1&&y<=m;
    };
    auto isok=[&](int x,int y,int r,int c) {
        if(x==1&&r==1||x==n&&r==n||y==1&&c==1||y==m&&c==m) return true;
        if(!side[x][y]&&!side[r][c]) return true;
        return false;
    };

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if((i+j)&1) {
                if(mark[i][j]) {
                    flow.add_edge(flow.S, uni(i, j), 1);
                    for(int k=0;k<4;k++) {
                        int x=i+mvr[k];
                        int y=j+mvc[k];
                        if(check(x,y)&&mark[x][y]&&isok(x, y, i, j)) {
                            flow.add_edge(uni(i,j), uni(x,y), 1);
                        }
                    }
                }
            }
            else {
                if(mark[i][j])
                    flow.add_edge(uni(i,j), flow.T, 1);
            }
        }
    }

    if(flow.maxflow()*2<cnt) {
        cout<<"NO"<<endl;
        return;
    }

    for(int i=1;i<=2*n-1;i++) {
        for(int j=1;j<=2*m-1;j++) {
            if(!isdigit(ans[i][j]))
                ans[i][j]='#';
        }
    }

    for(int i=0;i<flow.idx;i++) {
        int t=flow.e[i];
        int s=flow.e[i^1];
        auto [sx,sy]=dec(s);
        auto [tx,ty]=dec(t);
        debug(sx,sy,tx,ty);
        if(flow.f[i^1]&&check(sx,sy)&&check(tx,ty)&&((sx+sy)&1)) {
            auto [sr,sc]=get(s);
            auto [tr,tc]=get(t);
            if(sr==tr) ans[sr][(sc+tc)/2]='.';
            else ans[(sr+tr)/2][sc]='.';
        }
    }
    
    cout<<"YES"<<endl;
    for(int i=1;i<=2*n-1;i++) {
        for(int j=1;j<=2*m-1;j++) {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}