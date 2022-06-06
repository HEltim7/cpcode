#include<iostream>
using namespace std;

const int M=1e4+10;
int dp[M];//从前i个物品选，总和为j的方案数

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        for(int j=m;j>=a;j--) dp[j]+=dp[j-a]+1;
    }
    cout<<dp[m];
    return 0;
}