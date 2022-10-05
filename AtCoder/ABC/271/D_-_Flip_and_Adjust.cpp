#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

constexpr int N=1e4+10,M=100+10;
bool dp[M][N];
int pre[M][N],res[M][N];

void solve() {
    int n,s;
    cin>>n>>s;
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        for(int j=s;j>=1;j--) {
            if(j>=a&&dp[i-1][j-a]) dp[i][j]=1,pre[i][j]=j-a,res[i][j]=1;
            if(j>=b&&dp[i-1][j-b]) dp[i][j]=1,pre[i][j]=j-b,res[i][j]=0;
        }
    }
    if(dp[n][s]) {
        cout<<"Yes"<<endl;
        int i=n,j=s;
        vector<char> ans;
        while(i&&j) {
            debug(i,j,res[i][j]);
            ans.push_back(res[i][j]?'H':'T');
            j=pre[i][j];
            i--;
        }
        reverse(ans.begin(),ans.end());
        for(auto x:ans) cout<<x;
    }
    else cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}