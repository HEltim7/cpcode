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

template<typename T=int,T init=T()> struct Fenwick {
    using F=function<void(T&,const T&)>;
    F add,sub;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }
    void resize(int n) { tr.resize(n+2,init); }

    void modify(int pos,T val) {
        pos++;
        if(pos<=0||pos>=tr.size()) return;
        while(pos<tr.size()) add(tr[pos],val),pos+=lowbit(pos);
    }

    void reset(int pos) {
        if(++pos<=0) return;
        while(pos<tr.size()) tr[pos]=init,pos+=lowbit(pos);
    }

    T query(int pos) {
        if(++pos<0) return init;
        pos=min(pos,int(tr.size())-1);
        T res=init;
        while(pos) add(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }
    
    T range_query(int l,int r) {
        T res=query(r);
        sub(res,query(l-1));
        return res;
    }

    explicit Fenwick(
        int n,
        F add=[](T &x,const T &y) { x+=y; },
        F sub=[](T &x,const T &y) { x-=y; })
        : add(add),sub(sub) {
        resize(n);
    }
};

namespace cd {
    constexpr int N=1e5+10,L=__lg(N)+2;
    vector<int> adj[N];
    int sz[N],centroid[2];
    int belong[L][N],lyr[N],p[N];
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

    void dfs_subtr(int lay,int rt,int u,int fa) {
        belong[lay][u]=rt;
        for(int v:adj[u]) {
            if(v!=fa&&!del[v]) {
                dfs_subtr(lay, rt, v, u);
            }
        }
    }

    LL val[N];
    int dis[L][N];
    
    auto tr=vector(L,vector(N,Fenwick<LL>(-2)));
    void dfs_rt(int lay,int rt,int u,int fa,int d) {
        dis[lay][u]=d;
        tr[lay][rt].modify(d, val[u]);
        for(int v:adj[u]) {
            if(v!=fa&&!del[v]) {
                dfs_rt(lay, rt, v, u, d+1);
            }
        }
    }

    int build(int lay,int _u,int tot) {
        centroid[0]=centroid[1]=0;
        get_centroid(_u, -1, tot);
        int u=centroid[0];
        get_centroid(u, -1, tot);
        lyr[u]=lay;
        del[u]=1;

        for(int v:adj[u]) if(!del[v]) dfs_subtr(lay, v, v, u);

        auto work=[&](int u,int d) {
            tr[lay][u].resize(sz[u]+d);
            dfs_rt(lay, u, u, -1, d);
        };

        for(int v:adj[u]) if(!del[v]) work(v, 1);
        work(u, 0);

        for(int v:adj[u]) if(!del[v]) p[build(lay+1, v, sz[v])]=u;
        return u;
    }

    void modify(int u,int s,LL x) {
        int lay=lyr[u];
        int d=dis[lay][s];
        tr[lay][u].modify(d, x-val[s]);
        if(u!=s) {
            int v=belong[lay][s];
            tr[lay][v].modify(d, x-val[s]);
        }
        if(p[u]) modify(p[u], s, x);
    }

    LL query(int u,int s,int k) {
        LL res=0;
        int lay=lyr[u];
        int d=k-dis[lay][s];

        res+=tr[lay][u].query(d);
        if(u!=s) {
            int v=belong[lay][s];
            res-=tr[lay][v].query(d);
        }

        if(p[u]) res+=query(p[u], s, k);
        return res;
    }

    void clear(int n) {
        fill(del,del+1+n,0);
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>cd::val[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        cd::adj[u].emplace_back(v);
        cd::adj[v].emplace_back(u);
    }
    cd::build(1, 1, n);

    LL ans=0;
    while(q--) {
        LL op,x,y;
        cin>>op>>x>>y;
        x^=ans,y^=ans;
        if(op==0) {
            ans=cd::query(x, x, y);
            cout<<ans<<endl;
        }
        else {
            cd::modify(x, x, y);
            cd::val[x]=y;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}