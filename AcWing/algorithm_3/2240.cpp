#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=410,M=5e5+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],idx;
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
    int F=0,flow=0;
    while(bfs()) while(flow=dfs(S,INF)) F+=flow;
    return F;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    int nn,ff,dd;
    cin>>nn>>ff>>dd;
    S=0,T=N-1;
    //FOOD:1~ff,COW:ff+1~ff+2nn,DRINK:ff+2nn+1~ff+2nn+dd;
    //对cow进行拆点
    for(int i=1;i<=ff;i++) add(S,i,1);
    for(int i=ff+1;i<=ff+nn;i++) add(i,i+nn,1);
    for(int i=ff+2*nn+1;i<=ff+2*nn+dd;i++) add(i,T,1);

    for(int i=1;i<=nn;i++){
        int Food,Drink,in;
        cin>>Food>>Drink;
        for(int j=1;j<=Food;j++) cin>>in,add(in,i+ff,1);
        for(int j=1;j<=Drink;j++) cin>>in,add(i+nn+ff,in+2*nn+ff,1);
    }
    cout<<dinic();
    return 0;
}