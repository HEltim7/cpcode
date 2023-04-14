#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e3+10;
int arr[N],dp[N],cnt[N];
bool del[N][N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];

    for(int i=1;i<=n;i++) {
        int num=0;
        for(int j=i;j<=n;j++) {
            del[i][j]=0;
            int len=j-i+1;
            cnt[arr[j]]++;
            if(cnt[arr[j]]*2>len) num=arr[j];
            if(cnt[num]*2<=len) num=0;
            if(len%2==0&&!num) del[i][j]=1;
        }
        for(int j=i;j<=n;j++) cnt[arr[j]]=0;
    }

    dp[1]=1;
    for(int i=2;i<=n;i++) {
        if(del[1][i-1]) dp[i]=1; else dp[i]=0;
        for(int j=1;j<i;j++) 
            if(arr[j]==arr[i]&&dp[j]&&(j+1==i||del[j+1][i-1]))
                dp[i]=max(dp[i],dp[j]+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++) if(i==n||del[i+1][n]) ans=max(ans,dp[i]);
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