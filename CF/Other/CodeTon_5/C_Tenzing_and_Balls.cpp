#include <algorithm>
#include <array>
#include <cassert>
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

constexpr int N=2e5+10;
int arr[N],dp[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) dp[i]=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int ans=0;
    for(int i=1;i<=n;i++) {
        dp[arr[i]]=max(dp[arr[i]],dp[arr[i]]);
        ans=max(ans,dp[arr[i]]+i);
        dp[arr[i]]=max(dp[arr[i]],dp[arr[i-1]]);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}