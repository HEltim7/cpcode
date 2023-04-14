#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e3+10,M=1<<(__lg(N)+1);
int dp[N][M+10],arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];

    for(int i=0;i<=n;i++) for(int j=0;j<M;j++) dp[i][j]=N;
    dp[0][0]=0;
    for(int i=0;i<n;i++) {
        dp[i+1][0]=min(dp[i+1][0],dp[i][0]+(arr[i+1]>0));
        for(int j=0;j<M;j++)
            dp[i+1][j^arr[i+1]]=min(dp[i+1][j^arr[i+1]],dp[i][j]+(j>0));
        dp[i+2][arr[i+1]^arr[i+2]]=min(dp[i+2][arr[i+1]^arr[i+2]],dp[i][0]+(arr[i+1]>0));
    }
    cout<<dp[n][0]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}