#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
constexpr LL INF=1e12;
LL arr[N],dp[N][3];
vector<int> adj[N];

void dfs(int u,int fa) {
    int cnt=0;
    for(int v:adj[u]) {
        if(v!=fa) {
            dfs(v, u);
            cnt++;
        }
    }

    if(!cnt) {
        dp[u][0]=0;
        dp[u][1]=arr[u];
        dp[u][2]=INF;
    }
    else {
        dp[u][1]=arr[u];
        LL minn=INF;
        for(int v:adj[u]) {
            if(v!=fa) {
                dp[u][0]+=dp[v][2];
                dp[u][1]+=min({dp[v][0],dp[v][1],dp[v][2]});
                dp[u][2]+=min(dp[v][1],dp[v][2]);
                minn=min(minn,max(0LL,dp[v][1]-dp[v][2]));
            }
        }
        dp[u][2]+=minn;
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) adj[i].clear(),memset(dp[i],0,sizeof dp[i]);
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout<<min(dp[1][1],dp[1][2])<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}