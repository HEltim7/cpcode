#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e5+10;
vector<int> adj[N];
int hch[N],sz[N],id[N],ed[N],idx;
int cnt[N],color[N],idcolor[N],mx;
LL tot[N],ans[N];

void dfs1(int u,int fa) {
    id[u]=++idx;
    sz[u]=1;
    for(int v:adj[u])
        if(v!=fa) {
            dfs1(v, u);
            if(sz[v]>sz[hch[u]]) hch[u]=v;
            sz[u]+=sz[v];
        }
    ed[u]=idx;
}

void dfs2(int u,int fa,bool keep) {
    auto add=[&](int c) {
        c=idcolor[c];
        tot[cnt[c]]-=c;
        cnt[c]++;
        tot[cnt[c]]+=c;
        mx=max(mx,cnt[c]);
    };
    
    auto del=[&](int c) {
        c=idcolor[c];
        tot[cnt[c]]-=c;
        cnt[c]--;
        tot[cnt[c]]+=c;
        if(tot[mx]==0) mx--;
    };

    for(int v:adj[u]) 
        if(v!=fa&&v!=hch[u])
            dfs2(v, u, 0);
    if(hch[u]) dfs2(hch[u], u, 1);
    for(int v:adj[u])
        if(v!=fa&&v!=hch[u])
            for(int i=id[v];i<=ed[v];i++) add(i);
    add(id[u]);

    ans[u]=tot[mx];
    if(!keep) for(int i=id[u];i<=ed[u];i++) del(i);
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>color[i];
    for(int i=2;i<=n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, -1);
    for(int i=1;i<=n;i++) idcolor[id[i]]=color[i];
    dfs2(1, -1, 1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}