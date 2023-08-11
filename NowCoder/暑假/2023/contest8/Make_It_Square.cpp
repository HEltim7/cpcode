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

vector<int> zfunc(const string &s) {
    int n=s.size();
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;i++) {
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<n&&s[i+z[i]]==s[z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
    return z;
}

void solve() {
    int m;
    cin>>m;
    string s,t;
    cin>>s>>t;

    int sl=s.length();
    int tl=t.length();

    auto zero=[&]() {
        for(int i=1;i<=m;i++) {
            cout<<0<<" \n"[i==m];
        }
        exit(0);
    };

    if((sl+tl)&1) zero();
    if(s==t) {
        Mint cur=26;
        for(int i=1;i<=m;i++) {
            cout<<cur<<" \n"[i==m];
            cur*=26;
        }
        return;
    }

    if(sl>=tl) {
        int mid=(sl+tl)/2;
        for(int i=mid-tl,j=0;i<mid;i++,j++) {
            if(s[i]!=t[j]) zero();
        }

        auto &&z=zfunc(s);
        int i=1;
        for(int j=mid+i;i<=m&&j<sl;i++,j++) {
            if(z[j]==sl-j) cout<<1<<' ';
            else cout<<0<<' ';
        }

        Mint cur=1;
        while(i<=m) {
            cout<<cur<<' ';
            cur*=26;
            i++;
        }
        cout<<endl;
    }
    else {
        auto &&zt=zfunc(t);
        auto &&zst=zfunc(s+"#"+t);
        int lim=(tl-sl)/2-1;
        int idx=tl-(sl+tl)/2+1+sl;
        if(zst[idx]!=sl) zero();
        for(int i=1;i<=min(m,lim);i++) {
            int len=(sl+tl+2*i)/2;
            int pre=len-(sl+2*i);
            int p=tl-pre;
            if(zt[p]!=pre) cout<<0<<' ';
            else cout<<1<<' ';
        }

        Mint cur=1;
        for(int i=min(m,lim)+1;i<=m;i++) {
            cout<<cur<<' ';
            cur*=26;
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}