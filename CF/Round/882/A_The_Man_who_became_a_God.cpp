#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int arr[N],dp[N][N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            dp[i][j]=min(dp[i-1][j]+abs(arr[i]-arr[i-1]),dp[i-1][j-1]);
        }
    }
    cout<<dp[n][k]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}