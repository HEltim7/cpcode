#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e3+10;
LL num[N],dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    sort(num+1,num+1+n);
    
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++) dp[1][i]=0;
    for(int i=1;i<n;i++)
        for(int j=1;j<=n;j++){
            int k=j+i-1;
            if(k>n) break;
            if(j>1) dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+num[k]-num[j-1]);
            if(k<n) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+num[k+1]-num[j]);
        }
    
    cout<<dp[n][1];
    return 0;
}