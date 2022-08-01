#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int mod=998244353;

LL qpow(LL a,LL b) {
    LL res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

template<typename T=long long,T mod=998244353> struct Modint {
    T v;
    T inv() {
        T res=1,a=v,b=mod-2;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }

    Modint &operator+=(const Modint &x) { v+=x.v; if(v>mod) v-=mod; return *this; }
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
using Mod=Modint<>;

void solve() {
    int n;
    cin>>n;
    Mod ans=1;
    for(int i=1;i<=n;i++) ans*=i;
    cout<<ans*qpow(2,n+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}