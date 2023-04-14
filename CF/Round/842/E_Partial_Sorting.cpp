#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int mod;
template<typename I,typename L,const I &mod> struct Modint {
    I v;
    I pow(L b) const {
        L res=1,a=v;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }
    I inv() const { return pow(mod-2); }

    Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=L(1)*v*x.inv()%mod; return *this; }

    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }

    Modint operator++(int) { auto res=*this; *this+=1; return res; }
    Modint operator--(int) { auto res=*this; *this-=1; return res; }
    Modint operator-  () { return *this*-1; }
    Modint &operator++() { return *this+=1; }
    Modint &operator--() { return *this-=1; }

    bool operator< (const Modint&x) const { return v< x.v; }
    bool operator> (const Modint&x) const { return v> x.v; }
    bool operator<=(const Modint&x) const { return v<=x.v; }
    bool operator>=(const Modint&x) const { return v>=x.v; }
    bool operator==(const Modint&x) const { return v==x.v; }
    bool operator!=(const Modint&x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,mod>;

constexpr int N=1e6+10;
Mint faet[N*3],infaet[N*3];

void init() {
    faet[1]=1,faet[0]=1;
    infaet[1]=1,infaet[0]=1;
    for(int i=2;i<N*3;i++) faet[i]=faet[i-1]*i;
    for(int i=2;i<N*2;i++) infaet[i]=infaet[i-1]/i;
}

Mint get(int a,int b) {
    if(a<0||b<0||a<b) return 0;
    return faet[a]*infaet[a-b]*infaet[b];
}

void solve() {
    int n;
    cin>>n>>mod;
    init();

    Mint ans,res0,res1,res2,res3;
    res0=1;
    res1=faet[n]-1+faet[2*n]-faet[n]+faet[2*n]-faet[n];

    Mint x,y;
    for(int k=0;k<=n;k++) x+=get(n,k)*get(n,n-k)*get(n+n-k,n)*faet[n].pow(3);
    for(int k=0;k<=n;k++) y+=get(n,k)*get(n,n-k)*faet[n]*faet[2*n];
    res2=2*(y-x)+(x-res1-res0);
    res3=faet[3*n]-res0-res1-res2;

    ans=res1+2*res2+3*res3;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}