#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,M=450;
vector<int> adj[N];
bitset<M> bs[N];
int deg[N],mp[N];

void solve() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> edg;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        deg[u]++,deg[v]++;
        edg.emplace_back(u,v);
    }
    
    for(auto [u,v]:edg) {
        if(deg[u]<deg[v]+(u<v)) adj[u].push_back(v);
        else adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());

    LL ans=0;
    for(int u=1;u<=n;u++) {
        edg.clear();
        for(int idx=0; int v:adj[u]) mp[v]=idx++;
        for(int v:adj[u]) {
            bs[v].reset();
            int i=0,j=0;
            while(i<adj[u].size()&&j<adj[v].size()) {
                if(adj[u][i]==adj[v][j]) {
                    edg.emplace_back(v,adj[v][j]);
                    bs[v].set(mp[adj[v][j]]);
                    i++,j++;
                }
                else if(adj[u][i]<adj[v][j]) i++;
                else j++;
            }
        }
        for(auto [v,w]:edg) ans+=(bs[v]&bs[w]).count();
    }

    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}