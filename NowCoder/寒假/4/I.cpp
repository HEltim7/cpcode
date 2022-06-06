#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;
LL dp[N][N],num[N],val[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof dp);
    dp[0][0]=0;
    for(int i=1;i<=n;i++) cin>>num[i]>>val[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<k;j++){
            dp[i][j]=dp[i-1][j];
            LL pre=j-num[i];
            if(pre<0) pre=(pre+abs(pre/k)*k+k)%k;
            if(dp[i-1][pre]!=-1) dp[i][j]=max(dp[i][j],dp[i-1][pre]+val[i]);
        }
    cout<<(dp[n][0]?dp[n][0]:-1);
    return 0;
}