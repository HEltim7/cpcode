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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr.begin()+1,arr.end());
    int sum=accumulate(arr.begin()+1,arr.end(),0);
    auto dp=vector(n+10,vector(sum+10,Mint{}));
    dp[0][0]=1;
    Mint res;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=sum;j++) {
            dp[i][j]=dp[i-1][j];
            int left=j-arr[i];
            if(left>=0) {
                dp[i][j]+=dp[i-1][left];
                if(arr[i]<=left) res+=(j+1)/2*dp[i-1][left];
                else res+=arr[i]*dp[i-1][left];
            }
        }
    }
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}