#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
typedef long long LL;
const int N=1e3+10,M=1e4+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],idx;
int h[N],q[N],d[N],arc[N];
int n,m,S=N-1,T=N-2;
int label[N];
PII edge[M];

inline void add(int a,int b,int c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=c,ne[idx]=h[b],h[b]=idx++;
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

void build(int cnt){
    memset(h,-1,sizeof h);
    idx=0;
    for(int i=1;i<=m;i++) add(edge[i].first,edge[i].second,1);
    for(int i=1;i<=n;i++)
        if(~label[i])
            if(label[i]>>cnt&1) add(i,T,INF);
            else add(S,i,INF);
}

LL dinic(int cnt){
    LL F=0,flow=0;
    build(cnt);
    while(bfs()) while(flow=dfs(S,INF)) F+=flow;
    return F;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(label,-1,sizeof label);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>edge[i].first>>edge[i].second;
    }
    int k;
    cin>>k;
    while(k--){
        int a;
        cin>>a>>label[a];
    }
    LL ans=0;
    for(int i=0;i<=30;i++) ans+=dinic(i)<<i;
    cout<<ans;
    return 0;
}