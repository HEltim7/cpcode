#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VII;
const int N=2e5+10;

LL n,total,ans;
LL c[N],csum[N];
LL tmp1[N],tmp2[N];
LL dp1[N],dp2[N];
VII adj[N];

void dfs(int u,int fa){
    for(auto [x,d]:adj[u]){
        if(x==fa) continue;
        dfs(x,u);
        csum[u]+=csum[x];
        tmp1[u]+=tmp1[x]+csum[x]*d;
        tmp2[u]+=tmp2[x]+tmp1[x]*d*2+csum[x]*d*d;
    }
    csum[u]+=c[u];
}

void getdp(int u,int fa){
    for(auto [x,d]:adj[u]){
        if(x==fa) continue;
        dp1[x]=dp1[u]+(total-2*csum[x])*d;
        LL len=dp1[u]-tmp1[x]-csum[x]*d;
        dp2[x]=dp2[u]+(len-tmp1[x])*2*d+(total-2*csum[x])*d*d;
        getdp(x,u);
    }
    ans=min(ans,dp2[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i],total+=c[i];
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    dfs(1,0);
    dp1[1]=tmp1[1];
    ans=dp2[1]=tmp2[1];
    getdp(1,0);
    cout<<ans;
    return 0;
}

/////////////该范围