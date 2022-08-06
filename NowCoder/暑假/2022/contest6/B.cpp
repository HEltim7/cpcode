#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;

const int N=2e6+10;
vector<int> adj[N];
int dep[N],dis[N],val[N];

void dfs(int u,int d,int fa) {
    dep[d]=u;
    val[u]++;
    val[dep[max(0,d-dis[u]-1)]]--;
    for(int v:adj[u]) if(v!=fa) dfs(v,d+1,u);
}

void sum(int u,int fa) {
    for(int v:adj[u]) if(v!=fa) sum(v,u),val[u]+=val[v];
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>dis[i];
    dfs(1,1,-1);
    sum(1,-1);
    for(int i=1;i<=n;i++) cout<<val[i]<<' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}