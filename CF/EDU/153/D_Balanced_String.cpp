#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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
constexpr int N=105,M=2600;
int dp[N][N][M*2+10];

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;
    vector<int> arr(n+1);
    int zero=0;
    for(int i=1;i<=n;i++) arr[i]=s[i]=='1',zero+=!arr[i];

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][M]=0;
    for(int i=0;i<n;i++) {
        int mx=(i+1)/2*(i/2);
        for(int j=0;j<=i;j++) {
            int pre0=j,pre1=i-j;
            for(int k=-mx;k<=mx;k++) {
                assert(k-pre1+M>=0&&k-pre1+M<M*2+10);
                assert(k+pre0+M>=0&&k+pre0+M<M*2+10);
                dp[i+1][j+1][k-pre1+M]=min(dp[i+1][j+1][k-pre1+M],dp[i][j][k+M]+arr[i+1]);
                dp[i+1][j][k+pre0+M]=min(dp[i+1][j][k+pre0+M],dp[i][j][k+M]+!arr[i+1]);
            }
        }
    }

    cout<<dp[n][zero][M]/2<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

/*
大杀伤力hack数据
010000100000100010001011010010000110010011000101010001100100110111000101110111011110100110101
4
*/