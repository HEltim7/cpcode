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

namespace cd {
    constexpr int N=1e5+10;
    int sz[N],centroid[2],belong[N];
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

    void build(int _u,int tot,int fa=0) {
        centroid[0]=centroid[1]=0;
        get_centroid(_u, -1, tot);
        int u=centroid[0];
        get_centroid(u, -1, tot);
        del[u]=1;

        belong[u]=fa;
        for(int v:adj[u]) if(!del[v]) build(v, sz[v], u);
    }

    multiset<int> st;
    void modify(int u) {
        
    }

    void clear(int n) {
        fill(del,del+1+n,0);
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}