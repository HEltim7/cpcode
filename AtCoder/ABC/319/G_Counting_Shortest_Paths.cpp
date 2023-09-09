#include <algorithm>
#include <array>
#include <bitset>
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
constexpr int N=2e5+10;
using BS=bitset<N>;

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
    int n,m;
    cin>>n>>m;
    set<pair<int,int>> st;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);
        st.emplace(u,v);
    }

    if(st.find({1,n})==st.end()) {
        cout<<1<<endl;
        return;
    }
    st.erase({1,n});

    BS s,t;
    for(int i=2;i<=n;i++) s[i]=1;
    for(int i=1;i<n;i++) t[i]=1;
    Mint ans=n-2;
    for(int i=n-3;st.size();i--) {
        for(int i=s._Find_first();i<=n;i=s._Find_next(i)) {
            auto it=st.find({1,i});
            if(it!=st.end()) {
                s[i]=0;
                st.erase(it);
            }
        }
        for(int i=t._Find_first();i<=n;i=t._Find_next(i)) {
            auto it=st.find({i,n});
            if(it!=st.end()) {
                t[i]=0;
                st.erase(it);
            }
        }

        auto tmp=s&t;
        if(tmp.count()) {
            cout<<ans-st.size()<<endl;
            return;
        }
        else {
            ans*=i;
            for(int i=2;i<=n;i++) s[i]=1;
            for(int i=1;i<n;i++) t[i]=1;
        }
    }
    cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}