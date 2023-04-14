#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2.5e5+10;
vector<pair<int,int>> adj[N],g[N];
vector<int> group[N];
int p[N],ans[N],deg[N];
int id[N],oddcnt[N],idx;
bool mark[N],valid=1;
int xorsum;

void dfs(int u) {
    mark[u]=1;
    id[u]=idx;
    group[idx].push_back(u);

    if(deg[u]&1) {
        oddcnt[idx]++;
        xorsum^=p[u];
    }

    for(auto [v,w]:g[u]) {
        if(mark[v]) valid&=(p[v]^p[u])==w;
        else p[v]=p[u]^w,dfs(v);
    }
}

void find_ans(int u,int fa) {
    for(auto [v,id]:adj[u]) {
        if(v!=fa) {
            ans[id]=p[u]^p[v];
            find_ans(v,u);
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        deg[u]++,deg[v]++;
    }

    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++) if(!mark[i]) ++idx,dfs(i);
    for(int i=2;i<=idx;i++) 
        if(oddcnt[i]&1) {
            for(int u:group[i]) p[u]^=xorsum;
            xorsum^=xorsum;
            break;
        }

    if(valid) {
        find_ans(1, 0);
        cout<<"Yes"<<endl;
        for(int i=1;i<n;i++) cout<<ans[i]<<' ';
    }
    else cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}