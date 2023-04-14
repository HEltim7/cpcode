#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
vector<int> adj[N];

int dfs(int u) {
    if(adj[u].empty()) return 1;
    vector<int> cur;
    for(int v:adj[u]) cur.push_back(dfs(v)+1);
    sort(cur.begin(),cur.end());
    cur.back()--;
    sort(cur.begin(),cur.end());
    return cur.back();
}

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) {
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    cout<<dfs(1)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}