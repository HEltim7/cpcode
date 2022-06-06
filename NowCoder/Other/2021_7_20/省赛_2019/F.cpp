#include<iostream>
using namespace std;

#define endl '\n'
const int mod=1e9+7;
typedef long long LL;
LL two;

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL n,a,b,c,d;
    LL two=qpow(2,mod-2);
    while(cin>>n>>a>>b>>c>>d){
        LL part1=(a*b%mod+a*d%mod+b*c%mod+c*d%mod)%mod;
        part1=part1*(n*(n-1)%mod)%mod;
        part1=part1*two%mod;
        LL ans=((a+b+c+d)%mod*n)%mod+1;
        cout<<(ans+part1)%mod<<endl;
    }
    return 0;
}