#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10,INF=0x3f3f3f3f;
int dp[N][2][2];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    debug(s);
    dp[0][0][1]=INF;
    dp[0][1][1]=INF;
    for(int i=1;i<=n;i++) {
        dp[i][0][0]=dp[i-1][0][1]+(s[i]=='1');
        dp[i][0][1]=min(dp[i-1][0][0],dp[i-1][1][0])+(s[i]=='1');
        dp[i][1][0]=dp[i-1][1][1]+(s[i]=='0');
        dp[i][1][1]=min(dp[i-1][1][0],dp[i-1][0][0])+(s[i]=='0');
        debug(i,dp[i][0][0],dp[i][0][1],dp[i][1][0],dp[i][1][1]);
    }
    cout<<min(dp[n][0][0],dp[n][1][0])<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}