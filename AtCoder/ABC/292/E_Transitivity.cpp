#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;
vector<int> adj[N],radj[N];
int cnt[N];
bool mark[N];

void dfs(int u,int p) {
    mark[u]=1;
    if(u!=p) cnt[u]++;
    for(int v:radj[u]) {
        if(!mark[v]) {
            dfs(v,p);
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        if(u==v) continue;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        sort(adj[i].begin(),adj[i].end());
        adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
    }
    for(int i=1;i<=n;i++) {
        memset(mark, 0, sizeof mark);
        dfs(i, i);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++) ans+=cnt[i]-adj[i].size();
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}