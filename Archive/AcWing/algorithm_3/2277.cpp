#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=210,M=1e5+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],w[M],idx;
int h[N],d[N],q[N],arc[N];
int n,m,S,T,K;

inline void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,w[idx]=c,ne[idx]=h[b],h[b]=idx++;
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
    return 0;
}

int dinic(){
    int F=0,flow;
    while(bfs()) while(flow=dfs(S,INF)) F+=flow;
    return F;
}

inline bool check(int mid){
    for(int i=0;i<idx;i++)
        if(w[i]>mid) f[i]=0;
        else f[i]=1;
    return dinic()>=K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    cin>>n>>m>>K;
    S=1,T=n;
    int l=INF,r=0;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        l=min(l,c);
        r=max(r,c);
        add(a,b,c);
    }
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}