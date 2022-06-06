#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
const int N=600,M=1e5+10,INF=0x3f3f3f3f;
int e[M],ne[M],f[M],idx;
int h[N],arc[N],q[N],d[N];
int n,m,S,T;
vector<int> ans[N];

inline void add(int a,int b,int c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}

int dfs(int id,int lim){
    if(id==T) return lim;
    int flow=0;
    for(int i=arc[id];~i&&flow<lim;i=ne[i]){
        arc[id]=i;
        int ver=e[i];
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
    d[S]=0,q[0]=S,arc[S]=h[S];
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    cin>>m>>n;
    n+=m;
    S=0,T=n+1;
    int in,sum=0;
    for(int i=1;i<=m;i++){
        cin>>in;
        sum+=in;
        add(S,i,in);
        for(int j=m+1;j<=n;j++) add(i,j,1);
    }
    for(int i=m+1;i<=n;i++){
        cin>>in;
        add(i,T,in);
    }

    if(dinic()==sum){
        cout<<1<<endl;
        for(int i=0;i<idx;i+=2)
            if(f[i]==0&&e[i]>m&&e[i]<=n)
                ans[e[i^1]].push_back(e[i]);
        for(int i=1;i<=m;i++){
            for(auto x:ans[i])
                cout<<x-m<<' ';
            cout<<endl;
        }
    }
    else cout<<0<<endl;
    return 0;
}