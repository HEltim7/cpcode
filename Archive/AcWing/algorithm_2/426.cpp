#include<iostream>
using namespace std;

const int N=3e4+10;
int dp[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    int volume,value;
    for(int i=1;i<=m;i++){
        cin>>volume>>value;
        for(int j=n;j>=volume;j--)
            dp[j]=max(dp[j],dp[j-volume]+value*volume);
    }
    cout<<dp[n];
    return 0;
}