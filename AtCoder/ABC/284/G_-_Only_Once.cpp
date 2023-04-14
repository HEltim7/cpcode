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

constexpr int N=2e5+10;
Mint pw[N],pre1[N],pre2[N];

void init(int n) {
    pw[0]=1;
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*n;
    pre1[1]=n;
    for(int i=2;i<=n;i++) pre1[i]=pre1[i-1]*(n-i+1);
    for(int i=2;i<=n;i++) pre2[i]=pre2[i-1]+pre1[i]*pw[n-i];
}

void solve() {
    int n;
    cin>>n>>mod;
    init(n);

    Mint ans;
    for(int l=1;l<n;l++) ans+=(pre2[n]-pre2[l])*l;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}