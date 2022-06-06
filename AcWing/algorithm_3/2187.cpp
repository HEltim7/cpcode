#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=4e4+10,M=1e5+10,INF=0x3f3f3f3f;
int e[M],ne[M],f[M],idx;
int h[N],d[N],arc[N],q[N];
int n,m,k,S,T;
int fa[30];

struct SHIP{
    int h,r;
    int id[30];
} ship[30];

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

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

inline int get(int day,int id){
    return day*(n+2)+id;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    for(int i=0;i<30;i++) fa[i]=i;
    S=N-2,T=N-1;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ship[i]={a,b};
        for(int j=0;j<b;j++){
            cin>>a;
            if(a==-1) a=n+1;
            ship[i].id[j]=a;
            if(j){
                int x=ship[i].id[j-1];
                x=findfa(x);
                fa[x]=findfa(a);
            }
        }
    }
    int day=1,res=0;
    if(findfa(0)!=findfa(n+1)) cout<<"0";
    else{
        for(;;day++){
            //建一条到地球的初始边
            add(S,0,k);
            //建立平行时间边
            for(int i=0;i<=n+1;i++)
                add(get(day-1,i),get(day,i),INF);
            //建立太空船边
            for(int i=0;i<m;i++){
                int r=ship[i].r;
                int last=ship[i].id[(day-1)%r];
                int now=ship[i].id[day%r];
                add(get(day-1,last),get(day,now),ship[i].h);
            }
            //建立月球边
            add(get(day,n+1),T,INF);
            res+=dinic();
            if(res>=k) break;
        }
        cout<<day;
    }
    return 0;
}