#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N=1e5+10;
string hhh="nunhehheh";//前缀
LL dp[10][N];//从0开始
LL ans[N];
int suf[N];
int mod=998244353;

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string str;
        cin>>str;
        for(int i=0;i<=8;i++) memset(dp[i],0,sizeof (LL)*str.length());

        memset(ans,0,sizeof (LL)*str.length());
        for(int i=0;i<str.length();i++){
            if(i==0){
                if(str[i]=='n') dp[0][i]=1;
                continue;
            }
            //需要从大到小避免自己加自己
            for(int j=0;j<=8;j++) dp[j][i]=dp[j][i-1];

            if(str[i]=='n'){
                dp[2][i]=(dp[2][i]+dp[1][i-1])%mod;//nun
                dp[0][i]=(dp[0][i]+1)%mod;//n
            }
            else if(str[i]=='u'){
                dp[1][i]=(dp[1][i]+dp[0][i-1])%mod;//nu
            }
            else if(str[i]=='h'){
                ans[i]=(dp[7][i-1])%mod;//nunhehheh
                dp[6][i]=(dp[6][i]+dp[5][i-1])%mod;//nunhehh
                dp[5][i]=(dp[5][i]+dp[4][i-1])%mod;//nunheh
                dp[3][i]=(dp[3][i]+dp[2][i-1])%mod;//nunh
            }
            else if(str[i]=='e'){
                dp[7][i]=(dp[7][i]+dp[6][i-1])%mod;//nunhehhe
                dp[4][i]=(dp[4][i]+dp[3][i-1])%mod;//nunhe
            }
        }

        suf[str.length()]=0;
        for(int i=str.length()-1;i>=0;i--){
            suf[i]=suf[i+1];
            if(str[i]=='a') suf[i]++;
        }

        LL res=0;
        for(int i=0;i<str.length();i++){
            res=(res+ans[i]*(qpow(2,suf[i+1])-1)%mod)%mod;
        }
        printf("%lld\n",res);
    }
    return 0;
}