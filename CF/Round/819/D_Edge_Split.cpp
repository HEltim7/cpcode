#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=2e5+10;
vector<PII> adj[N];
PII edge[N];
bool poi[N],edg[N],ban[N];

void dfs(int u,int fa) {
    poi[u]=1;
    for(auto [v,id]:adj[u])
        if(v!=fa&&!poi[v]&&!ban[id]) {
            edg[id]=1;
            dfs(v,u);
        }
}

void solve() {
    int n,m;
    cin>>n>>m;

    auto clear=[&]() {
        memset(poi, 0, sizeof(bool)*(n+1));
        memset(edg, 0, sizeof(bool)*(m+1));
        memset(ban, 0, sizeof(bool)*(m+1));
    };

    clear();
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=m;i++) {
        cin>>edge[i].first>>edge[i].second;
        adj[edge[i].first].emplace_back(edge[i].second,i);
        adj[edge[i].second].emplace_back(edge[i].first,i);
    }

    auto output=[&]() {
        for(int i=1;i<=m;i++) cout<<edg[i];
        cout<<endl;
    };

    dfs(1, -1);
    if(m<n+2) output();
    else {
        vector<int> p,id;
        for(int i=1;i<=m;i++) if(!edg[i]) {
            id.push_back(i);
            p.push_back(edge[i].first);
            p.push_back(edge[i].second);
        }
        sort(p.begin(),p.end());
        p.erase(unique(p.begin(),p.end()),p.end());
        if(p.size()!=3) output();
        else {
            clear();
            auto [u,v]=edge[id.front()];
            edg[id.front()]=1;
            poi[u]=poi[v]=1;
            ban[id[1]]=ban[id[2]]=1;
            dfs(u, -1);
            dfs(v, u);
            output();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}