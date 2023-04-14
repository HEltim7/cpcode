#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e2+5;
LL pre[N],arr[N];
LL dp[N][N];

LL cal(int l,int r) {
    LL len=pre[r]-pre[l-1];
    return len*len;
}

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    n--;
    for(int i=n;i>=1;i--) arr[i]=arr[i]-arr[i-1];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+arr[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            for(int k=0;k<=j;k++)
                dp[i][j]=max(dp[i][j],dp[i-k-1][j-k]+cal(i-k,i));
    for(int i=1;i<=n+1;i++) cout<<(i*2>=n-1?dp[n][n-1]:dp[n][i*2])<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}