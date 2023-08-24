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

namespace cd {
    constexpr int N=1e5+10;
    int sz[N],centroid[2];
    vector<int> adj[N];
    bool del[N];

    void get_centroid(int u,int fa,int tot) {
        int maxx=0;
        sz[u]=1;
        for(int v:adj[u]) {
            if(v!=fa&&!del[v]) {
                get_centroid(v,u,tot);
                sz[u]+=sz[v];
                maxx=max(maxx,sz[v]);
            }
        }
        maxx=max(maxx,tot-sz[u]);
        if(maxx<=tot/2) centroid[centroid[0]!=0]=u;
    }

    int cnt[N],ans[N],d;
    void get_cnt(int u,int fa,int dep) {
        if(dep>d) return;
        cnt[dep]++;
        for(int v:adj[u]) {
            if(v!=fa&&!del[v]) {
                get_cnt(v,u,dep+1);
            }
        }
    }

    void get_ans(int u,int fa,int dep,int sign,int lim) {
        if(dep>d) return;
        for(int v:adj[u]) {
            if(v!=fa&&!del[v]) {
                get_ans(v,u,dep+1,sign,lim);
            }
        }
        ans[u]+=sign*cnt[min(d-dep,lim)];
    }

    void solve(int _u,int tot) {
        centroid[0]=centroid[1]=0;
        get_centroid(_u, -1, tot);
        int u=centroid[0];
        get_centroid(u, -1, tot);
        del[u]=1;

        get_cnt(u, 0, 0);
        for(int i=1;i<=min(sz[u],d);i++) cnt[i]+=cnt[i-1];
        get_ans(u, 0, 0, 1, sz[u]);
        for(int i=0;i<=min(sz[u],d);i++) cnt[i]=0;

        for(int v:adj[u]) {
            if(!del[v]) {
                get_cnt(v, u, 1);
                for(int i=1;i<=min(sz[v],d);i++) cnt[i]+=cnt[i-1];
                get_ans(v, u, 1, -1, sz[v]);
                for(int i=0;i<=min(sz[v],d);i++) cnt[i]=0;
            }
        }

        for(int v:adj[u]) if(!del[v]) solve(v, sz[v]);
    }

    void clear(int n) {
        fill(del,del+1+n,0);
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n;
    cin>>n>>cd::d;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        cd::adj[u].emplace_back(v);
        cd::adj[v].emplace_back(u);
    }
    cd::solve(1, n);

    for(int i=1;i<=n;i++) cout<<cd::ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}