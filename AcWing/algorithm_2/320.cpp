#include<iostream>
using namespace std;

const int N=310;
int dp[N][N];
int beads[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>beads[i],beads[i+n]=beads[i];

    for(int len=3;len<=n+1;len++){
        for(int l=1;l<=n*2-2;l++){
            int r=l+len-1;
            for(int k=l+1;k<=r-1;k++){
                dp[l][r]=max(dp[l][r],dp[l][k]+dp[k][r]+beads[l]*beads[k]*beads[r]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i][i+n]);
    cout<<ans;
    return 0;
}