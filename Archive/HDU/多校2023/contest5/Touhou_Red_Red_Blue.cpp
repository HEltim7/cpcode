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
constexpr int N=1e5+10;
const string rgb="XRGB";
int dp[N][4][4];

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;
    int ans=0;
    if(n<=2) {
        cout<<0<<endl;
        return;
    }
    
    auto getc=[&](int x) {
        return find(rgb.begin(),rgb.end(),s[x])-rgb.begin();
    };

    for(int i=1;i<=n;i++) 
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                dp[i][j][k]=-N;
    for(int i=1;i<=n;i++)
        dp[i][getc(i)][0]=0;

    for(int i=1;i<n;i++) {
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
        int c=getc(i+1);
        for(int j=1;j<4;j++) dp[i+1][j][c]=max(dp[i+1][j][c],dp[i][j][0]);
        for(int j=1;j<4;j++) {
            for(int k=1;k<4;k++) {
                if(dp[i][j][k]>=0) {
                    if(c==j&&c==k) {
                        for(int x=1;x<4;x++)
                            dp[i+1][x][0]=max(dp[i+1][x][0],dp[i][j][k]+1);
                    }
                    else if(c!=j&&c!=k&&j!=k) {
                        for(int x=1;x<4;x++)
                            for(int y=1;y<4;y++)
                                dp[i+1][x][y]=max(dp[i+1][x][y],dp[i][j][k]);
                    }
                    else {
                        dp[i+1][k][c]=max(dp[i+1][k][c],dp[i][j][k]);
                    }
                }
            }
        }
    }
    for(int i=1;i<4;i++)
        for(int j=0;j<4;j++)
            ans=max(ans,dp[n][i][j]);
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