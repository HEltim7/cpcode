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
constexpr int N=3e3+10;

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
        // if(sz[x]<sz[y]) swap(x,y);
        sz[x]+=sz[y];
        fa[y]=x;
        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }

    DisjointUnionSet() = default;
    DisjointUnionSet(int n) { init(n); }
} dsu(N*2);

void solve() {
    int n;
    cin>>n;
    vector<int> col(n+1),cost(n+1),val(n*2+1);
    vector<tuple<int,int,int>> edg(n-1);
    vector<pair<int,int>> adj(n*2+1);
    for(int i=1;i<=n;i++) cin>>col[i];
    for(int i=1;i<=n;i++) cin>>cost[i];
    for(auto &[w,u,v]:edg) cin>>u>>v>>w;
    sort(edg.begin(),edg.end());
    
    int idx=n;
    for(auto [w,u,v]:edg) {
        idx++;
        u=dsu.find(u);
        v=dsu.find(v);
        val[idx]=w;
        adj[idx]={u,v};
        dsu.join(idx, u);
        dsu.join(idx, v);
    }

    constexpr LL INF=1e18;
    auto dp=vector(n*2+1,vector(n+1,-INF));
    function<int(int)> dfs=[&](int u) {
        if(u<=n) {
            dp[u][0]=col[u]?-cost[u]:0;
            dp[u][1]=col[u]?0:-cost[u];
            return 1;
        }
        auto [lch,rch]=adj[u];
        int l=dfs(lch);
        int r=dfs(rch);
        for(int i=0;i<=l;i++) {
            for(int j=0;j<=r;j++) {
                LL cnt=1LL*i*(r-j)+1LL*j*(l-i);
                dp[u][i+j]=max(
                    dp[u][i+j],
                    dp[lch][i]+dp[rch][j]+cnt*val[u]
                );
            }
        }
        return l+r;
    };
    dfs(idx);

    cout<<*max_element(dp[idx].begin(),dp[idx].end())<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}