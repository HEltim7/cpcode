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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=5e3+10;
vector<int> adj[N];
int sz[N];

LL ans;
void dfs(int u) {
    sz[u]=1;
    for(int v:adj[u]) dfs(v),sz[u]+=sz[v];
    if(adj[u].empty()) return;
    int t=(sz[u]-1)/2;
    auto dp=vector(adj[u].size()+1,vector(t+1,0));

    dp[0][0]=1;
    for(int i=1;i<=adj[u].size();i++) {
        int v=adj[u][i-1];
        for(int j=0;j<=t;j++) {
            dp[i][j]|=dp[i-1][j];
            if(j>=sz[v]) dp[i][j]|=dp[i-1][j-sz[v]];
        }
    }
    int maxx=0;
    for(int i=0;i<=t;i++) {
        if(dp[adj[u].size()][i]) maxx=i;
    }
    ans+=1LL*maxx*(sz[u]-1-maxx);
}

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        int p;
        cin>>p;
        adj[p].emplace_back(i);
    }
    dfs(1);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}