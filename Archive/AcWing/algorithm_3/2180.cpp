#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
const int N=1e3+10,M=1e6+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],idx;
int h[N],q[N],arc[N],d[N],dp[N],num[N];
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

int getdp(){
    int res=0;
    for(int i=1;i<=n;i++) dp[i]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            if(num[i]>=num[j])
                dp[i]=max(dp[i],dp[j]+1),res=max(res,dp[i]);
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(dp[j]+1==dp[i]&&num[i]>=num[j]) add(j+n,i,1);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    S=0,T=N-1;
    cin>>n;
    if(n==1){
        cout<<1<<endl<<1<<endl<<1;
        return 0;
    }
    for(int i=1;i<=n;i++) cin>>num[i];
    int s=getdp();
    for(int i=1;i<=n;i++){
        if(dp[i]==1) add(S,i,1);
        add(i,i+n,1);
        if(dp[i]==s) add(i+n,T,1);
    }
    cout<<s<<endl;
    int F=dinic();
    cout<<F<<endl;
    if(dp[1]==1) add(1,1+n,INF),add(S,1,INF);
    if(dp[n]==s) add(n,n+n,INF),add(n+n,T,INF);
    cout<<F+dinic()<<endl;
    return 0;
}