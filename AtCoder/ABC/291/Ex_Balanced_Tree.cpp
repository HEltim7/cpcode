#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
vector<int> adj[N];
int p[N],sz[N];
bool mark[N];

int centroid[2];
void get_centroid(int u,int fa,int tot) {
    int maxx=0;
    sz[u]=1;
    for(int v:adj[u]) {
        if(v!=fa&&!mark[v]) {
            get_centroid(v, u, tot);
            sz[u]+=sz[v];
            maxx=max(maxx,sz[v]);
        }
    }
    maxx=max(maxx,tot-sz[u]);
    if(maxx<=tot/2) centroid[centroid[0]!=0]=u;
}

int find_root(int u,int tot) {
    centroid[0]=centroid[1]=0;
    get_centroid(u,0,tot);
    int root=centroid[0];
    get_centroid(root, 0, tot);
    mark[root]=1;
    for(int v:adj[root]) if(!mark[v]) p[find_root(v, sz[v])]=root;
    return root;
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    find_root(1, n);
    for(int i=1;i<=n;i++) cout<<(p[i]?p[i]:-1)<<' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}