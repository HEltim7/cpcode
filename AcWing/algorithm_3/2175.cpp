#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'

const int N=110,M=5210,INF=0x3f3f3f3f;
int n,m,S,T;
int e[M],ne[M],f[M],idx;
int h[N],arc[N],d[N],q[N];

inline void add(int a,int b,int c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}

bool bfs(){
    memset(d,-1,sizeof d);
    q[0]=S,d[S]=0,arc[S]=h[S];
    int hh=0,tt=1;
    while(hh<tt){
        int t=q[hh++];
        for(int i=h[t];~i;i=ne[i]){
            int ver=e[i];
            if(d[ver]==-1&&f[i]){
                d[ver]=d[t]+1;
                arc[ver]=h[ver];
                if(ver==T) return 1;
                q[tt++]=ver;
            }
        }
    }
    return 0;
}

int dfs(int id,int lim){
    if(id==T) return lim;
    int flow=0;
    for(int i=arc[id];~i&&flow<lim;i=ne[i]){
        arc[id]=i;
        int ver=e[i];
        if(d[ver]==d[id]+1&&f[i]){
            int t=dfs(ver,min(f[i],lim-flow));
            if(!t) d[ver]=-1;
            f[i]-=t,f[i^1]+=t,flow+=t;
        }
    }
    return flow;
}

int dinic(){
    int F=0,flow;
    while(bfs()) while(flow=dfs(S,INF)) F+=flow;
    return F;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>m>>n;
    S=0,T=n+1;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++) add(S,i,1);
    for(int i=m+1;i<=n;i++) add(i,T,1);
    int a,b;
    while(cin>>a>>b&&a!=-1) add(a,b,1);
    cout<<dinic()<<endl;

    for(int i=0;i<idx;i+=2)
        if(e[i]>m&&e[i]<=n&&!f[i])
            cout<<e[i^1]<<' '<<e[i]<<endl;

    return 0;
}