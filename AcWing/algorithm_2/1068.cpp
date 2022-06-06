#include<iostream>
#include<cstring>
using namespace std;
#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=410;
const int INF=0x3f3f3f3f;
int pile[N];//n堆石子
int dp[N][N];//合并区间[l-r]的最小值
int pd[N][N];//合并区间[l-r]的最大值
int prefix[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pile[i],pile[i+n]=pile[i];
    for(int i=1;i<=n*2;i++) prefix[i]=prefix[i-1]+pile[i];

    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=2*n;i++) dp[i][i]=0;
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n*2;l++){
            int r=l+len-1;
            int sum=prefix[r]-prefix[l-1];
            for(int i=l;i<r;i++){
                dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+sum);
                pd[l][r]=max(pd[l][r],pd[l][i]+pd[i+1][r]+sum);
                // debug(l),debug(r),debug(dp[l][r]),debug(pd[l][r]);
            }
        }
    }
    int ans1=INF,ans2=0;
    for(int i=1;i<=n+1;i++) ans1=min(ans1,dp[i][i+n-1]),ans2=max(ans2,pd[i][i+n-1]);
    cout<<ans1<<endl<<ans2;
    return 0;
}