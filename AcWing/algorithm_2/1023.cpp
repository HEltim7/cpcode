#include<iostream>
using namespace std;

const int N=1e3+10;
int dp[N];
int book[5]={0,10,20,50,100};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=4;i++)
        for(int j=book[i];j<=n;j++)
            dp[j]+=dp[j-book[i]];

    cout<<dp[n];
    return 0;
}