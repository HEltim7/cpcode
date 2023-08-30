#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
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
    int n,m,k;
    cin>>n>>m>>k;
    auto tim=vector(n+1,0);
    auto adj=vector(n+1,vector<int>());
    auto ind=vector(n+1,0);
    DisjointUnionSet dsu(n+1);

    for(int i=1;i<=n;i++) cin>>tim[i];
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        ind[v]++;
        dsu.join(u, v);
    }

    auto mn=vector(n+1,k);
    auto que=vector(n+1,queue<int>());
    for(int i=1;i<=n;i++) {
        if(ind[i]==0) {
            int fa=dsu.find(i);
            que[fa].emplace(i);
            mn[fa]=min(mn[fa],tim[i]);
        }
    }

    auto dis=[&](LL from,LL to) {
        return to>=from?to-from:to+k-from;
    };

    auto mx=vector(n+1,0LL);
    auto bfs=[&](queue<int> &q) {
        LL res=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            res=max(res,mx[u]);
            for(int v:adj[u]) {
                mx[v]=max(mx[v],mx[u]+dis(tim[u],tim[v]));
                if(--ind[v]==0) q.emplace(v);
            }
        }
        return res;
    };

    auto dur=vector<pair<LL,LL>>();
    for(int i=1;i<=n;i++) {
        if(dsu.find(i)==i) {
            LL res=bfs(que[i]);
            dur.emplace_back(mn[i],res+mn[i]);
        }
    }

    sort(dur.begin(),dur.end(),greater<>());
    multiset<LL> st;
    for(auto [from,to]:dur) st.emplace(to);
    
    LL suf=0,ans=numeric_limits<LL>::max();
    for(auto [from,to]:dur) {
        suf=max(suf,to);
        st.erase(st.find(to));
        LL res=suf;
        if(st.size()) res=max(res,*st.rbegin()+k);
        ans=min(ans,res-from);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}