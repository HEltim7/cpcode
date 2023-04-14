#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10,INF=1e9;
int dp[N][N];
bool color[N];
vector<int> adj[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>color[i];
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=INF;
    dp[1][n]=0;
    queue<pair<int,int>> q;
    q.emplace(1,n);
    while(q.size()) {
        auto [u,v]=q.front();
        q.pop();
        for(int x:adj[u])
            for(int y:adj[v])
                if(color[x]^color[y])
                    if(dp[x][y]>dp[u][v]+1) {
                        dp[x][y]=dp[u][v]+1;
                        q.emplace(x,y);
                    }
    }
    cout<<(dp[n][1]==INF?-1:dp[n][1])<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}