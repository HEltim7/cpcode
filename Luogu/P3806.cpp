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
constexpr int K=110;
int m;
int k[K];
bool ans[K];

namespace cd {
    constexpr int N=1e4+10,M=1e8+10;
    int sz[N],centroid[2];
    vector<pair<int,int>> adj[N];
    bool del[N];

    void get_centroid(int u,int fa,int tot) {
        int maxx=0;
        sz[u]=1;
        for(auto [v,_]:adj[u]) {
            if(v!=fa&&!del[v]) {
                get_centroid(v,u,tot);
                sz[u]+=sz[v];
                maxx=max(maxx,sz[v]);
            }
        }
        maxx=max(maxx,tot-sz[u]);
        if(maxx<=tot/2) centroid[centroid[0]!=0]=u;
    }

    bool mark[M];
    void dfs(int u,int fa,int d,int type) {
        if(type==0) {
            for(int i=1;i<=m;i++) {
                if(k[i]-d>=0&&mark[k[i]-d])
                    ans[i]=1;
            }
        }
        if(type==1) mark[d]=1;
        if(type==2) mark[d]=0;
        for(auto [v,w]:adj[u]) {
            if(v!=fa&&!del[v]) {
                dfs(v, u, d+w, type);
            }
        }
    }

    void solve(int _u,int tot) {
        centroid[0]=centroid[1]=0;
        get_centroid(_u, -1, tot);
        int u=centroid[0];
        get_centroid(u, -1, tot);
        del[u]=1;

        for(auto [v,w]:adj[u]) {
            if(!del[v]) {
                dfs(v, u, w, 0);
                dfs(v, u, w, 1);
            }
        }
        for(int i=1;i<=m;i++) if(mark[k[i]]) ans[i]=1;
        
        for(auto [v,w]:adj[u]) {
            if(!del[v]) {
                dfs(v, u, w, 2);
            }
        }
        
        for(auto [v,_]:adj[u]) if(!del[v]) solve(v, sz[v]);
    }

    void clear(int n) {
        fill(del,del+1+n,0);
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n;
    cin>>n>>m;
    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        cd::adj[u].emplace_back(v,w);
        cd::adj[v].emplace_back(u,w);
    }
    for(int i=1;i<=m;i++) cin>>k[i];
    cd::solve(1,n);
    for(int i=1;i<=m;i++) cout<<(ans[i]?"AYE":"NAY")<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}