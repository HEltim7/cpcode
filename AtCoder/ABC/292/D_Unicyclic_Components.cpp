#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
bool mark[N];
vector<int> adj[N];
vector<pair<int,int>> edg;
int id[N],cnt[N],ecnt[N];

void dfs(int u,int idx) {
    mark[u]=1;
    id[u]=idx;
    cnt[idx]++;
    for(int v:adj[u]) {
        if(!mark[v]) {
            dfs(v,idx);
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    if(n!=m) {
        cout<<"No"<<endl;
        return;
    }
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edg.emplace_back(u,v);
    }
    int idx=0;
    for(int i=1;i<=n;i++) if(!mark[i]) dfs(i,++idx);
    for(auto [u,v]:edg) ecnt[id[u]]++;
    for(int i=1;i<=idx;i++) {
        debug(cnt[i],ecnt[i]);
        if(cnt[i]!=ecnt[i]) {
            cout<<"No"<<endl;
            return ;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}