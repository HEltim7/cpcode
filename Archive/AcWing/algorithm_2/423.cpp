#include<iostream>
using namespace std;

#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=1e3+10;
int dp[N];
int t,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        int v,w;
        cin>>v>>w;
        for(int j=t;j>=v;j--) dp[j]=max(dp[j],dp[j-v]+w);
    }
    cout<<dp[t];
    return 0;
}