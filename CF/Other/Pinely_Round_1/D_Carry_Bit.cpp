#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

template<typename I,typename L,I mod> struct Modint {
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
    static_assert(0ULL+mod+mod-2<1ULL<<(sizeof(I)*8-1), "Modint overflow");
    static_assert(1ULL*(mod-1)*(mod-1)<1ULL<<(sizeof(L)*8-1), "Modint overflow");
}; using Mint=Modint<int,long long,int(1e9+7)>;

constexpr int N=1e6+10;
Mint faet[N],infaet[N],pw[N];

void init() {
    faet[1]=1,faet[0]=1,pw[0]=1;
    infaet[1]=1,infaet[0]=1;
    for(int i=2;i<N;i++){
        faet[i]=faet[i-1]*i;
        infaet[i]=infaet[i-1]/i;
    }
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*3;
}

Mint get(int a,int b) {
    if(a<0||b<0||a<b) return 0;
    return faet[a]*infaet[a-b]*infaet[b];
}

Mint pw3(int x) {
    return x>=0?pw[x]:0;
}

void solve() {
    int n,k;
    cin>>n>>k;
    Mint ans;
    for(int i=1;i<=k;i++)
        ans+=get(k-1,i-1)*(get(n-k,i-1)*pw3(n-2*i+1)+get(n-k,i)*pw3(n-2*i));
    if(k==0) ans=pw[n];
    cout<<ans;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}