#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define endl '\n'
typedef vector<int> VI ;

int mod;
const int N=12;
const int M=110;
int dp[N][N][M];//总共i位，最高位为j，各位总和%mod=k的方案数

void init(){
    for(int i=0;i<=9;i++) dp[1][i][i%mod]=1;
    
    for(int i=2;i<N;i++)
        for(int j=0;j<=9;j++)
            for(int x=0;x<=9;x++)
                for(int k=0;k<mod;k++)
                    dp[i][j][(k+j)%mod]+=dp[i-1][x][k];
}

int dfs(int n){
    if(n==0) return 0;
    VI num;
    while(n) num.push_back(n%10),n/=10;

    int res=0,last=0;
    for(int i=num.size()-1;~i;i--){
        int x=num[i];
        for(int j=i==num.size()-1?1:0;j<x;j++){
            res+=dp[i+1][j][(mod-last)%mod];
        }
        last=(last+x)%mod;
    }

    for(int i=0;i<num.size()-1;i++)
        for(int j=1;j<=9;j++)
            res+=dp[i+1][j][0];

    if(last==0) res++;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a,b;
    while(cin>>a>>b>>mod){
        memset(dp,0,sizeof dp);
        init();
        cout<<dfs(b)-dfs(a-1)<<endl;
    }
    return 0;
}