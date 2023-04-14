#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef vector<int> VI;
typedef long long LL;
const int N=2e6+10;
VI adj[N];
LL dp[N],tmp[N],node[N];
int n,ans;

void dfs(int u,int fa){
    for(auto x:adj[u]){
        if(x==fa) continue;
        dfs(x,u);
        tmp[u]+=tmp[x]+node[x];
        node[u]+=node[x];
    }
    node[u]++;
}

void getdp(int u,int fa){
    for(auto x:adj[u]){
        if(x==fa) continue;
        dp[x]=dp[u]+n-2*node[x];
        getdp(x,u);
    }
    if(dp[ans]<dp[u]) ans=u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);
    dp[1]=tmp[1];
    getdp(1,0);
    cout<<ans;
    return 0;
}