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
constexpr int N=1e6+10;

namespace lpd {
    int id[N],ed[N],len[N],hch[N],dfn;
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

    void dfs2(int u,int fa) {
        id[u]=++dfn;
        ed[u]=id[u]+len[u]-1;
        if(hch[u]) dfs2(hch[u],u);
        for(int v:adj[u]) if(v!=fa&&v!=hch[u]) dfs2(v,u);
    }

    void init() { dfs1(1,0),dfs2(1,0); }

    int ans[N],cnt[N];
    void solve(int u,int fa) {
        if(hch[u]) solve(hch[u],u);
        if(hch[u]) ans[u]=ans[hch[u]]+1;
        if(++cnt[id[u]]>=cnt[id[u]+ans[u]]) ans[u]=0;
        for(int v:adj[u]) {
            if(v!=fa&&v!=hch[u]) {
                solve(v,u);
                for(int i=id[u]+1,j=id[v];j<=ed[v];i++,j++) {
                    cnt[i]+=cnt[j];
                    if(cnt[i]>cnt[id[u]+ans[u]]) ans[u]=i-id[u];
                    else if(cnt[i]==cnt[id[u]+ans[u]]) ans[u]=min(ans[u],i-id[u]);
                }
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
    for(int i=1;i<=n;i++) cout<<lpd::ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}