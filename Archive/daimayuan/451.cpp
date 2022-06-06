#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
typedef long long LL;
const int N=200000+10;

vector<int> adj[N];
int id[N],w[N],nw[N],cnt;
int dep[N],sz[N],top[N],p[N],hch[N];
int n,tr[N];

void dfs1(int x,int fa,int d){
    dep[x]=d,p[x]=fa,sz[x]=1;
    for(auto i:adj[x]){
        if(i==fa) continue;
        dfs1(i,x,d+1);
        sz[x]+=sz[i];
        if(sz[hch[x]]<sz[i]) hch[x]=i;
    }
}

void dfs2(int x,int t){
    id[x]=++cnt,nw[cnt]=w[x],top[x]=t;
    if(!hch[x]) return;
    dfs2(hch[x],t);
    for(auto i:adj[x]) if(i!=p[x]&&i!=hch[x]) dfs2(i,i);
}

inline void add(int pos,int v){
    while(pos<=n) tr[pos]^=v,pos+=lowbit(pos);
}

inline int sum(int pos){
    int res=0;
    while(pos) res^=tr[pos],pos-=lowbit(pos);
    return res;
}

int get(int u,int v){
    int res=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res^=(sum(id[u])^sum(id[top[u]]-1));
        u=p[top[u]];
    }
    if(dep[u]<dep[v]) swap(u,v);
    res^=(sum(id[u])^sum(id[v]-1));
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,-1,1);
    dfs2(1,1);
    for(int i=1;i<=n;i++) add(i,nw[i]);
    while(m--){
        int u,v;
        cin>>u>>v;
        cout<<get(u,v)<<endl;
    }
    return 0;
}