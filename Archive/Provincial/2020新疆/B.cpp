#include<iostream>
using namespace std;

#define endl '\n'
const int N=1e5+10;
typedef long long LL;
int n,d,m;
int a[N];
LL dp[2][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>d>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<=m){
            if(i-d-1>=1)
                dp[0][i]=max(dp[0][i-1],dp[1][i-d-1])+a[i];
            else dp[0][i]=dp[0][i-1]+a[i];
            dp[1][i]=max(dp[0][i],dp[1][i-1]);
        }
        else{
            if(i-d-1>=1)
                dp[0][i]=max(dp[0][i-1],dp[1][i-d-1]);
            else dp[0][i]=dp[0][i-1];
            dp[1][i]=max(dp[1][i-1],dp[0][i]+a[i]);
        }
    }
    cout<<max(dp[0][n],dp[1][n]);
    return 0;
}