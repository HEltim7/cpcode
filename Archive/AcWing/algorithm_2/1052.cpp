#include<iostream>
#include<cstring>
using namespace std;

const int N=55;
const int mod=1e9+7;
int ne[N];
char s[N],t[N];
int lent,lens;
int dp[N][N];//构造到第i位置，kmp匹配到j的方案数

void kmp(){
    ne[1]=1,ne[2]=1;
    for(int i=2,j=1;i<=lent;i++){
        while(t[i]!=t[j]&&j>1) j=ne[j];
        if(t[i]==t[j]) j++;
        ne[i+1]=t[i+1]==t[j]?ne[j]:j;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>lens>>t+1;
    lent=strlen(t+1);
    kmp();
    
    dp[0][1]=1;//状态机入口
    for(int i=1;i<=lens;i++){//构造到第i位置
        for(int j=1;j<=lent;j++){//kmp匹配到j
            for(char c='a';c<='z';c++){//暴力枚举所有字符
                //开始字符串匹配
                int tmp=j;
                while(c!=t[tmp]&&tmp>1) tmp=ne[tmp];
                if(c==t[tmp]) tmp++;
                //状态转移
                if(tmp<=lent) dp[i][tmp]=(dp[i][tmp]+dp[i-1][j])%mod;
            }
        }
    }
    int ans=0;//统计所有可行方案（出口
    for(int i=1;i<=lent;i++) ans=(ans+dp[lens][i])%mod;
    cout<<ans;
    return  0;
}