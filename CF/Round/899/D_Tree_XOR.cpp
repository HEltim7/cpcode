#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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
constexpr int N=2e5+10,K=21;
vector<int> adj[N];
int arr[N];
LL sz[N],dp[K][N][2],sum1[K][N][2],sum2[K][N][2];
LL ans[N];

void dfs1(int u,int fa,int b) {
    sz[u]=1;
    for(int v:adj[u]) {
        if(v!=fa) {
            dfs1(v, u, b);
            sz[u]+=sz[v];
            sum1[b][u][0]+=dp[b][v][0];
            sum1[b][u][1]+=dp[b][v][1];
        }
    }

    bool x=arr[u]>>b&1;
    dp[b][u][x]=sum1[b][u][x];
    dp[b][u][!x]=sum1[b][u][x]+sz[u];
}

int n;
void dfs2(int u,int fa) {
    for(int v:adj[u]) {
        if(v!=fa) {
            for(int b=0;b<K;b++) {
                LL szu=n-sz[v];
                array<LL,2> sumu{},dpu{};
                sumu[0]=sum2[b][u][0]-dp[b][v][0];
                sumu[1]=sum2[b][u][1]-dp[b][v][1];
                bool x=arr[u]>>b&1;
                dpu[x]=sumu[x];
                dpu[!x]=sumu[x]+szu;
                
                x=arr[v]>>b&1;
                sum2[b][v][0]=sum1[b][v][0]+dpu[0];
                sum2[b][v][1]=sum1[b][v][1]+dpu[1];
                ans[v]+=(1LL<<b)*sum2[b][v][x];
            }
            dfs2(v, u);
        }
    }
}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    constexpr int rt=1;
    for(int b=0;b<K;b++) dfs1(rt, 0, b);
    for(int b=0;b<K;b++) 
        sum2[b][rt][0]=sum1[b][rt][0],
        sum2[b][rt][1]=sum1[b][rt][1];

    dfs2(rt, 0);
    for(int b=0;b<K;b++) {
        int x=arr[rt]>>b&1;
        ans[rt]+=(1LL<<b)*dp[b][rt][x];
    }
    
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++) {
        ans[i]=0;
        adj[i].clear();
        for(int b=0;b<K;b++) {
            sum1[b][i][0]=sum1[b][i][1]=0;
            sum2[b][i][0]=sum2[b][i][1]=0;
            dp[b][i][0]=dp[b][i][1]=0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}