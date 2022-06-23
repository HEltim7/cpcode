#include<array>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=5e4+10;

void solve() {
    int n,x,ans=0;
    array<int,N> arr,dp[2];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    cin>>x;
    for(int i=1,pre=0;i<=n+1;i++) {
        if(i>=2&&arr[i]+arr[i-1]>=2*x) dp[1][i]=dp[0][i-2]+2;
        if(i>=3&&arr[i]+arr[i-1]>=2*x&&arr[i]+arr[i-1]+arr[i-2]>=3*x)
            dp[1][i]=max(dp[1][i],dp[1][i-1]+1);
        dp[0][i]=max(dp[1][i-1],dp[0][i-1]);
        if(i>=2) dp[0][i]=max(dp[0][i],dp[0][i-2]+1);
    }
    cout<<dp[0][n+1]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}