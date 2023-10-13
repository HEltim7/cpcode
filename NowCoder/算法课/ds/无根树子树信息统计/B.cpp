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
    constexpr int N=1e5+10,L=__lg(N)+2;
    vector<int> adj[N];
    int sz[N],centroid[2];
    // belong[l][u] u点在点分树第l层所属的子树
    // lay[u] u作为分治重心在点分树上的层数
    // p[u] u在点分树上的父节点
    int belong[L][N],lay[N],p[N];
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

    // dis[l][u] 点分树l层，u与分治重心的距离
    // cnt[l][u][i] 点分树l层u子树中，以u为一端长度为i的链数量
    int dis[L][N],lsz[L][N];
    vector<int> cnt[L][N];
    void get_cnt(vector<int> &cnt,int u,int fa,int dep,int lyr) {
        belong[lyr][u]=fa==-1?u:belong[lyr][fa];
        lsz[lyr][u]=sz[u];
        dis[lyr][u]=dep;
        cnt[dep]++;
        for(int v:adj[u]) {
            if(v!=fa&&!del[v]) {
                get_cnt(cnt,v,u,dep+1,lyr);
            }
        }
    }

    // 建立点分树并初始化计数
    int build(int _u,int tot,int lyr) {
        centroid[0]=centroid[1]=0;
        get_centroid(_u, -1, tot);
        int u=centroid[0];
        get_centroid(u, -1, tot);
        lay[u]=lyr;
        del[u]=1;

        auto work=[&](int v,int fa) {
            auto &vec=cnt[lyr][v];
            vec.resize(sz[v]+1);
            get_cnt(vec, v, fa, v==u?0:1, lyr);
            partial_sum(vec.begin(),vec.end(),vec.begin());
        };

        work(u, -1);
        for(int v:adj[u]) if(!del[v]) work(v,-1);
        
        for(int v:adj[u]) if(!del[v]) p[build(v, sz[v], lyr+1)]=u;
        return u;
    }

    // 从查询点爬点分树，容斥累计答案，注意爬树过程重心与r的距离非单调
    int query(int u,int r,int d) {
        int res=0;
        int len=dis[lay[u]][r];
        int l=lay[u];
        if(d-len>=0) res+=cnt[l][u][min(d-len,lsz[l][u])];
        if(u!=r) {
            int rt=belong[l][r];
            if(d-len>=0) res-=cnt[l][rt][min(d-len,lsz[l][rt])];
        }
        if(p[u]) res+=query(p[u],r,d);
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
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        cd::adj[u].emplace_back(v);
        cd::adj[v].emplace_back(u);
    }
    cd::build(1, n, 1);
    
    int last=0;
    while(q--) {
        int r,d;
        cin>>r>>d;
        r=(r+last)%n+1;
        last=cd::query(r, r, d);
        cout<<last<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}