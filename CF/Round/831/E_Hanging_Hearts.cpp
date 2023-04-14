#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
vector<int> adj[N];

pair<int,int> dfs(int u) {
    int maxx=0,sum=0;
    for(int v:adj[u]) {
        auto [x,y]=dfs(v);
        maxx=max(maxx,x);
        sum+=max(x,y);
    }
    return {maxx+1,sum};
}

void solve() {
    int n;
    cin>>n;
    for(int i=2,p;i<=n;i++) cin>>p,adj[p].emplace_back(i);
    auto [x,y]=dfs(1);
    cout<<max(x,y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}