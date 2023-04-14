#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=1e4+10,M=2e5+10,INF=0x3f3f3f3f;

int n,m,S,T;
int he[N],e[M],ne[M],cap[M],idx;//cap表示容量
int q[N],d[N],arc[N];//d表示层数，arc表示当前弧

inline void add(int a,int b,int c){
    e[idx]=b,cap[idx]=c,ne[idx]=he[a],he[a]=idx++;
    e[idx]=a,cap[idx]=0,ne[idx]=he[b],he[b]=idx++;
}

int dfs(int id,int lim){
    if(id==T) return lim;
    int flow=0;//优化1,当前流出的流量，如果超过lim就停止dfs
    for(int i=arc[id];~i&&flow<lim;i=ne[i]){
        arc[id]=i;//优化2,更新当前弧
        int ver=e[i];
        if(d[ver]==d[id]+1&&cap[i]){
            int t=dfs(ver,min(cap[i],lim-flow));
            if(!t) d[ver]=-1;//优化3,可用容量为0，删去点ver
            cap[i]-=t,cap[i^1]+=t,flow+=t;
        }
    }
    return flow;
}

//检查是否有增广路，同时建立分层图
bool bfs(){
    int hh=0,tt=0;
    memset(d,-1,sizeof d);
    q[0]=S,d[S]=0;arc[S]=he[S];
    while(hh<=tt){
        int h=q[hh++];
        for(int i=he[h];~i;i=ne[i]){
            int ver=e[i];
            if(d[ver]==-1&&cap[i]){//如果当前点没有被遍历且有容量
                d[ver]=d[h]+1;//按照最短路分层
                arc[ver]=he[ver];
                if(ver==T) return 1;
                q[++tt]=ver;
            }
        }
    }
    return 0;
}

int dinic(){
    int F=0,flow;
    while(bfs()) while(flow=dfs(S,INF)) F+=flow;
    /*
        如果INF一次就足够消耗万整个网络的流量，那么可以不用while循环：
        while(bfs()) F+=dfs(S,INF);
    */
    return F;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(he,-1,sizeof he);
    cin>>n>>m>>S>>T;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<dinic();
    return 0;
}