#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10,mod=998244353;
LL dp[N],ans=1;
int p[N],e[N];
bool mark[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    dp[1]=1,dp[2]=3;
    for(int i=3;i<=n;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;

    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>e[p[i]];
    for(int i=1;i<=n;i++){
        int cur=i,cnt=0;
        while(!mark[cur]){
            mark[cur]=1;
            cur=e[cur];
            cnt++;
        }
        if(cnt>1) ans=(ans*dp[cnt])%mod;
    }
    cout<<ans;
    return 0;
}

/*

n大小的环，每相邻的连个点至少有一个要选

dp1[i][1]起点选，大小为i的环，i选
dp2[i][0]起点不选，大小为i的环，i不选

f[n]=n大小的环的方案数
f[n]=dp1[n][1]+dp1[n][0]+dp2[n][1]
    =dp1[n-1][1]+dp1[n-1][0]+dp1[n-1][1]+dp2[n-1][1]+dp2[n-1][0]
    =f[n-1]+dp1[n-1][1]+dp2[n-1][0]
    =f[n-1]+dp1[n-2][1]+dp1[n-2][0]+dp2[n-2][1]
    =f[n-1]+f[n-2]
     
f[n-1]=dp1[n-1][1]+dp1[n-1][0]+dp2[n-1][1]
f[n-2]=dp1[n-2][1]+dp1[n-2][0]+dp2[n-2][1]

dp[i][1]=dp[i-1][1]+dp[i-1][0]
dp[i][0]=dp[i-1][1]

*/