#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
vector<int> dp[N],adj[N];
int s[N],siz[N];
int n,m;

void init(int u) {
    siz[u]=1;
    for(int v:adj[u]) init(v),siz[u]+=siz[v];
    dp[u].resize(min(m,siz[u])+1);
}

void dfs(int u) {
    int sz=1;
    dp[u][1]=s[u];
    for(int v:adj[u]) {
        dfs(v);
        for(int i=min(m,sz+siz[v]);i>=2;i--)
            for(int j=max(1,i-siz[v]);j<=min(i-1,sz);j++)
                dp[u][i]=max(dp[u][i],dp[u][j]+dp[v][i-j]);
        sz+=siz[v];
    }
}

void solve() {
    cin>>n>>m;
    m++;
    for(int i=1;i<=n;i++) {
        int p;
        cin>>p>>s[i];
        adj[p].push_back(i);
    }
    init(0);
    dfs(0);
    cout<<dp[0][m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}