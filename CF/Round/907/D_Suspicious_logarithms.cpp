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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
using LLL=__int128;
constexpr LL INF=1e18;

template<typename I,typename L,I mod> struct Modint {
    I v;
    constexpr I _pow(L k) const {
        L res=1,x=v;
        while(k) { if(k&1) res=res*x%mod; k>>=1; x=x*x%mod; }
        return res;
    }
    constexpr I _inv() const { return _pow(mod-2); }
    constexpr Modint pow(L k) const { return Modint(_pow(k)); }
    constexpr Modint inv(L k) const { return Modint(_inv(k)); }

    constexpr Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    constexpr Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    constexpr Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    constexpr Modint &operator/=(const Modint &x) { v=L(1)*v*x._inv()%mod; return *this; }

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
}; using Mint=Modint<int,long long,int(1e9)+7>;

void solve() {
    vector<pair<LL,LL>> vec;
    vec.emplace_back(3,0);
    for(LL f=2;(1LL<<f)<=INF;f++) {
        LL l=1LL<<f;
        LL r=min((1LL<<(f+1))-1,INF);
        for(LLL g=1,L=f;L<=r;g++) {
            LL R=min(LLL(r),L*f-1);
            if(R>=l) vec.emplace_back(R,LL(g));
            L*=f;
        }
    }
    LL last=0;
    Mint sum=0;
    vector<Mint> pre;
    for(auto [r,x]:vec) {
        sum+=(r-last)*x;
        pre.emplace_back(sum);
        last=r;
    }
    
    auto get=[&](LL r) {
        if(r<=3) return Mint{};
        int idx=lower_bound(vec.begin(),vec.end(),pair{r,-1LL})-vec.begin();
        Mint ans=pre[idx-1];
        LL last=vec[idx-1].first;
        ans+=(r-last)*vec[idx].second;
        return ans;
    };

    int q;
    cin>>q;
    while(q--) {
        LL l,r;
        cin>>l>>r;
        Mint ans=get(r)-get(l-1);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}