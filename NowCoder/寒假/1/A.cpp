#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

const int N=10,M=1e5+10;
LL cnt[N],dp[N][N],res[N][N];
LL faet[M],infaet[M];
int mod=998244353;

inline int get(int x){
    int res=10;
    while(res>=10){
        res=0;
        while(x){
            res+=x%10;
            x/=10;
        }
        x=res;
    }
    return res;
}

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void init(){
    faet[1]=1,faet[0]=1;
    infaet[1]=1,infaet[0]=1;
    for(int i=2;i<=1e5;i++){
        faet[i]=faet[i-1]*i%mod;
        infaet[i]=infaet[i-1]*qpow(i,mod-2)%mod;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        cnt[get(in)]++;
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=cnt[i];j++){
            res[i][get(i*j)]=
                (res[i][get(i*j)]+faet[cnt[i]]*infaet[j]%mod*infaet[cnt[i]-j]%mod)%mod;
        }
    }
    for(int i=1;i<=9;i++) dp[1][i]=res[1][i],res[i][0]=1;
    dp[1][0]=1;
    for(int i=1;i<=8;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                dp[i+1][get(j+k)]=(dp[i+1][get(j+k)]+dp[i][j]*res[i+1][k]%mod)%mod;
            }
        }
    }
    for(int i=1;i<=9;i++) cout<<dp[9][i]<<' ';
    return 0;
}

/*

1 ---------
1 2 3 4 5 6 7 8 9 
2 ---------
2 4 6 8 1 3 5 7 9 
3 ---------
3 6 9 3 6 9 3 6 9 
4 ---------
4 8 3 7 2 6 1 5 9 
5 ---------
5 1 6 2 7 3 8 4 9 
6 ---------
6 3 9 6 3 9 6 3 9 
7 ---------
7 5 3 1 8 6 4 2 9 
8 ---------
8 7 6 5 4 3 2 1 9 
9 ---------
9 9 9 9 9 9 9 9 9

*/