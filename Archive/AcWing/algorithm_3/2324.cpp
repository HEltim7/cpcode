#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'

const int N=2e2+10,M=1e4+10,INF=0x3f3f3f3f;
int ne[M],e[M],idx;
int h[N],arc[N],d[N],q[N];
int n,m,S,T;
double f[M];
double eps=1e-6;

pair<int,int> edge[M];

inline void add(int a,int b,double c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}

double dfs(int id,double lim){
    if(id==T) return lim;
    double flow=0;
    for(int i=arc[id];~i&&flow<lim;i=ne[i]){
        int ver=e[i];
        arc[id]=i;
        if(d[ver]==d[id]+1&&f[i]>eps){
            double t=dfs(ver,min(f[i],lim-flow));
            if(t<eps) d[ver]=-1;
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
            if(d[t]==-1&&f[i]>eps){
                d[t]=d[ver]+1;
                arc[t]=h[t];
                if(t==T) return 1;
                q[tt++]=t;
            }
        }
    }
    return 0;
}

double dinic(){
    double F=0,flow=0;
    while(bfs()) while(flow=dfs(S,INF)>eps) F+=flow;
    return F;
}

void build(double mid){

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>edge[i].first>>edge[i].second;

    double l=0,r=m;
    while (l<r)
    {
        double mid=(l+r)/2;
        build(mid);
        
    }
    
}