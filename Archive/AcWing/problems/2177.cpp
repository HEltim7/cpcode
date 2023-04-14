#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define endl '\n'
const int N=310,M=2e4+10,INF=0x3f3f3f3f;
int e[M],ne[M],f[M],idx;
int h[N],q[N],arc[N],d[N];
int n,m,S,T;
vector<int> path[N];
bool mark[N];

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

void findp(int root,int now){
    path[root].push_back(now);
    mark[now]=1;
    for(int i=h[now];~i;i=ne[i]){
        if(f[i^1]&&e[i]!=S){
            findp(root,e[i]-n);
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    S=0,T=N-1;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) 
        add(S,i,1),add(i+n,T,1);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b+n,1);
    }
    int ans=n-dinic();
    for(int i=1;i<=n;i++) if(!mark[i]) findp(i,i);
    for(int i=1;i<=n;i++)
        if(path[i].size()){
            for(auto x:path[i]) cout<<x<<' ';
            cout<<endl;
        }
    cout<<ans;
    return 0;
}