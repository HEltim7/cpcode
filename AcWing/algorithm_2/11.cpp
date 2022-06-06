#include<iostream>
using namespace std;

const int N=1010;
const int mod=1e9+7;
int dp[N];//体积恰好为i的最大值
int ans[N];//体积恰好为i的方案数

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,v;
    cin>>n>>v;
    ans[0]=1;
    for(int i=1;i<=n;i++){
        int vol,val;
        cin>>vol>>val;
        for(int j=v;j>=vol;j--){
            if(!ans[j-vol]) continue;
            if(dp[j]<dp[j-vol]+val){
                ans[j]=ans[j-vol];
                dp[j]=dp[j-vol]+val;
            }
            else if(dp[j]==dp[j-vol]+val){
                ans[j]=(ans[j]+ans[j-vol])%mod;
            }
        }
    }
    int maxi=1,res=0;
    for(int i=2;i<=v;i++) if(dp[i]>dp[maxi]) maxi=i;
    for(int i=1;i<=v;i++) if(dp[i]==dp[maxi]) res=(res+ans[i])%mod;
    cout<<res;
    return 0;
}