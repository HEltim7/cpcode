#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=4e3+10,mod=998244353;

LL dp[N][2];
vector<int> adj[N];

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

#ifdef __LOCAL
#include<debug>
#else
#define debug(...)
#endif

void dfs(int x,int fa){
    dp[x][0]=dp[x][1]=1;
    LL sum=1;
    int cnt=0;
    for(auto s:adj[x]){
        if(s==fa) continue;
        dfs(s,x);
        sum=sum*(dp[s][0]+dp[s][1])%mod;
        cnt++;
    }
    dp[x][0]=sum;
    for(auto s:adj[x])
        if(s!=fa) {
            LL t=sum*qpow((dp[s][1]+dp[s][0])%mod,mod-2)%mod*dp[s][0]%mod;
            dp[x][1]=dp[x][1]*t%mod;
        }
    if(cnt==0) dp[x][1]=0;
    debug(x,dp[x][0],dp[x][1]);
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
    return 0;
}