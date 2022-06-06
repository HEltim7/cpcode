#include<iostream>
using namespace std;

const int N=2e4+10;
int v,n;
int dp[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>v>>n;
    while(n--){
        int w;
        cin>>w;
        for(int i=v;i>=w;i--) dp[i]=max(dp[i],dp[i-w]+w);
    }
    cout<<v-dp[v];
    return 0;
}