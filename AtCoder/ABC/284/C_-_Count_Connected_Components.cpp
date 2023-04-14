#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
vector<int> adj[N];
bool mark[N];

void dfs(int u) {
    if(mark[u]) return;
    mark[u]=1;
    for(int v:adj[u]) dfs(v);
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans=0;
    for(int i=1;i<=n;i++) if(!mark[i]) ans++,dfs(i);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}