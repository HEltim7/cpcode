#include<iostream>
using namespace std;

const int INF=0x3f3f3f3f;
const int N=5e4+10;
int n,t;
int cost[N];
int dp[N];//前i位都合法且选第i位的方案
int que[N];

bool check(int m){//判断当前空段是否可达
    int hh=0,tt=0;
    for(int i=1;i<=n;i++){//单调队列维护dp
        if(i-que[hh]>m+1) hh++;
        dp[i]=dp[que[hh]]+cost[i];
        while(dp[i]<=dp[que[tt]]&&tt>=hh) tt--;
        que[++tt]=i;
    }

    int res=INF;
    for(int i=n;i>=1;i--) if(i+m>=n) res=min(dp[i],res); else break;
    if(res<=t) return true; else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>t;
    for(int i=1;i<=n;i++) cin>>cost[i];

    int l=0,r=n;
    while(l<r){//二分最大空段
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }

    cout<<r;
    return 0;
}