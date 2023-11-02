#include <cassert>
#include <vector>
#include <cstring>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
template<class... T> void dbg(T... x) {((cerr<<x<<" "),...),cerr<<endl;}
#define __pos__ "["s+__func__+" "+to_string(__LINE__)+"] "
#define debug(...) cerr<<__pos__<<#__VA_ARGS__" = ", dbg(__VA_ARGS__)
#else
#define debug(...) 0
#endif

constexpr int N = 1e5 + 10,INF=1e9;

namespace sgt {
    #define lch (tr[u].lc)
    #define rch (tr[u].rc)
    struct Node {
        int lc=0, rc=0;
        int mn=INF;
        int add=0;
    };

    constexpr int M = N*(__lg(N)+1)*2;
    vector<Node> tr(M);
    int idx, rng_l, rng_r;

    int new_node() {
        assert(++idx<M);
        tr[idx]={};
        return idx;
    }

    void pushup(int u) {
        tr[u].mn=min(tr[lch].mn,tr[rch].mn);
    }

    void update(int u,int add) {
        if(!u) return;
        tr[u].mn+=add;
        tr[u].add+=add;
    }

    void pushdn(int u) {
        if(!u||!tr[u].add) return;
        if(lch) update(lch,tr[u].add);
        if(rch) update(rch,tr[u].add);
        tr[u].add=0;
    }

    void merge(int &u,int v,int l,int r,int x,int y) {
        if(!u&&!v) return;
        else if(!u||!v) {
            int p=min(tr[u].mn,x);
            int q=min(tr[v].mn,y);
            u=u|v;
            tr[u].add+=p+q-tr[u].mn;
            tr[u].mn=p+q;
        }
        else if(l==r) {
            int p=min(tr[u].mn,x);
            int q=min(tr[v].mn,y);
            tr[u].mn=p+q;
        }
        else {
            pushdn(u),pushdn(v);
            int mid=(l+r)/2;
            merge(tr[u].lc, tr[v].lc, l, mid, x, y);
            merge(tr[u].rc, tr[v].rc, mid+1, r, x, y);
            pushup(u),pushup(v);
        }
    }

    void merge(int u,int v,int x,int y) { merge(u,v,rng_l,rng_r,x,y); }

    void modify(int &u, int l,int r,int p) {
        if(!u) u=new_node();
        if(l==r) {
            tr[u].mn=0;
        }
        else {
            int mid=(l+r)/2;
            if(p<=mid) modify(lch, l, mid, p);
            else modify(rch, mid+1, r, p);
            pushup(u);
        }
    }

    void modify(int &u, int p) {
        modify(u, rng_l, rng_r, p);
    }

    void init(int l,int r) { idx=0, rng_l=l, rng_r=r; }
    #undef lch
    #undef rch
}

vector<int> adj[N];
int c[N],dp[N],rt[N];

void dfs(int u) {
    if(c[u]) {
        sgt::modify(rt[u],c[u]);
        dp[u]=1;
        return;
    }

    int pre=0;
    for(int v:adj[u]) {
        dfs(v);
        if(!rt[u]) {
            rt[u]=rt[v];
            pre+=dp[v];
        }
        else {
            sgt::merge(rt[u],rt[v],pre,dp[v]);
            pre+=dp[v];
        }
    }
    
    dp[u]=sgt::tr[rt[u]].mn+1;
}

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        int p;
        cin>>p;
        adj[p].emplace_back(i);
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    sgt::init(1, n);
    dfs(1);
    cout<<dp[1]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}