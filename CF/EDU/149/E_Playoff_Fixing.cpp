#include <algorithm>
#include <array>
#include <cassert>
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

constexpr int K=20,N=1<<K;
int arr[N],cnt[K][N],top[K][N],fr[K];

void solve() {
    int n;
    cin>>n;

    auto get=[&](int x) {
        int b=__lg(x);
        if(x==1<<b) return b;
        return b+1;
    };

    auto add=[&](int idx,int x) {
        for(int i=n;i>=get(x);i--) {
            if(cnt[i][idx]) return false;
            debug(x,idx);
            cnt[i][idx]++;
            idx=(idx+1)/2;
        }
        if(get(x)-1>=0) {
            if(top[get(x)-1][idx]) return false;
            top[get(x)-1][idx]++;
        }
        return true;
    };

    fr[0]=1;
    for(int i=1;i<=n;i++) fr[i]=(1<<i)-(1<<(i-1));
    for(int i=1;i<=1<<n;i++) cin>>arr[i];
    for(int i=1;i<=1<<n;i++) {
        if(arr[i]==-1) continue;
        fr[get(arr[i])]--;
        if(!add(i, arr[i])) {
            cout<<0<<endl;
            return;
        }
    }
    debug(fr,0,n);
    
    Mint ans=1;
    for(int i=n;i>=1;i--) {
        if(fr[i]<=0) continue;
        Mint cur=1;
        for(int j=1;j<=1<<(i-1);j++) {
            debug(i,j);
            if(!cnt[i-1][j]) cur*=2;
        }

        Mint a=1;
        for(int j=1;j<=fr[i];j++) a*=j;
        debug(cur,a);
        ans*=cur*a;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}