#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int c[N],dis[N],res;
bool mark[N];
vector<int> adj[N];

void dfs(int u,int fa) {
    if(dis[u]>res) return;
    if(mark[u]) res=min(res,dis[u]);
    for(int v:adj[u]) {
        if(v!=fa) {
            if(dis[u]+1<dis[v]) {
                dis[v]=dis[u]+1;
                dfs(v,u);
            }
            else res=min(res,dis[u]+dis[v]+1);
        }
    }
}

void solve() {
    int n;
    cin>>n>>c[0];
    for(int i=1;i<n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(mark,0,sizeof(bool)*(n+1));
    memset(dis,0x3f,sizeof(int)*(n+1));
    res=0x3f3f3f3f;
    for(int i=0;i<n;i++) {
        dis[c[i]]=0;
        dfs(c[i],0);
        mark[c[i]]=1;
        if(i) cout<<res<<" \n"[i==n-1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}