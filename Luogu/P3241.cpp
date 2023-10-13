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
    constexpr int N=1.5e5+10,L=__lg(N)+2;
    vector<pair<int,int>> adj[N];
    int sz[N],centroid[2];
    int belong[L][N],lyr[N],p[N];
    bool del[N];

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

    void dfs_subtr(int lay,int rt,int u,int fa) {
        belong[lay][u]=rt;
        for(auto [v,w]:adj[u]) {
            if(v!=fa&&!del[v]) {
                dfs_subtr(lay, rt, v, u);
            }
        }
    }

    int age[N];
    LL dis[L][N];
    vector<pair<int,LL>> pre[L][N];
    void dfs_rt(int lay,int rt,int u,int fa,LL d) {
        dis[lay][u]=d;
        pre[lay][rt].emplace_back(age[u],d);
        for(auto [v,w]:adj[u]) {
            if(v!=fa&&!del[v]) {
                dfs_rt(lay, rt, v, u, d+w);
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

        for(auto [v,w]:adj[u]) if(!del[v]) dfs_subtr(lay, v, v, u);

        auto work=[&](int u,int d) {
            dfs_rt(lay, u, u, -1, d);
            sort(pre[lay][u].begin(),pre[lay][u].end());
            for(int i=1;i<pre[lay][u].size();i++)
                pre[lay][u][i].second+=pre[lay][u][i-1].second;
        };

        for(auto [v,w]:adj[u]) if(!del[v]) work(v, w);
        work(u, 0);

        for(auto [v,w]:adj[u]) if(!del[v]) p[build(lay+1, v, sz[v])]=u;
        return u;
    }

    LL query(int u,int s,int l,int r) {
        LL res=0;
        int lay=lyr[u];

        auto cal=[&](int u,int r) {
            if(pre[lay][u].front().first>r) return 0LL;
            auto it=--lower_bound(
                pre[lay][u].begin(),pre[lay][u].end(),pair{r+1,-1LL}
            );
            return (it->second)+1LL*(it-pre[lay][u].begin()+1)*dis[lay][s];
        };

        res+=cal(u,r)-cal(u,l-1);
        if(u!=s) {
            int v=belong[lay][s];
            res-=cal(v,r)-cal(v,l-1);
        }

        if(p[u]) res+=query(p[u], s, l, r);
        return res;
    }

    void clear(int n) {
        fill(del,del+1+n,0);
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n,q,lim;
    cin>>n>>q>>lim;
    for(int i=1;i<=n;i++) cin>>cd::age[i];
    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        cd::adj[u].emplace_back(v,w);
        cd::adj[v].emplace_back(u,w);
    }
    cd::build(1, 1, n);

    LL ans=0;
    while(q--) {
        int u,a,b;
        cin>>u>>a>>b;
        int l=(a+ans)%lim;
        int r=(b+ans)%lim;
        if(l>r) swap(l,r);
        ans=cd::query(u, u, l, r);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}