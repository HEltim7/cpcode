#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=510,M=1e4+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],idx;
int h[N],q[N],arc[N],d[N];
int n,m,S,T;
bool vis_s[N],vis_t[N];

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
    q[0]=S,d[S]=0,arc[S]=h[S];
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

void dfs(int id,bool st[],int t){
    st[id]=1;
    for(int i=h[id];~i;i=ne[i]){
        int ver=e[i],j=i^t;
        if(f[j]&&!st[ver]) dfs(ver,st,t);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    cin>>n>>m;
    S=0,T=n-1;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    dinic();
    dfs(S,vis_s,0);
    dfs(T,vis_t,1);
    int ans=0;
    for(int i=0;i<idx;i+=2)
        if(!f[i]&&vis_s[e[i^1]]&&vis_t[e[i]])
            ans++;
    cout<<ans;
    return 0;
}