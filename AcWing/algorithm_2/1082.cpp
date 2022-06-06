#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VI;

const int N=35;
int dp[N][N];//总共有i位且最高位为j的的方案数
int a,b;

void init(){
    for(int i=1;i<=9;i++) dp[1][i]=1;
    for(int i=2;i<=N-1;i++)
        for(int j=0;j<=9;j++)
            for(int k=j;k<=9;k++)
                dp[i][j]+=dp[i-1][k];
}

int sol(int n){
    if(n==0) return 0;
    int last=0,res=0;
    VI num;
    while(n) num.push_back(n%10),n/=10;
    for(int i=num.size()-1;i>=0;i--){
        int x=num[i];
        if(x<last) break;
        for(int j=last;j<x;j++) res+=dp[i+1][j];
        last=x;
        if(i==0) res++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    while(cin>>a>>b) cout<<sol(b)-sol(a-1)<<endl;
    return 0;
}