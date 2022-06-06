#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
vector<int> adj[N],radj[N];
int dp[N];

void dfs(int u) {
    if(dp[u]) return;
    if(adj[u].size()<=1) {dp[u]=1;return;}
    dp[u]=1;
    for(int v:adj[u]){
        if(radj[v].size()>=2){
            dfs(v);
            dp[u]=max(dp[u],dp[v]+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!dp[i]) dfs(i);
    int ans=0;
    for(int i=1;i<=n;i++) 
        ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}