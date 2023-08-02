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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=210;
int ans[N][N],dp[N][N];

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(n+1),sz(1);
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=m;i++) {
        int in;
        cin>>in;
        if(m-i+1<=n) sz.emplace_back(in);
    }

    m=min(n,m);
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=0;k<=sz[i];k++) {
                dp[j][k]=max(dp[j-1][k],ans[i-1][j]);
                if(k>=a[j]) dp[j][k]=max(dp[j][k],dp[j-1][k-a[j]]+b[j]);
                ans[i][j]=max(ans[i][j],dp[j][k]);
            }
        }
    }

    int maxx=0;
    for(int i=1;i<=n;i++) maxx=max(maxx,ans[m][i]);
    cout<<maxx<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}