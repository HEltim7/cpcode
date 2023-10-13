#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    constexpr int INF=1e9;
    auto dp=vector(n,vector<int>(n,INF));
    int ans=k-1;
    for(int i=0;i<n;i++) dp[i][i]=0;
    for(int i=0;i+1<n;i++) if(s[i]==s[i+1]) dp[i][i+1]=0,ans=min(ans,max(0,k-2));
    for(int len=3;len<=n;len++) {
        for(int i=0,j=i+len-1;j<n;i++,j++) {
            if(s[i]==s[j]) {
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                if(s[i+1]==s[j]) dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                if(s[i]==s[j-1]) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                
                int cnt=max({0,k-(j-i+1),dp[i][j]});
                ans=min(ans,cnt);
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}