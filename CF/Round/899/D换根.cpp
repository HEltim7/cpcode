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
constexpr int N=2e5+10;
vector<int> adj[N];
int arr[N],sz[N];
LL dp[N],ans[N];

namespace chrt {
    // 初始化节点u
    void init(int u) {
        sz[u]=1;
        dp[u]=0;
    }

    // 将子树u加入到子树p下
    void link(int p,int u) {
        sz[p]+=sz[u];
        dp[p]+=dp[u]+1LL*sz[u]*(arr[p]^arr[u]);
    }

    // 将子树u从子树p中移除
    void cut(int p,int u) {
        sz[p]-=sz[u];
        dp[p]-=dp[u]+1LL*sz[u]*(arr[p]^arr[u]);
    }

    void dfs1(int u,int fa) {
        init(u);
        for(int v:adj[u]) {
            if(v!=fa) {
                dfs1(v,u);
                link(u,v);
            }
        }
    }

    void dfs2(int u,int fa) {
        ans[u]=dp[u];
        for(int v:adj[u]) {
            if(v!=fa) {
                cut(u,v),link(v,u);
                dfs2(v,u);
                cut(v,u),link(u,v);
            }
        }
    }

    void solve(int rt) {
        dfs1(rt, -1);
        dfs2(rt, -1);
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    chrt::solve(1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++) adj[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}