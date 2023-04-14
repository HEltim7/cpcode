#include<iostream>
using namespace std;

const int N=3010;
int a[N],b[N];
int dp[N][N];
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    for(int i=1;i<=n;i++){
        int maxx=0;//前缀max
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(a[i]==b[j]) dp[i][j]=max(dp[i][j],maxx+1);
            else if(a[i]>b[j]) maxx=max(maxx,dp[i][j]);
            ans=max(ans,dp[i][j]);
        }
    }
    
    cout<<ans;
    return 0;
}