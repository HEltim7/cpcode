#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10;
vector<pair<int,int>> adj[N];
int dp[N][3],ans[N];

void dfs1(int x,int fa){
    dp[x][1]=dp[x][2]=1;
    for(auto [s,d]:adj[x]){
        if(s==fa) continue;
        dfs1(s,x);
        if(d==1) dp[x][1]++,dp[x][2]+=dp[s][1];
        else if(d==2) dp[x][2]++;
    }
}

void dfs2(int x,int fa,int dis){
    ans[x]+=dp[x][2];
    if(dis==1) ans[x]+=dp[fa][1]-1;
    else if(dis==2) ans[x]++;

    for(auto [s,d]:adj[x])
        if(s!=fa) dfs2(s,x,d);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(i,b);
        adj[i].emplace_back(a,b);
    }
    dfs1(1,-1);
    dfs1(1,-1);
    dfs2(1,-1,3);
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
    return 0;
}