#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
constexpr LL INF=1e18;

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

    bool operator< (const Modint &x) const { return v< x.v; }
    bool operator> (const Modint &x) const { return v> x.v; }
    bool operator<=(const Modint &x) const { return v<=x.v; }
    bool operator>=(const Modint &x) const { return v>=x.v; }
    bool operator==(const Modint &x) const { return v==x.v; }
    bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
    static_assert(0ULL+mod+mod-2<1ULL<<(sizeof(I)*8-1), "Modint overflow");
    static_assert(1ULL*(mod-1)*(mod-1)<1ULL<<(sizeof(L)*8-1), "Modint overflow");
}; using Mint=Modint<int,long long,998244353>;

void solve() {
    int n;
    cin>>n;
    map<LL,Mint> cnt;
    int mul=0;
    Mint pw=1;
    LL sub=0,tot=0;
    for(int i=1;i<=n;i++) {
        int op,x;
        cin>>op;
        if(op!=3) cin>>x;
        if(op==1) {
            if(sub==0&&mul) cnt[sub+x]+=1/pw;
            else cnt[sub+x]++;
        }
        else if(op==2) {
            if(sub==0&&mul) {
                for(auto &[x,y]:cnt) y*=pw;
                mul=0;
            }
            sub+=x,tot+=x;
        }
        else {
            if(sub==0) mul++,pw*=2;
            else if(tot<INF) {
                for(auto it=cnt.lower_bound(tot+sub+1);it!=cnt.end();it++) {
                    cnt[it->first-tot]+=it->second;
                }
                tot*=2;
            }
        }
    }
    if(mul) for(auto &[x,y]:cnt) y*=pw;

    Mint ans=0;
    for(auto it=cnt.lower_bound(sub+1);it!=cnt.end();it++) ans+=it->second;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}