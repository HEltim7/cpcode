#include<iostream>
using namespace std;

const int V=110;
int dp[V][V];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,v,m;
    cin>>n>>v>>m;
    for(int i=1;i<=n;i++){
        int vi,mi,wi;
        cin>>vi>>mi>>wi;
        for(int j=v;j>=vi;j--)
            for(int k=m;k>=mi;k--)
                dp[j][k]=max(dp[j][k],dp[j-vi][k-mi]+wi);
    }
    cout<<dp[v][m];
    return 0;
}