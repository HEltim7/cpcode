#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e3+10,mod=1e9+7;
LL dp[N][N];//i个a,j对ab的概率
LL ans=0;
LL pa,pb;

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

inline LL cal(LL i,LL j){
    LL a=qpow((1-pa+mod)%mod,mod-2);
    return ((i+j)*pb%mod*a+pa*pb%mod*a%mod*a%mod)%mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int k,p,q;
    cin>>k>>p>>q;
    pa=1LL*p*qpow(p+q,mod-2)%mod;
    pb=1LL*q*qpow(p+q,mod-2)%mod;

    dp[1][0]=1;
    for(int i=1;i<k;i++)
        for(int j=0;j<k;j++){
            if(i+j<k){
                dp[i][j+i]=(dp[i][j+i]+dp[i][j]*pb)%mod;
                dp[i+1][j]=(dp[i+1][j]+dp[i][j]*pa)%mod;
            }
        }

    for(int i=1;i<=k;i++)
        for(int j=0;j<k;j++)
            if(i+j>=k)
                ans=(ans+dp[i][j]*cal(i,j)%mod)%mod;
            
    cout<<ans;
    return 0;
}