#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
using TIII=tuple<int,int,int>;
constexpr int N=1e5+10;

vector<int> adj[N];
PII res[N];
int sz[N],fa[N];

void init(int u,int p) {
    sz[u]++;
    fa[u]=p;
    for(int v:adj[u]) {
        if(v!=p) {
            init(v,u);
            sz[u]+=sz[v];
        }
    }
}

PII get(int cnt) {
    PII res={};
    while(cnt>=2&&cnt%2==0) {
        cnt/=2;
        res.first++;
    }
    while(cnt>=5&&cnt%5==0) {
        cnt/=5;
        res.second++;
    }
    return res;
}

void dfs(int u) {
    res[u]=res[fa[u]];
    auto tmp=get(fa[u]);
    res[u].first-=tmp.first*sz[u];
    res[u].second-=tmp.second*sz[u];
    tmp=get(u);
    res[u].first+=tmp.first*sz[u];
    res[u].second+=tmp.second*sz[u];
    for(int v:adj[u]) if(v!=fa[u]) dfs(v);
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init(1,0);
    dfs(1);
    while(m--) {
        int x;
        cin>>x;
        cout<<min(res[x].first,res[x].second)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}