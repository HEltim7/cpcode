#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=210,M=1e5+10,INF=0x3f3f3f3f;
int e[M],ne[M],f[M],idx;
int h[N],q[N],arc[N],d[N];
int n,m,S,T;

inline void add(int a,int b,int c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}

int dfs(int id,int lim){
    if(id==T) return lim;
    int flow=0;
    for(int i=arc[id];~i&&flow<lim;i=ne[i]){
        int ver=e[i];
        arc[id]=i;
        if(f[i]&&d[ver]==d[id]+1){
            int t=dfs(ver,min(f[i],lim-flow));
            if(!t) d[ver]=-1;
            f[i]-=t,f[i^1]+=t,flow+=t;
        }
    }
    return flow;
}

bool bfs(){
    memset(d,-1,sizeof d);
    q[0]=S,arc[S]=h[S],d[S]=0;
    int hh=0,tt=1;
    while(hh<tt){
        int ver=q[hh++];
        for(int i=h[ver];~i;i=ne[i]){
            int t=e[i];
            if(f[i]&&d[t]==-1){
                d[t]=d[ver]+1;
                arc[t]=h[t];
                if(t==T) return 1;
                q[tt++]=t;
            }
        }
    }
    return 0;
}

int dinic(){
    int F=0,flow=0;
    while(bfs()) while(flow=dfs(S,INF)) F+=flow;
    return F;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    S=0,T=N-1;
    int n,m;
    int a[N],b[N];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],add(S,i,1);
    cin>>m;
    for(int i=1;i<=m;i++) cin>>b[i],add(i+n,T,1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(abs(a[i]-b[i])<=1)
                add(i,j+n,1);
    cout<<dinic();
    return 0;
}