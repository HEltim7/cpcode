#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define endl '\n'
typedef vector<int> VI;

const int N=12;
int dp[N][N];//i位，最高位为j且合法的方案数

void init(){
    for(int i=0;i<=9;i++) if(i==4) continue; else dp[1][i]=1;
    for(int i=2;i<N;i++){
        for(int j=0;j<=9;j++){
            if(j==4) continue;
            for(int k=0;k<=9;k++){
                if(k==4) continue;
                dp[i][j]+=dp[i-1][k];
            }
            if(j==6) dp[i][j]-=dp[i-1][2];
        }
    }
}

int dfs(int n){
    if(n==0) return 1;
    VI num;
    while(n) num.push_back(n%10),n/=10;

    int res=0,last=0;
    for(int i=num.size()-1;~i;i--){
        int x=num[i];
        for(int j=0;j<x;j++){
            if(last==6&&j==2||j==4) continue;
            res+=dp[i+1][j];
        }
        if(x==4||last==6&&x==2) break;
        else last=x;
        if(i==0) res++;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    init();
    while(cin>>n>>m&&n&&m) cout<<dfs(m)-dfs(n-1)<<endl;
    return 0;
}