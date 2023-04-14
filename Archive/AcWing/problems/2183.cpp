#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=1e3+10,M=1e4+10,INF=0x3f3f3f3f;
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

inline bool check(int row,int col){
    return row>=1&&row<=n&&col>=1&&col<=m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    cin>>n>>m;
    S=0,T=N-1;
    int tot=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int in;
            cin>>in;
            tot+=in;
            if(i+j&1) add(i*m+j,T,in);
            else{
                add(S,i*m+j,in);
                int mvr[]={-1,1,0,0};
                int mvc[]={0,0,1,-1};
                for(int k=0;k<4;k++)
                    if(check(i+mvr[k],j+mvc[k]))
                        add(i*m+j,(i+mvr[k])*m+j+mvc[k],INF);
            }
        }
    cout<<tot-dinic()<<endl;
    return 0;
}