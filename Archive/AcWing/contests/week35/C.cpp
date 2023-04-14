#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=3e3+10,INF=0x3f3f3f3f;
typedef pair<int,int> PII;
int n,ans=INF;
int s[N],c[N];
int dp[N][N];//i位置，s大于等于j的c最小值

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(dp,0x3f,sizeof dp);
    cin>>n;
    PII tmp[N];
    for(int i=1;i<=n;i++) cin>>tmp[i].first,tmp[i].second=i;
    sort(tmp+1,tmp+1+n);
    int idx=0;
    for(int i=1;i<=n;i++) 
        if(tmp[i].first==tmp[i-1].first) s[tmp[i].second]=idx;
        else s[tmp[i].second]=++idx;

    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=n;i>=3;i--){
        for(int j=idx;j>=1;j--){
            dp[i][j]=min(dp[i][j+1],dp[i+1][j]);
            if(s[i]>=j) dp[i][j]=min(dp[i][j],c[i]);
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i]>=s[j]) continue;
            ans=min(ans,c[i]+c[j]+dp[j+1][s[j]+1]);
        }
    }
    if(ans==INF) cout<<-1;
    else cout<<ans;
    return 0;
}