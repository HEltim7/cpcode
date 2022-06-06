#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e2+10,M=1e5+10;
const LL INF=0x3f3f3f3f3f3f3f3f;
LL f[M];
int e[M],ne[M],idx;
int h[N],q[N],arc[N],d[N];
int n,m,S,T;
bool mark[N];

inline void add(int a,int b,LL c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}

LL dfs(int id,LL lim){
    if(id==T) return lim;
    LL flow=0;
    for(int i=arc[id];~i&&flow<lim;i=ne[i]){
        int ver=e[i];
        arc[id]=i;
        if(f[i]&&d[ver]==d[id]+1){
            LL t=dfs(ver,min(f[i],lim-flow));
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
            if(f[i]&&d[t]==-1){
                d[t]=d[ver]+1;
                arc[t]=h[t];
                if(t==T) return 1;
                q[tt++]=t;
            }
        }
    }
    return 0;
}

LL dinic(){
    LL F=0,flow=0;
    while(bfs()) while(flow=dfs(S,INF)) F+=flow;
    return F;
}

void dfs(int x,int fa){
    mark[x]=1;
    for(int i=h[x];~i;i=ne[i]){
        int ver=e[i];
        if(ver==fa) continue;
        if(f[i]>0&&!mark[ver]) dfs(ver,x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    memset(h,-1,sizeof h);
    S=1+n,T=n;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a+n,b,INF);
        add(b+n,a,INF);
    }
    for(int i=1;i<=n;i++){
        int c;
        cin>>c;
        add(i,i+n,c);
    }
    cout<<dinic()<<endl;
    vector<int> ans;
    dfs(S,-1);
    for(int i=0;i<idx;i+=2) if(mark[e[i^1]]&&!mark[e[i]]) ans.push_back(e[i^1]);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<' ';
    return 0;
}