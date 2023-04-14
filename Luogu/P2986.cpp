#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef long long LL;
const int N=1e5+10;
VII adj[N];
LL n,ans,total;
LL c[N],tmp[N],cow[N],dp[N];

void dfs(int u,int fa){
    for(auto [x,d]:adj[u]){
        if(x==fa) continue;
        dfs(x,u);
        tmp[u]+=tmp[x]+cow[x]*d;
        cow[u]+=cow[x];
    }
    cow[u]+=c[u];
}

void getdp(int u,int fa){
    for(auto [x,d]:adj[u]){
        if(x==fa) continue;
        dp[x]=dp[u]+(total-2*cow[x])*d;
        getdp(x,u);
    }
    ans=min(ans,dp[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i],total+=c[i];
    for(int i=1;i<n;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    dfs(1,0);
    ans=dp[1]=tmp[1];
    getdp(1,0);
    cout<<ans;
    return 0;
}