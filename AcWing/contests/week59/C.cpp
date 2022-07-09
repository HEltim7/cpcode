#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
vector<int> adj[N];
bool mark[N];
int ind[N];

int dfs(int u) {
    mark[u]=1;
    int res=ind[u]==2;
    for(auto v:adj[u]) 
        if(!mark[v]) 
            res=min(res,dfs(v));
    return res;
}

void solve() {
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }
    for(int i=1;i<=n;i++) if(!mark[i]) ans+=dfs(i);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}