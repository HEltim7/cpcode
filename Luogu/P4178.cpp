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

template<typename T=int,T init=T()> struct Fenwick {
    using F=function<void(T&,const T&)>;
    F add;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }
    void resize(int n) { tr.resize(n+2,init); }

    void modify(int pos,T val) {
        if(++pos<=0) return;
        while(pos<tr.size()) add(tr[pos],val),pos+=lowbit(pos);
    }

    void reset(int pos) {
        if(++pos<=0) return;
        while(pos<tr.size()) tr[pos]=init,pos+=lowbit(pos);
    }

    T query(int pos) {
        if(++pos<0) return {};
        T res=init;
        while(pos) add(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }
    
    explicit Fenwick(
        int n,F add=[](T &x,const T &y) { x += y; })
        : add(add) {
        resize(n);
    }
};

namespace cd {
    constexpr int N=4e4+10,K=2e4+10;
    int sz[N],centroid[2];
    vector<pair<int,int>> adj[N];
    bool del[N];
    int k;
    LL ans;

    void get_centroid(int u,int fa,int tot) {
        int maxx=0;
        sz[u]=1;
        for(auto [v,w]:adj[u]) {
            if(v!=fa&&!del[v]) {
                get_centroid(v,u,tot);
                sz[u]+=sz[v];
                maxx=max(maxx,sz[v]);
            }
        }
        maxx=max(maxx,tot-sz[u]);
        if(maxx<=tot/2) centroid[centroid[0]!=0]=u;
    }

    Fenwick<> tr(K);
    void dfs(int u,int fa,int d,int type) {
        if(d>=K) return;
        if(type==0) ans+=tr.query(k-d);
        else if(type==1) tr.modify(d, 1);
        else tr.reset(d);
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

        tr.modify(0, 1);
        for(auto [v,w]:adj[u]) {
            if(!del[v]) {
                dfs(v, u, w, 0);
                dfs(v, u, w, 1);
            }
        }
        tr.reset(0);
        for(auto [v,w]:adj[u]) if(!del[v]) dfs(v, u, w, 2);
        for(auto [v,w]:adj[u]) if(!del[v]) solve(v, sz[v]);
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
        int u,v,w;
        cin>>u>>v>>w;
        cd::adj[u].emplace_back(v,w);
        cd::adj[v].emplace_back(u,w);
    }
    cin>>cd::k;
    cd::solve(1, n);
    cout<<cd::ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}