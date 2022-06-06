#include<iostream>
using namespace std;

const int M=6010;
int dp[M];//在前i个物品选，总体积不超过j的最大值

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int v,w,s;
        cin>>v>>w>>s;
        for(int k=1;k<=s;k*=2){
            for(int j=m;j>=v*k;j--)
                dp[j]=max(dp[j],dp[j-v*k]+w*k);
            s-=k;
        }
        if(s) for(int j=m;j>=s*v;j--) dp[j]=max(dp[j],dp[j-v*s]+w*s);
    }
    cout<<dp[m];
    return 0;
}