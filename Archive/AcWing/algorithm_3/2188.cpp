#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=210,M=3e4+10,INF=0x3f3f3f3f;
int ne[M],f[M],e[M],l[M],idx;
int h[N],d[N],arc[N],q[N],sum[N];
int n,m,S,T;

inline void add(int a,int b,int c,int d){
    e[idx]=b,f[idx]=d-c,l[idx]=c,ne[idx]=h[a],h[a]=idx++;
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
    cin>>n>>m;
    S=0,T=n+1;
    while(m--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        add(a,b,c,d);
        sum[a]-=c,sum[b]+=c;
    }
    int total=0;
    for(int i=1;i<=n;i++){
        if(sum[i]>0) add(S,i,0,sum[i]) ,total+=sum[i];
        else if(sum[i]<0) add(i,T,0,-sum[i]);
    }
    if(dinic()<total) cout<<"NO";
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<idx;i+=2)
            if(e[i]<=n&&e[i^1]) cout<<f[i^1]+l[i]<<endl;
    }
    return 0;
}