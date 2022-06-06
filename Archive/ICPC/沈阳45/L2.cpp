#include<iostream>
#include<vector>
#include<algorithm>
#include<debug>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=4e3+10,mod=998244353;

LL dp[N][N][2];
vector<int> adj[N];
int sz[N];

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void dfs(int x,int fa){
    sz[x]=1;
    dp[x][0][0]=1;
    for(auto s:adj[x]){
        if(s==fa) continue;
        dfs(s,x);
        for(int i=sz[x];~i;i--)
            for(int j=sz[s];j>0;j--){
                dp[x][i+j+1][1]=(dp[x][i+j+1][1]+dp[x][i][0]*dp[s][j][0]%mod)%mod;
                dp[x][i+j][0]=(dp[x][i+j][0]+dp[x][i][0]*(dp[s][j][0]+dp[s][j][1])%mod)%mod;
            }
        sz[x]+=sz[s];
    }
    if(sz[x]==1) dp[x][0][1]=0,dp[x][0][0]=1;
    debug(x,sz[x]);
    for(int i=0;i<=sz[x];i++) debug(i,dp[x][i][0],dp[x][i][1]);
    cout<<"----"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<n*2;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
    // for(int i=0;i<=sz[1];i++)
    //     debug(i,dp[1][i][0],dp[1][i][1]);
    return 0;
}