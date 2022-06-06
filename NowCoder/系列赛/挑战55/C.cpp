#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const LL mod=998244353;

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cout<<qpow(2,15);
}