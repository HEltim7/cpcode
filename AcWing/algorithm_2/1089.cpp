#include<iostream>
using namespace std;

const int INF=0x3f3f3f3f;
const int N=2e5+10;
int dp[N];//前i个，且选i的花费的最小值
int beacon[N];
int que[N];
int ans=INF;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>beacon[i];
    
    int h=0,t=0;//第0个beacon已点燃
    for(int i=1;i<=n;i++){//维护长度为m的单调队列
        if(i-que[h]>m) h++;
        dp[i]=dp[que[h]]+beacon[i];
        while(dp[i]<=dp[que[t]]&&t>=h) t--;
        que[++t]=i;
    }
    for(int i=n;i+m>n;i--) ans=min(ans,dp[i]);
    cout<<ans;
    return 0;
}