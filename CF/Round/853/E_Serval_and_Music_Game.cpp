#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e6+10,M=2e7+10;

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

int s[N],cnt_gcd[M],cnt[M],pre[M];

int next_floor(int k,int i) {
    return k/(k/i);
}

int next_ceil(int k,int i) {
    if(k-1<i) return i;
    return (k-1)/((k-1)/i);
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i],cnt[s[i]]++;
    const int sn=s[n];
    vector<int> vgcd;
    vgcd.reserve(n);
    for(int i=1,t;i<=n;i++) t=gcd(s[i],sn),cnt_gcd[t]++,vgcd.push_back(t);
    for(int i=1;i<=sn;i++) pre[i]=pre[i-1]+cnt[i];

    vector<int> d;
    for(int i=1;i*i<=sn;i++)
        if(sn%i==0) {
            d.push_back(i);
            if(i!=sn/i) d.push_back(sn/i);
        }
    
    Mint ans;
    for(int i=1;i<=sn;) {
        LL res=0;
        int j=min(next_floor(sn, i),next_ceil(sn, i));
        int a=sn/i,b=(sn+i-1)/i;
        if(a==b) {
            for(int x:d) if(x%a==0) res+=cnt_gcd[x];
        }
        else {
            for(int x=1;x<=min(sn/a,a-1);x++)
                res+=pre[min(x*a+x,sn)]-pre[x*a-1];
            if(a<=sn/a) res+=pre[sn]-pre[a*a-1];
        }
        while(i<=j) ans+=res*i,i++;
    }
    cout<<ans<<endl;

    for(int x:vgcd) cnt_gcd[x]--;
    for(int i=1;i<=n;i++) cnt[s[i]]--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}