#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

struct Node {
    int sz;
    int id;
    bool operator<(const Node &x) const {
        if(sz!=x.sz) return sz>x.sz;
        return id<x.id;
    }
};

LL a[N],sum[N];
set<Node> st[N];
vector<int> adj[N];
int sz[N],p[N];

void dfs(int u,int fa) {
    sz[u]=1;
    sum[u]=a[u];
    p[u]=fa;
    for(int v:adj[u]) {
        if(v!=fa) {
            dfs(v,u);
            st[u].emplace(sz[v],v);
            sz[u]+=sz[v];
            sum[u]+=sum[v];
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);

    while(m--) {
        int op,u;
        cin>>op>>u;
        debug(op,u);
        if(op==2) {
            if(st[u].empty()) continue;
            int fa=p[u];
            st[fa].erase({sz[u],u});
            auto [szv,v]=*st[u].begin();
            st[u].erase(st[u].begin());
            sz[u]-=sz[v];
            sum[u]-=sum[v];
            sz[v]+=sz[u];
            sum[v]+=sum[u];
            p[v]=fa;
            p[u]=v;

            st[fa].insert({sz[v],v});
            st[v].insert({sz[u],u});
        }
        else cout<<sum[u]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}