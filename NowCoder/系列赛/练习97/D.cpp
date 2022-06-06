#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e6+10,mod=998244353;
LL dp[N][2];
LL n,x,y;
vector<int> adj[N];
LL faet[N],infaet[N];

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void init(){
    faet[1]=1,faet[0]=1;
    infaet[1]=1,infaet[0]=1;
    for(int i=2;i<N;i++){
        faet[i]=faet[i-1]*i%mod;
        infaet[i]=infaet[i-1]*qpow(i,mod-2)%mod;
    }
}

//a中选b个
inline LL cmb(int a,int b){
    return faet[a]*infaet[a-b]%mod*infaet[b]%mod;
}

void dfs(int root,int fa){
    int cnt=0;
    dp[root][0]=dp[root][1]=1;
    LL zero=1,one=1;
    for(auto s:adj[root]){
        if(s==fa) continue;
        dfs(s,root);
        cnt++;
        zero=zero*(dp[s][0]*x%mod+dp[s][1]*y%mod)%mod;
    }
    dp[x][0]=zero;
    if(cnt<y) dp[root][1]=dp[root][0];
    else{
        for(int i=0;i<=y;i++){
            one=1;
            for(auto s:adj[root]){
                if(s==fa) continue;
                LL tmp=0;
                tmp+=dp[s][0]*x%mod;
                tmp=(tmp+dp[s][1]*y%mod)%mod;
                one=one*tmp%mod;
            }
            dp[root][1]=(dp[root][1]+one)%mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>x>>y;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    init();
    dfs(1,-1);
    LL ans=(dp[1][0]*x%mod+dp[1][1]%mod*y%mod)%mod;
    cout<<ans;
    return 0;
}