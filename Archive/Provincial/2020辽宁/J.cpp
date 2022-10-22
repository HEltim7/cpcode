#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=110;
const int mod=1e9+7;

int n,m,k;
LL dp[N][N];
LL cmb[N][N];
LL cmbp[N][N][N];

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void get_cmb(){

}

void init(){

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    
}