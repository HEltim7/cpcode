#include <algorithm>
#include <array>
#include <cassert>
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
};

void solve() {
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>> edg(m);
    for(auto &[w,u,v]:edg) {
        cin>>u>>v>>w;
    }
    sort(edg.begin(),edg.end());
    DisjointUnionSet dsu(n);
    map<int, int> cnt;
    int ans=0;
    for(auto [w,u,v]:edg) {
        if(!dsu.same(u, v)) {
            dsu.join(u, v);
            cnt[w]++;
            ans+=w;
        }
    }
    debug(ans);
    debug(cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}