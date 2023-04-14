#include<iostream>
using namespace std;

const int N=310;
int prefix[N];
int dp[N][N];

#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>prefix[i],prefix[i]+=prefix[i-1];
    
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            for(int k=l;k<l+len-1;k++){
                if(!dp[l][l+len-1]) dp[l][l+len-1]=dp[l][k]+dp[k+1][l+len-1]+prefix[l+len-1]-prefix[l-1];
                else dp[l][l+len-1]=min(dp[l][l+len-1],dp[l][k]+dp[k+1][l+len-1]+prefix[l+len-1]-prefix[l-1]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}