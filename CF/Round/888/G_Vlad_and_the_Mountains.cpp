#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
constexpr int N=2e5+10;
vector<int> adj[N];

struct DisjointUnionSet {
    vector<int> fa,sz;

    void init(int n) {
        fa.resize(n+1);
        sz.assign(n+1,1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }

    bool same(int x,int y) {
        return find(x)==find(y);
    }

    bool join(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        sz[x]+=sz[y];
        fa[y]=x;
        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }

    DisjointUnionSet() = default;
    DisjointUnionSet(int n) { init(n); }
};

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> id(n);
    iota(id.begin(), id.end(), 1);
    sort(id.begin(),id.end(),[&](int x,int y) {
        return h[x]<h[y];
    });
    debug(id);

    int q;
    cin>>q;
    vector<bool> ans(q+1),mark(n+1);
    vector<tuple<int,int,int,int>> qry(q);
    for(int i=1;i<=q;i++) {
        int a,b,e;
        cin>>a>>b>>e;
        qry.emplace_back(h[a]+e,a,b,i);
    }
    sort(qry.begin(),qry.end());
    debug(qry);

    DisjointUnionSet dsu(n);
    for(int idx=0; auto [e,a,b,qid]:qry) {
        while(idx<id.size()&&h[id[idx]]<=e) {
            int u=id[idx++];
            mark[u]=1;
            for(int v:adj[u]) {
                if(mark[v]) dsu.join(u, v);
            }
        }
        ans[qid]=dsu.same(a, b);
    }

    for(int i=1;i<=q;i++) cout<<(ans[i]?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}