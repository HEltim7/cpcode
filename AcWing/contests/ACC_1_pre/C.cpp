#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=5e3+10;
LL pre[N];
LL dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        LL in;
        cin>>in;
        pre[i]=pre[i-1]+in;
    }
    for(int j=1;j<=k;j++){
        for(int i=m;i<=n;i++){
            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            dp[i][j]=max(dp[i-m][j-1]+pre[i]-pre[i-m],dp[i][j]);
        }
    }
    cout<<dp[n][k];
    return 0;
}