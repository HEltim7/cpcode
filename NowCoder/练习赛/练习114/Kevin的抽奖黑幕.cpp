#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

template<typename I,typename L,I mod> struct Modint {
    I v;
    constexpr I pow(L b) const {
        L res=1,a=v;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }
    constexpr I inv() const { return pow(mod-2); }

    constexpr Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    constexpr Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    constexpr Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    constexpr Modint &operator/=(const Modint &x) { v=L(1)*v*x.inv()%mod; return *this; }

    friend constexpr Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend constexpr Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend constexpr Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend constexpr Modint operator/(Modint l,const Modint &r) { return l/=r; }
    friend constexpr Modint operator-(Modint r) { r.v=mod-r.v; return r; }

    Modint operator++(int) { auto res=*this; ++*this; return res; }
    Modint operator--(int) { auto res=*this; --*this; return res; }
    Modint &operator++() { v=v==mod-1?0:v+1; return *this; }
    Modint &operator--() { v=v?v-1:mod-1; return *this; }

    constexpr bool operator< (const Modint &x) const { return v< x.v; }
    constexpr bool operator> (const Modint &x) const { return v> x.v; }
    constexpr bool operator<=(const Modint &x) const { return v<=x.v; }
    constexpr bool operator>=(const Modint &x) const { return v>=x.v; }
    constexpr bool operator==(const Modint &x) const { return v==x.v; }
    constexpr bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    constexpr Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,998244353>;

void solve() {
    int n,m,k,d;
    cin>>n>>m>>k>>d;
    auto dp=vector(m+1,vector(d+1,Mint{}));
    Mint p=Mint(k)/n;
    Mint bonus=0;
    dp[0][0]=1;
    for(int i=0;i<m;i++) {
        for(int j=0;j<d;j++) {
            dp[i+1][0]+=p*dp[i][j];
            dp[i+1][j+1]+=(1-p)*dp[i][j];
        }
        bonus+=dp[i+1][d];
        dp[i+1][0]+=dp[i+1][d];
    }
    Mint ans=bonus*n+m*k;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}