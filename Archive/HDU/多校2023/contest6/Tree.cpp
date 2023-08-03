#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
using PII=pair<int,int>;
constexpr int N=1e5+10;
constexpr PII zero={0,0};
int c[N];
LL ans;

namespace cd {
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

    map<PII,int> mp;
    void dfs(int u,int fa,PII cur,bool ins) {
        if(c[u]==0) cur.first--,cur.second--;
        else if(c[u]==1) cur.first++;
        else if(c[u]==2) cur.second++;
        if(ins) mp[cur]++;
        else {
            PII aim={0-cur.first,0-cur.second};
            auto it=mp.find(aim);
            if(it!=mp.end()) ans+=it->second;
        }
        for(int v:adj[u]) if(v!=fa&&!del[v]) dfs(v,u,cur,ins);
    }

    void solve(int _u,int tot) {
        centroid[0]=centroid[1]=0;
        get_centroid(_u, -1, tot);
        int u=centroid[0];
        get_centroid(u, -1, tot);
        del[u]=1;

        PII cur=zero;
        if(c[u]==0) cur.first--,cur.second--;
        else if(c[u]==1) cur.first++;
        else if(c[u]==2) cur.second++;

        mp.clear();
        mp[zero]=1;
        for(int v:adj[u]) {
            if(!del[v]) {
                dfs(v, u, cur, false);
                dfs(v, u, zero, true);
            }
        }

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
    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        c[i]=in-'a';
    }
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        cd::adj[u].emplace_back(v);
        cd::adj[v].emplace_back(u);
    }
    cd::solve(1, n);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}