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

namespace fast_io {
    constexpr int MAXBUF = 1e6;
    char buf[MAXBUF], *pl, *pr;

    #define gc() \
    (pl == pr && (pr = (pl = buf) + fread(buf, 1, MAXBUF, stdin), pl == pr) \
    ? EOF : *pl++)

    template<typename T> T rd(T &x) {
        x = 0;
        T f = 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') f = -1;
            c = gc();
        }
        while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
        return x = x * f;
    }

    template<typename... T> auto read(T&... x) { return (rd(x),...); }   
    #undef gc

    struct IO {
        template<typename T> friend IO&
        operator>>(IO &io, T& x) { rd(x); return io; }
    } static io;
}
using fast_io::read,fast_io::io;

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
    int n;
    io>>n;
    DisjointUnionSet dsu(n);
    vector<vector<int>> adj(n+1);
    vector<int> hch(n+1),dep(n+1);
    int root=1;
    for(int i=1;i<=n;i++) {
        int p;
        io>>p;
        if(p==0) root=i;
        else adj[p].push_back(i);
    }
    for(int i=1;i<=n;i++) {
        io>>hch[i];
        if(hch[i]) dsu.join(i, hch[i]);
    }

    int maxdep=1;
    function<void(int)> dfs=[&](int u) {
        if(dsu.find(u)==u) dep[u]+=__lg(dsu.size(u)*2-1)+1;
        debug(u,dep[u]);
        for(int v:adj[u]) {
            dep[v]=dep[u];
            dfs(v);
        }
        maxdep=max(maxdep,dep[u]);
    };
    dfs(root);
    printf("%d\n",maxdep);
}

int main() {
    int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    int t;
    io>>t;
    while(t--) solve();
    exit(0);
    return 0;
}