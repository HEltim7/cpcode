#include<iostream>
using namespace std;

typedef long long ll;
const int M=3010;
ll dp[M];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int v;
        cin>>v;
        for(int i=v;i<=m;i++) dp[i]+=dp[i-v];
    }
    cout<<dp[m];
    return 0;
}