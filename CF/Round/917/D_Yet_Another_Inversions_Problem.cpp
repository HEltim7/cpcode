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

template<typename T=int,T init=T()> struct Fenwick {
    using F=function<void(T&,const T&)>;
    F add,sub;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }
    void resize(int n) { tr.resize(n+2,init); }

    void modify(int pos,T val) {
        if(++pos<=0) return;
        while(pos<tr.size()) add(tr[pos],val),pos+=lowbit(pos);
    }

    void reset(int pos) {
        if(++pos<=0) return;
        while(pos<tr.size()) tr[pos]=init,pos+=lowbit(pos);
    }

    T query(int pos) {
        if(++pos<0) return init;
        T res=init;
        while(pos) add(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }
    
    T range_query(int l,int r) {
        T res=query(r);
        sub(res,query(l-1));
        return res;
    }

    explicit Fenwick(
        int n,
        F add=[](T &x,const T &y) { x+=y; },
        F sub=[](T &x,const T &y) { x-=y; })
        : add(add),sub(sub) {
        resize(n);
    }
};

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
}; using Mint=Modint<int,long long,998244353>;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> p(n),q(k);
    for(int &x:p) cin>>x;
    for(int &x:q) cin>>x;
    Fenwick<> tr(k);
    Mint ans;
    for(int i=0;i<k;i++) {
        tr.modify(q[i], 1);
        ans+=i+1-tr.query(q[i]);
    }
    ans*=n;

    auto div=[&](int x,int y) {
        return (x+y-1)/y;
    };

    auto cal=[&](Mint x) {
        return x*(x+1)/2;
    };

    auto sol=[&](bool inv) {
        Mint res;
        tr=Fenwick<>(2*n-1);
        for(int x:p) {
            for(int pw=1;;pw++) {
                int l=div(x,1<<pw);
                int r=div(x,1<<(pw-1))-1;
                if(l>r) break;
                Mint t=tr.range_query(l, r);
                if(inv) res+=(Mint(k).pow(2)-cal(max(0,k-pw)))*t;
                else res+=cal(max(0,k-pw))*t;
            }
            tr.modify(x, 1);
        }
        return res;
    };

    ans+=sol(0);
    reverse(p.begin(),p.end());
    ans+=sol(1);
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