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
constexpr int N=1e5+10,INF=0x3f3f3f3f;
vector<int> adj[N];
set<int> st[N];
int dis[N],cnt[N];
bool mark[N];

int k;
LL ans=0;
void dfs(int u,int fa) {
    for(int v:st[u]) {
        dfs(v, u);
    }

    bool flag=0;
    for(int v:adj[u]) {
        if(v!=fa&&st[u].find(v)==st[u].end()) {
            debug(u,v,k-dis[u]);
            ans+=k-dis[u];
            flag=1;
        }
    }

    if(st[u].empty()&&!flag&&u!=1)
        ans+=k-dis[u],debug(u,k-dis[u]);
}

void solve() {
    int n,m;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dis, 0x3f, sizeof dis);

    queue<int> q;
    q.push(1);
    dis[1]=0;
    mark[1]=1;

    while(q.size()) {
        int u=q.front();
        q.pop();
        ans++;
        if(dis[u]>=k) continue;
        for(int v:adj[u]) {
            if(!mark[v]&&dis[v]>dis[u]+1) {
                mark[v]=1;
                dis[v]=dis[u]+1;
                q.push(v);
                cnt[u]++;
                st[u].insert(v);
            }
        }
    }
    debug(ans);

    dfs(1, 0);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}