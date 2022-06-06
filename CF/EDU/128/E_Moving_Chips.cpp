#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int grid[2][N];
int dp[2][N];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void solve(){
    int n;
    cin>>n;
    int maxx=1,minn=n;
    for(int i=0;i<=1;i++) {
        for(int j=1;j<=n;j++){
            char in;
            cin>>in;
            if(in=='*') grid[i][j]=1,maxx=max(maxx,j),minn=min(minn,j);
            else grid[i][j]=0;
        }
    }
    dp[0][minn]=grid[1][minn];
    dp[1][minn]=grid[0][minn];
    for(int i=minn+1;i<=n;i++){
        dp[0][i]=min(dp[0][i-1]+1+grid[1][i],dp[1][i-1]+2);
        dp[1][i]=min(dp[1][i-1]+1+grid[0][i],dp[0][i-1]+2);
    }
    debug(dp[0],1,n);
    debug(dp[1],1,n);
    cout<<min(dp[0][maxx],dp[1][maxx])<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}