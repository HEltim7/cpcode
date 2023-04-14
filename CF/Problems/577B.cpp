#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10;
bool dp[N][N];

void solve() {
    int n,m;
    cin>>n>>m;
    if(n>m) {
        cout<<"YES"<<endl;
        return;
    }

    for(int i=0;i<n;i++) {
        int in;
        cin>>in;
        dp[i+1][in%m]=1;
        for(int j=0;j<m;j++) {
            dp[i+1][j]|=dp[i][j];
            dp[i+1][(j+in)%m]|=dp[i][j];
        }
    }

    cout<<(dp[n][0]?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}