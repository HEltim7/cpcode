#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=1e4+10,M=2e5+10,INF=0x3f3f3f3f;
int e[M],ne[M],f[M],idx;
int h[N],d[N],arc[N],q[N];
int n,m,S,T;

inline void add(int a,int b,int c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
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

bool bfs(){
    memset(d,-1,sizeof d);
    int hh=0,tt=1;
    q[0]=S,d[S]=0,arc[S]=h[S];
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

int dinic(){
    int F=0,flow;
    while(bfs()) while(flow=dfs(S,INF)) F+=flow;
    return F;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    cin>>n>>m>>S>>T;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<dinic();
    return 0;
}