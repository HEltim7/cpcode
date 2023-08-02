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
constexpr int N=1e3+10,LIM=50;
int dp[N][N],pre[N][N];

int dfs(int n,int m) {
    if(n<=0||m<=0) return 0;
    if(n==m&&n<=25) return 1;
    if(n==1||m==1) return max(n,m);
    if(dp[n][m]) return dp[n][m];

    auto div=[&](int len) {
        return dfs(len,len)+dfs(n-len,len)+dfs(len,m-len)+dfs(n-len,m-len);
    };

    dp[n][m]=55;
    for(int i=1;i<=min(n,m);i++) {
        int t=div(i);
        if(t<dp[n][m]) pre[n][m]=i;
        dp[n][m]=min(dp[n][m],t);
        if(n==m&&dp[n][m]<=LIM) return dp[n][m]=1;
    }
    return dp[n][m];
}

vector<tuple<int,int,int>> ans;
void find_ans(int r,int c,int n,int m) {
    if(n<=0||m<=0) return;
    if(n==m&&n<=25) {
        if(n<=1) return;
        if(n<=7) {
            ans.emplace_back(r,c,n);
            return;
        }
        for(int i=7;i<=n;i++) {
            ans.emplace_back(r,c,i);
        }
        return;
    }
    if(n==1||m==1) return;
    
    int t=pre[n][m];
    find_ans(r, c, t, t);
    find_ans(r+t, c, n-t, t);
    find_ans(r, c+t, t, m-t);
    find_ans(r+t, c+t, n-t, m-t);

    if(n==m) ans.emplace_back(r,c,n);
}

void solve() {
    int n;
    cin>>n;
    dfs(n,n);
    find_ans(1, 1, n, n);
    cout<<ans.size()<<endl;
    for(auto [x,y,z]:ans) cout<<x<<' '<<y<<' '<<z<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}