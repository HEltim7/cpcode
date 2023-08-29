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
    constexpr int N=510;
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

    int maxk;
    vector<int> seg[12];
    void solve(int _u,int tot,int k) {
        centroid[0]=centroid[1]=0;
        get_centroid(_u, -1, tot);
        int u=centroid[0];
        get_centroid(u, -1, tot);
        del[u]=1;

        maxk=max(maxk,k);
        seg[k].emplace_back(u);
        for(int v:adj[u]) if(!del[v]) solve(v, sz[v],k+1);
    }

    void clear(int n) {
        fill(del,del+1+n,0);
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        cd::adj[u].emplace_back(v);
        cd::adj[v].emplace_back(u);
    }
    cd::solve(1, n, 1);
    cout<<cd::maxk<<endl;
    for(int i=cd::maxk;i>=1;i--) {
        cout<<cd::seg[i].size()<<' ';
        for(int x:cd::seg[i]) cout<<x<<' ';
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}