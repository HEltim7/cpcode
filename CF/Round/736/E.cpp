#include<iostream>
using namespace std;

#define endl '\n'

typedef long long LL;
const int N=3e6+10;
const int M=2e5+10;
LL fact[N];//阶乘
LL infact[N];//阶乘逆元
int n,q,x;
int mod=1e9+7;
int dp[M][3];

int qpow(LL a,int b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void factorial(){
    fact[0]=1,infact[0]=1;
    for(int i=1;i<=N;i++){
        fact[i]=fact[i-1]*i%mod;
        infact[i]=infact[i-1]*qpow(i,mod-2)%mod;
    }
}

int cmb(int a,int b){
    return fact[a]*infact[b]%mod*infact[a-b]%mod;
}

void getdp(){
    dp[0][0]=dp[0][1]=dp[0][2]=n;
    for(int i=1;i<=M;i++){
        dp[i][0]=(cmb(3*n,i+1)-2*dp[i-1][0]-dp[i-1][1])/3;
        dp[i][1]=dp[i][0]+dp[i-1][0];
        // dp[i][2]=dp[i][1]+dp[i-1][1];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    factorial();
    getdp();
    while(q--){
        cin>>x;
        cout<<dp[x][0]+cmb(3*n,x)<<endl;
    }
    return 0;
}