#include<iostream>
using namespace std;

typedef long long LL;

const int N=1e5+10;
int n,k;
LL px[N];//prefix
LL dp[N],que[N],g[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>px[i],px[i]+=px[i-1];

    int hh=0,tt=0;
    for(int i=1;i<=n;i++){
        if(i-que[hh]>k) hh++;
        dp[i]=max(dp[i-1],g[que[hh]]+px[i]);
        g[i]=dp[i-1]-px[i];
        while(g[i]>=g[que[tt]]&&tt>=hh) tt--;
        que[++tt]=i;
    }
    cout<<dp[n];
    return 0;
}