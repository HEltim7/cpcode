#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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

void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    LL ans=0;
    vector<int> sz(n+1);
    // add[u]=将u向上子树xor上a[u]^a[p]的代价-将u向下子树xor上a[u]^a[p]的代价
    vector<LL> add(n+1);
    function<void(int,int)> dfs1=[&](int u,int fa) {
        sz[u]=1;
        for(int v:adj[u]) {
            if(v!=fa) {
                dfs1(v,u);
                sz[u]+=sz[v];
                ans+=1LL*sz[v]*(a[u]^a[v]);
                add[v]=1LL*(n-sz[v]-sz[v])*(a[u]^a[v]);
            }
        }
    };

    // 以u为根的代价=从1到u路径上的代价全部变为向上
    function<void(int,int)> dfs2=[&](int u,int fa) {
        for(int v:adj[u]) {
            if(v!=fa) {
                // 链上前缀和
                add[v]+=add[u];
                dfs2(v,u);
            }
        }
    };

    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++) cout<<ans+add[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}