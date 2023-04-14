#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e3+10;
vector<int> adj[N];
int dp[N],sz[N],centroid[2],n;

void get_centroid(int u,int fa) {
    int maxx=0;
    sz[u]=1;
    for(int v:adj[u]) {
        if(v!=fa) {
            get_centroid(v, u);
            sz[u]+=sz[v];
            maxx=max(maxx,sz[v]);
        }
    }
    maxx=max(maxx,n-sz[u]);
    if(maxx<=n/2) centroid[centroid[0]!=0]=u;
}

void dfs(int u) {

}

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}