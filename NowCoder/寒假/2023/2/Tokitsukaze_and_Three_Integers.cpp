#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=5e3+10;
int arr[N];
LL dp[2][3][N],ans[N];

void solve() {
    int n,p;
    cin>>n>>p;
    for(int i=1;i<=n;i++) cin>>arr[i],arr[i]%=p;
    dp[0][0][1%p]=1;
    for(int i=0;i<n;i++) {
        int cur=i&1,ne=cur^1;
        memset(dp[ne],0,sizeof dp[ne]);
        for(int j=0;j<3;j++) {
            for(int k=0;k<p;k++) {
                dp[ne][j][k]+=dp[cur][j][k];
                if(j<2) dp[ne][j+1][(k*arr[i+1])%p]+=dp[cur][j][k];
            }
        }
    }

    for(int i=1;i<=n;i++)
        for(int k=0;k<p;k++)
            ans[(arr[i]+k)%p]+=dp[n&1][2][k];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) ans[(arr[i]*arr[j]+arr[i])%p]--;
    for(int k=0;k<p;k++) cout<<ans[k]*2<<' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}