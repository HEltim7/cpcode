#include<iostream>
using namespace std;

#define endl '\n'

const int N=1e5+10;
const int INF=0x3f3f3f3f;
int dp[N][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        dp[0][0]=0,dp[0][1]=-INF;
        for(int i=1;i<=n;i++){
            int money;
            cin>>money;
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+money;
        }
        cout<<max(dp[n][0],dp[n][1])<<endl;
    }
    return 0;
}