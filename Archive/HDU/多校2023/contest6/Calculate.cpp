#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
}; using Mint=Modint<int,long long,int(1e9)+7>;

void solve() {
    int n,q;
    cin>>n>>q;
    constexpr int H=30;
    using P=pair<Mint,Mint>;
    auto res=vector<vector<P>>(H,vector<P>(n+1));
    auto p=vector<vector<int>>(H,vector<int>(n+1));
    vector<int> k(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>k[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>p[0][i];
    for(int i=1;i<=n;i++) res[0][i]={k[p[0][i]],b[p[0][i]]};
    auto mul=[&](P x,P y) {
        return P{x.first*y.first,x.second*y.first+y.second};
    };
    for(int b=1;b<H;b++) {
        for(int i=1;i<=n;i++) {
            p[b][i]=p[b-1][p[b-1][i]];
            res[b][i]=mul(res[b-1][i],res[b-1][p[b-1][i]]);
        }
    }

    while(q--) {
        int x,l,y;
        cin>>x>>l>>y;
        P cur{1,0};
        for(int b=H-1;b>=0;b--) {
            if(l>=(1<<b)) {
                l-=1<<b;
                cur=mul(cur,res[b][x]);
                x=p[b][x];
            }
        }
        Mint res=y*cur.first+cur.second;
        cout<<res<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}