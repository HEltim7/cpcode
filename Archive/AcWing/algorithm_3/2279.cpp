#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

#define endl '\n'
const int N=110,M=810,INF=0x3f3f3f3f;
const double eps=1e-8;
int ne[M],e[M],w[M],idx;
int h[N],d[N],arc[N],q[N];
int n,m,S,T;
double f[M];

inline void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,w[idx]=c,ne[idx]=h[b],h[b]=idx++;
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

double dinic(double mid){
    double sum=0,F=0,flow=0;
    for(int i=0;i<idx;i+=2){
        if(w[i]<=mid) {
            sum+=w[i]-mid;
            f[i]=f[i^1]=0;
        }
        else f[i]=f[i^1]=w[i]-mid;
    }
    while(bfs()){
        while(flow=dfs(S,INF)) 
            F+=flow;
    }
    return sum+F;
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
    double l=0,r=1e7;
    while(r-l>eps){
        double mid=(l+r)/2;
        if(dinic(mid)<0) r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(2)<<l;
    return 0;
}