#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=3e5+10;
const LL INF=0x3f3f3f3f3f3f3f3f;
vector<PII> adj[N];
LL dp[2][N];
int d[N];

void dfs(int u,int fa) {
    vector<LL> cur(1,0);
    for(auto [v,w]:adj[u]) {
        if(v==fa) continue;
        dfs(v,u);
        dp[0][u]+=dp[1][v];
        dp[1][u]+=dp[1][v];
        if(dp[0][v]+w>dp[1][v])
            cur.push_back(dp[0][v]+w-dp[1][v]);
    }
    sort(next(cur.begin()),cur.end(),greater<LL>());
    int n=cur.size()-1;
    for(int i=1;i<=n;i++) cur[i]+=cur[i-1];
    if(d[u]==0) dp[0][u]=-INF;
    else {
        dp[0][u]+=cur[min(n,d[u]-1)];
        dp[1][u]+=cur[min(n,d[u])];
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    dfs(1,-1);
    cout<<dp[1][1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}