#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=5e3+10;
int dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j]=0;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            for(int j=0;j<=n;j++){
                dp[i][j]=dp[i-1][j]+in;
                if(j) dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+in+x);
                dp[i][j]=max(dp[i][j],0);
            }
        }
        for(int i=0;i<=n;i++){
            int res=0;
            for(int j=1;j<=n;j++)
                res=max(res,dp[j][i]);
            cout<<res<<' ';
        }
        cout<<endl;
    }
    return 0;
}