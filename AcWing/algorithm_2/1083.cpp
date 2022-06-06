#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VI;

const int N=12;
int dp[N][10];//i位，最高位为j的方案

void init(){
    for(int i=0;i<=9;i++) dp[1][i]=1;

    for(int i=2;i<N;i++)
        for(int j=0;j<=9;j++)
            for(int k=0;k<=9;k++)
                if(abs(j-k)>=2)
                    dp[i][j]+=dp[i-1][k];
}

int dfs(int n){
    if(n==0) return 0;
    VI num;
    while(n) num.push_back(n%10),n/=10;

    int res=0,last=-1;//last表示上一个数
    for(int i=num.size()-1;i>=0;i--){//枚举每一位
        int x=num[i];
        //枚举每一个可能的数，且第一位不能是0
        for(int j=i==num.size()?1:0;j<x;j++){
            if(abs(j-last)>=2) res+=dp[i+1][j];
        }

        if(abs(x-last)>=2) last=x;
        else break;
        if(i==0) res++;
    }

    //特判前导零的情况，防止重复计算
    for(int i=1;i<num.size();i++)
        for(int j=1;j<=9;j++)
            res+=dp[i][j];

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a,b;
    cin>>a>>b;
    init();
    cout<<dfs(b)-dfs(a-1);
    return 0;
}