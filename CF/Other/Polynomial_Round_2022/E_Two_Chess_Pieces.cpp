#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10,M=__lg(N);
vector<int> adj[N];
bool mark[2][N];
int fa[N][M+1];
int dis,ans;

void get_lca(int u,int p) {
    for(int v:adj[u]) {
        if(v==p) continue;
        fa[v][0]=u;
        for(int i=1;i<=M;i++)
            fa[v][i]=fa[fa[v][i-1]][i-1];
        get_lca(v,u);
    }
}

int get(int u) {
    int left=dis;
    for(int i=M;i>=0;i--) {
        if((1<<i)<=left) {
            u=fa[u][i];
            left-=1<<i;
        }
    }
    return u;
}

void dfs(int u,int p) {
    for(int v:adj[u]) if(v!=p) {
        dfs(v,u);
        mark[0][u]|=mark[0][v];
        mark[1][u]|=mark[1][v];
    }
    if(u!=1) {
        if(mark[0][u]) ans+=2;
        if(mark[1][u]) ans+=2;
    }
}

void solve() {
    int n;
    cin>>n>>dis;
    for(int i=2;i<=n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    get_lca(1, 0);

    for(int i=0;i<2;i++) {
        int m;
        cin>>m;
        for(int j=1;j<=m;j++) {
            int in;
            cin>>in;
            mark[i][in]=1;
            mark[i^1][get(in)]=1;
        }
    }
    dfs(1,0);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}