#pragma GCC optimize("O2")
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10,M=1e6+10,INF=0x3f3f3f3f;
vector<pair<int,int>> adj[N];

namespace cd {
    bool del[N];
    int sz[N],centroid[2];

    void get_centroid(int u,int fa,int tot) {
        int maxx=0;
        sz[u]=1;
        for(auto [v,_]:adj[u]) {
            if(v!=fa&&!del[v]) {
                get_centroid(v,u,tot);
                sz[u]+=sz[v];
                maxx=max(maxx,sz[v]);
            }
        }
        maxx=max(maxx,tot-sz[u]);
        if(maxx<=tot/2) centroid[centroid[0]!=0]=u;
    }

    int minn[M];
    vector<pair<int,int>> path;
    void get_path(int u,int fa,int len,int cnt) {
        path.emplace_back(len,cnt);
        for(auto [v,l]:adj[u]) {
            if(v!=fa&&!del[v]) {
                get_path(v, u, len+l, cnt+1);
            }
        }
    }

    int k;
    int solve(int _u,int tot) {
        centroid[0]=centroid[1]=0;
        get_centroid(_u, -1, tot);
        int root=centroid[0];
        get_centroid(root, -1, tot);
        del[root]=1;
        
        minn[0]=0;
        int ans=INF;
        vector<int> all;
        all.reserve(tot);
        for(auto [v,l]:adj[root]) {
            if(!del[v]) {
                path.clear();
                get_path(v, root, l, 1);
                for(auto [len,cnt]:path) if(len<=k) ans=min(ans,minn[k-len]+cnt);
                for(auto [len,cnt]:path) if(len<=k) 
                    all.emplace_back(len),minn[len]=min(minn[len],cnt);
            }
        }
        for(int len:all) minn[len]=INF;

        for(auto [v,_]:adj[root]) if(!del[v]) ans=min(ans,solve(v,sz[v]));
        return ans;
    }
}

void solve() {
    memset(cd::minn, 0x3f, sizeof cd::minn);
    cd::minn[0]=0;

    int n;
    cin>>n>>cd::k;
    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    int ans=cd::solve(0, n);
    cout<<(ans==INF?-1:ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}