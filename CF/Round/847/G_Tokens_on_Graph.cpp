#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
vector<int> adj[N];
bool ist[N],isb[N],vis[N];
int dis[N],fa[N],sz[N];

int findfa(int x) {
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

void solve() {
    int n,m;
    cin>>n>>m;
    fill(ist,ist+1+n,0);
    fill(isb,isb+1+n,0);
    fill(vis,vis+1+n,0);
    fill(dis,dis+1+n,N);
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;

    int p,b;
    cin>>p>>b;
    vector<int> token(p),bonus(b);
    for(auto &x:token) cin>>x,ist[x]=1;
    for(auto &x:bonus) cin>>x,isb[x]=1;
    
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs=[&](int &len,int &poi) {
        queue<int> q;
        q.push(1);
        dis[1]=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            if(ist[u]&&dis[u]<=len) len=dis[u],poi=u;
            if(isb[u]||u==1) 
                for(int v:adj[u]) 
                    q.push(v),dis[v]=min(dis[v],dis[u]+1);
        }
        return make_pair(len,poi);
    };

    int len=N,poi=-1;
    bfs(len,poi);
    if(len==N) {
        cout<<"NO"<<endl;
        return;
    }

    for(int u=1;u<=n;u++) {
        if(!isb[u]) continue;
        for(int v:adj[u]) {
            if(!isb[v]) continue;
            int a=findfa(u);
            int b=findfa(v);
            if(a!=b) fa[b]=a,sz[a]+=sz[b];
        }
    }

    auto count=[&](int u) {
        int res=0;
        for(int v:adj[u]) if(isb[v]) res=max(res,sz[findfa(v)]);
        if(res>=2) len=0;
        else len-=res;
    };

    for(int u:token) if(u!=poi) count(u);
    if(len<=1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}