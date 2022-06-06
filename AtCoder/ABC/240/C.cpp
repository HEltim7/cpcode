#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e2+10,M=1e4+10;
int dp[N][M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,x;
    cin>>n>>x;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        for(int j=0;j<M;j++){
            if(dp[i-1][j]&&j+a<=M) dp[i][j+a]=1;
            if(dp[i-1][j]&&j+b<=M) dp[i][j+b]=1;
        }
    }
    if(dp[n][x]) cout<<"Yes";
    else cout<<"No";
    return 0;
}