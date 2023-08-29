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
    constexpr int N=1e5+10;
    int sz[N],centroid[2];
    vector<int> adj[N];
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

    LL ans[N];
    int c[N],cnt[N],cur[N],cnt_tot,path;
    void dfs(int u,int fa,int type,LL res) {
        if(type==0) {
            if(!cur[c[u]]) {
                cnt[c[u]]+=sz[u];
                cnt_tot+=sz[u];
            }
            path++;
        }
        else if(type==1) {
            if(!cur[c[u]]) res+=path-cnt[c[u]];
            ans[u]+=res;
        }
        else if(type==2) {
            if(!cur[c[u]]) {
                cnt[c[u]]-=sz[u];
                cnt_tot-=sz[u];
            }
            path--;
        }
        cur[c[u]]++;
        for(int v:adj[u]) {
            if(v!=fa&&!del[v]) {
                dfs(v, u, type, res);
            }
        }
        cur[c[u]]--;
    }

    void solve(int _u,int tot) {
        centroid[0]=centroid[1]=0;
        get_centroid(_u, -1, tot);
        int u=centroid[0];
        get_centroid(u, -1, tot);
        del[u]=1;

        dfs(u, 0, 0, 0);
        ans[u]+=cnt_tot;
        for(int v:adj[u]) {
            if(!del[v]) {
                cur[c[u]]++;
                dfs(v, u, 2, 0);
                cur[c[u]]--;
                cnt[c[u]]-=sz[v];
                cnt_tot-=sz[v];

                cur[c[u]]++;
                dfs(v, u, 1, cnt_tot);
                cur[c[u]]--;

                cur[c[u]]++;
                dfs(v, u, 0, 0);
                cur[c[u]]--;
                cnt[c[u]]+=sz[v];
                cnt_tot+=sz[v];
            }
        }
        dfs(u, 0, 2, 0);
        for(int v:adj[u]) if(!del[v]) solve(v, sz[v]);
    }

    void clear(int n) {
        fill(del,del+1+n,0);
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>cd::c[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        cd::adj[u].emplace_back(v);
        cd::adj[v].emplace_back(u);
    }
    cd::solve(1, n);
    for(int i=1;i<=n;i++) cout<<cd::ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}