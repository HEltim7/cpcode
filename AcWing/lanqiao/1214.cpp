// 背包的《简 单》变种
// 注意取模得到的余数可能是负的，需要特别处理一下

#include<iostream>
using namespace std;
const int N=1e3+10;
const int MOD=100000007;
int dp[N][N];

#define mod(x) (x%n+n)%n

int main(){
    int n,a,s,b;
    cin>>n>>s>>a>>b;
    dp[0][0]=1;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<n;j++){
            dp[i][mod(j+i*a)]=(dp[i][mod(j+i*a)]+dp[i-1][j])%MOD;
            dp[i][mod(j-i*b)]=(dp[i][mod(j-i*b)]+dp[i-1][j])%MOD;
        }
    }
    cout<<dp[n-1][mod(s)]%MOD;
    return 0;
}