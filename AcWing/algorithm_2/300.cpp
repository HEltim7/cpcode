#include<iostream>
using namespace std;

typedef long long LL;

const int N=5e3+10;
LL dp[N];//前i-1已经处理完的集合
LL pxc[N],pxt[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>pxt[i],pxt[i]+=pxt[i-1];
        cin>>pxc[i],pxc[i]+=pxc[i-1];
    }

    for(int i=1;i<=n;i++){
        dp[i]=pxt[i]*pxc[i]+s*pxc[n];
        for(int j=1;j<i;j++){
            dp[i]=min(dp[i],dp[j]+pxt[i]*(pxc[i]-pxc[j])+s*(pxc[n]-pxc[j]));
        }
    }
    cout<<dp[n];
    return 0;
}