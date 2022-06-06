#include <iostream>
using namespace std;

const int N=1010;
int dp[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,v;
    cin>>n>>v;
    for(int i=1;i<=n;i++){
        int vol,val,s;
        cin>>vol>>val>>s;
        if(s==0) for(int j=vol;j<=v;j++) dp[j]=max(dp[j],dp[j-vol]+val);
        else{
            if(s==-1) s=1;
            for(int k=1;k<=s;k*=2){
                for(int j=v;j>=vol*k;j--) dp[j]=max(dp[j],dp[j-vol*k]+val*k);
                s-=k;
            }
            if(s) for(int j=v;j>=vol*s;j--) dp[j]=max(dp[j],dp[j-vol*s]+val*s);
        }
    }
    cout<<dp[v];
    return 0;
}