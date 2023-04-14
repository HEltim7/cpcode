#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
vector<int> adj[N];
bool mark[N];
int ans;

void dfs(int u) {
    if(ans>=1e6) return;
    mark[u]=1;
    ans++;
    for(int v:adj[u]) {
        if(!mark[v]) {
            dfs(v);
        }
    }
    mark[u]=0;
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
    dfs(1);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}