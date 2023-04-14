#include<iostream>
using namespace std;

const int __INF=0xcfcfcfcf;
const int N=1e5+10;
int dp[N][3];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    dp[0][0]=__INF;
    dp[0][1]=__INF;
    for(int i=1;i<=n;i++){
        int price;
        cin>>price;
        dp[i][0]=max(dp[i-1][0],dp[i-1][2]-price);
        dp[i][1]=dp[i-1][0]+price;
        dp[i][2]=max(dp[i-1][2],dp[i-1][1]);
    }
    cout<<max(dp[n][2],dp[n][1]);//这里实际上还是要两个出口取max
    return 0;
}