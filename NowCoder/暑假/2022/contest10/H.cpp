#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

template<typename T=long long,T mod=998244353> struct Modint {
    T v;
    T inv() const {
        T res=1,a=v,b=mod-2;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }

    Modint &operator+=(const Modint &x) { v+=x.v; if(v>=mod) v-=mod; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; if(v<0) v+=mod; return *this; }
    Modint &operator*=(const Modint &x) { v=v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=v*x.inv()%mod; return *this; }

    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }

    Modint operator++(int) { auto res=*this; *this+=1; return res; }
    Modint operator--(int) { auto res=*this; *this-=1; return res; }
    Modint operator-  () { return *this*-1; }
    Modint &operator++() { return *this+=1; }
    Modint &operator--() { return *this-=1; }

    bool operator< (const Modint&x) { return v< x.v; }
    bool operator> (const Modint&x) { return v> x.v; }
    bool operator<=(const Modint&x) { return v<=x.v; }
    bool operator>=(const Modint&x) { return v>=x.v; }
    bool operator==(const Modint&x) { return v==x.v; }
    bool operator!=(const Modint&x) { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(T x=0): v((x%=mod)<0?x+mod:x) {}
};
using Mint=Modint<>;

constexpr int N=2e6+10,mod=998244353;
LL faet[N],infaet[N];

LL qpow(LL a,LL b){
    LL  res=1;
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
    for(int i=2;i<N;i++){
        faet[i]=faet[i-1]*i%mod;
        infaet[i]=infaet[i-1]*qpow(i,mod-2)%mod;
    }
}

LL get(int a,int b){
    return faet[a]*infaet[a-b]%mod*infaet[b]%mod;
}

Mint cal(LL a,LL b) {
    Mint res;
    LL sum=a+b-1;
    for(int i=0;i<=a-1;i++) res+=get(sum,i);
    return res/qpow(2,sum);
}

void solve() {
    init();
    int a,b,in;
    cin>>a;
    for(int i=1;i<=7;i++) cin>>in;
    cin>>b;
    for(int i=1;i<=7;i++) cin>>in;
    LL A=(a+9)/10,B=(b+9)/10;
    Mint ans;
    if(A<=B) ans=cal(A,B);
    else ans=1-cal(B,A);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}