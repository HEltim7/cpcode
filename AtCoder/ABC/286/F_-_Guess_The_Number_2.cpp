#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;
constexpr int N=2e5+10;
vector<int> adj[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int k;
    cin>>k;
    vector<int> st(k);
    for(auto &x:st) cin>>x;
    
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}