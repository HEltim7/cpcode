#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=50010,M=(N+125010)*2,INF=2147483647;
int e[M],ne[M],f[M],idx;
int h[N],d[N],arc[N],q[N],sum[N];
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
    q[0]=S,arc[S]=h[S],d[S]=0;
    int hh=0,tt=1;
    while(hh<tt){
        int ver=q[hh++];
        for(int i=h[ver];~i;i=ne[i]){
            int t=e[i];
            if(d[t]==-1&&f[i]){
                d[t]=d[ver]+1;
                arc[t]=h[t];
                if(t==T) return 1;
                q[tt++]=t;
            }
        }
    }
    return  0;
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
    int s,t;
    cin>>n>>m>>s>>t;
    S=0,T=n+1;
    while(m--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        add(a,b,d-c);
        sum[a]-=c,sum[b]+=c;
    }
    int total=0;
    for(int i=1;i<=n;i++){
        if(sum[i]>0) add(S,i,sum[i]),total+=sum[i];
        else if(sum[i]<0) add(i,T,-sum[i]);
    }
    add(t,s,INF);
    if(dinic()<total) cout<<"No Solution";
    else{
        int res=f[idx-1];
        f[idx-1]=f[idx-2]=0;
        S=t,T=s;
        cout<<res-dinic();
    }
    return 0;
}