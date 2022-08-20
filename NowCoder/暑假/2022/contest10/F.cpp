#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e2+10;
vector<int> adj[N];
int ind[N];
bool mark[N];

bool bfs(int s,int t) {
    queue<int> q;
    q.push(t);
    while(q.size()) {
        int u=q.front();
        q.pop();
        if(u==s) return 1;
        if(mark[u]) continue;
        mark[u]=1;
        for(int v:adj[u]) if(++ind[v]==2) q.push(v);
    }
    return 0;
}

void solve() {
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    for(int i=1;i<=n;i++) adj[i].clear(),mark[i]=0,ind[i]=0;
    while(m--) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(bfs(s,t)) cout<<"Join Player"<<endl;
    else cout<<"Cut Player"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}