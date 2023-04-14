#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

namespace dsu {
    constexpr int N=1e5+10;
    int id[N],ed[N],ori[N],sz[N],hch[N],idx;
    int cnt[N],ans[N],dif;
    int c[N];
    vector<int> adj[N];

    void init(int u,int fa) {
        sz[u]=1;
        id[u]=++idx;
        ori[id[u]]=u;
        for(int v:adj[u]) {
            if(v!=fa) {
                init(v,u);
                if(sz[v]>sz[hch[u]]) hch[u]=v;
                sz[u]+=sz[v];
            }
        }
        ed[u]=idx;
    }

    void solve(int u,int fa,bool keep) {
        auto add=[](int id) {
            int x=ori[id];
            if(++cnt[c[x]]==1) dif++;
        };

        auto del=[](int id) {
            int x=ori[id];
            if(--cnt[c[x]]==0) dif--;
        };
        
        for(int v:adj[u]) if(v!=fa&&v!=hch[u]) solve(v,u,0);
        if(hch[u]) solve(hch[u],u,1);
        for(int v:adj[u]) 
            if(v!=fa&&v!=hch[u]) 
                for(int i=id[v];i<=ed[v];i++) add(i);
        add(id[u]);
        ans[u]=dif;
        if(!keep) for(int i=id[u];i<=ed[u];i++) del(i);
    }

    void clear(int n=N-1) {
        idx=0;
        fill(hch,hch+n+1,0);
        for(int i=0;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n,m;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        dsu::adj[u].push_back(v);
        dsu::adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>dsu::c[i];
    dsu::init(1, -1);
    dsu::solve(1, -1, 1);
    cin>>m;
    for(int i=1;i<=m;i++) {
        int u;
        cin>>u;
        cout<<dsu::ans[u]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}