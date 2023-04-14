#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;
int arr[N],cnt[N];

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

    Modint operator++(int) { auto res=*this; ++*this; return res; }
    Modint operator--(int) { auto res=*this; --*this; return res; }
    Modint &operator++() { v=v==mod-1?0:v+1; return *this; }
    Modint &operator--() { v=v?v-1:mod-1; return *this; }
    Modint operator-() { v=mod-v; return *this; }

    bool operator< (const Modint &x) const { return v< x.v; }
    bool operator> (const Modint &x) const { return v> x.v; }
    bool operator<=(const Modint &x) const { return v<=x.v; }
    bool operator>=(const Modint &x) const { return v>=x.v; }
    bool operator==(const Modint &x) const { return v==x.v; }
    bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    constexpr Modint(L x=0): v((x=abs(x)>=mod?x%mod:x)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,998244353>;

Mint faet[N],infaet[N];

void init() {
    faet[1]=1,faet[0]=1;
    infaet[1]=1,infaet[0]=1;
    for(int i=2;i<N;i++){
        faet[i]=faet[i-1]*i;
        infaet[i]=infaet[i-1]/i;
    }
}

Mint cmb(int a,int b) {
    if(a<0||b<0||a<b) return 0;
    return faet[a]*infaet[a-b]*infaet[b];
}

void solve() {
    int n,m,k,zero=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>arr[i],cnt[arr[i]]++;
    for(int i=m;i>=1;i--) cnt[i]+=cnt[i+1];
    for(int i=1;i<=n;i++) if(arr[i]==0) zero++;

    Mint ans,tot=Mint(m).pow(zero);
    for(int v=1;v<=m;v++) {
        Mint cur;
        for(int i=max(0,n-k+1-cnt[v]);i<=zero;i++) {
            cur+=cmb(zero, i)*Mint(m-v+1).pow(i)*Mint(v-1).pow(zero-i);
        }
        ans+=cur/tot;
    }
    cout<<ans;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}