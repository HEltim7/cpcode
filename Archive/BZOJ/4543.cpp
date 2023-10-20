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
constexpr int N=1e5+10;

namespace lpd {
    int id[N],ed[N],ori[N],len[N],hch[N],top[N],dfn;
    vector<int> adj[N];

    void dfs1(int u,int fa) {
        for(int v:adj[u]) {
            if(v!=fa) {
                dfs1(v,u);
                if(len[hch[u]]<len[v]) hch[u]=v;
            }
        }
        len[u]=len[hch[u]]+1;
    }

    void dfs2(int u,int fa,int t) {
        top[u]=t;
        ori[id[u]=++dfn]=u;
        ed[u]=id[u]+len[u]-1;
        if(hch[u]) dfs2(hch[u],u,t);
        for(int v:adj[u]) if(v!=fa&&v!=hch[u]) dfs2(v,u,v);
    }

    void init() { dfs1(1,0),dfs2(1,0,1); }
    
    LL ans;
    int f[N],g[N*2];
    void solve(int u,int fa) {
        if(hch[u]) solve(hch[u],u);
        auto getf=[&](int u,int offset) ->int& {
            return f[id[u]+offset];
        };
        auto getg=[&](int u,int offset) -> int& {
            int d=id[u]-id[top[u]]+1;
            int i=(id[top[u]]-1)*2+len[top[u]]+d;
            return g[i+offset];
        };
        getf(u,0)=1;
        ans+=getg(u,0);

        for(int v:adj[u]) {
            if(v!=fa&&v!=hch[u]) {
                solve(v,u);
                // 计算g来自v链，f来自前缀链并的贡献
                for(int i=0,j=1;j<=len[v];i++,j++) ans+=getg(v,-j)*getf(u,i);
                // 计算f来自v链，g来自前缀链并的贡献
                for(int i=1,j=0;j<len[v];i++,j++) ans+=getg(u,-i)*getf(v,j);
                // 计算v链f*前缀链并f对g造成的贡献
                for(int i=1,j=0;j<len[v];i++,j++) getg(u,-i)+=getf(u,i)*getf(v,j);
                // 将v链的g合并至当前链
                for(int i=0,j=1;j<=len[v];i++,j++) getg(u,-i)+=getg(v,-j);
                // 将v链的f合并至当前链
                for(int i=1,j=0;j<len[v];i++,j++) getf(u,i)+=getf(v,j);
            }
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        lpd::adj[u].emplace_back(v);
        lpd::adj[v].emplace_back(u);
    }
    lpd::init();
    lpd::solve(1, 0);
    cout<<lpd::ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}