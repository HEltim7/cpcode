#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2.5e3+10,X=1e4+10;
bool dp[N][X];

void solve() {
    int n,x,idx=0;
    cin>>n>>x;
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        for(int j=1;j<=b;j++) {
            idx++;
            for(int k=0;k<=x;k++) {
                if(k>=a) dp[idx][k]|=dp[idx-1][k-a];
                dp[idx][k]|=dp[idx-1][k];
            }
        }
    }
    cout<<(dp[idx][x]?"Yes":"No");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}