#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=110;
int a[N],b[N],dp[N][N*N*2];//前i个物品，体积为j是否合法

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,sum=0,res=0,ans=0;
        cin>>n;
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i],ans+=a[i]*a[i];
        for(int i=1;i<=n;i++) cin>>b[i],sum+=b[i],ans+=b[i]*b[i];
        for(int i=1;i<=n;i++) 
            for(int j=0;j<=sum/2;j++)
                if(dp[i-1][j])
                    dp[i][j+a[i]]=dp[i][j+b[i]]=1;
        ans=ans*(n-2);
        for(int i=1;i<=sum/2;i++) if(dp[n][i]) res=i;
        ans=ans+res*res+(sum-res)*(sum-res);
        cout<<ans<<endl;
    }
    return 0;
}