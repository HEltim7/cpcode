#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

template<typename T=long long,T mod=998244353> struct Modint {
    T v;
    LL inv() const {
        LL res=1,a=v,b=mod-2;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }

    Modint &operator+=(const Modint &x) { v+=x.v; if(v>=mod) v-=mod; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; if(v<0) v+=mod; return *this; }
    Modint &operator*=(const Modint &x) { v=1LL*v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=1LL*v*x.inv()%mod; return *this; }

    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }

    Modint operator++(int) { auto res=*this; *this+=1; return res; }
    Modint operator--(int) { auto res=*this; *this-=1; return res; }
    Modint operator-  () { return *this*-1; }
    Modint &operator++() { return *this+=1; }
    Modint &operator--() { return *this-=1; }

    bool operator< (const Modint&x) { return v< x.v; }
    bool operator> (const Modint&x) { return v> x.v; }
    bool operator<=(const Modint&x) { return v<=x.v; }
    bool operator>=(const Modint&x) { return v>=x.v; }
    bool operator==(const Modint&x) { return v==x.v; }
    bool operator!=(const Modint&x) { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(T x=0): v((x%=mod)<0?x+mod:x) {}
};
using Mint=Modint<int>;

constexpr int N=8e3+10;
Mint dp[2][N];
Mint val[N][N];
Mint p[N];
int a[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) cin>>a[i],p[i]=Mint(a[i]).inv();
    for(int z=0;z<2;z++) {
        for(int i=1;i<=n;i++) for(int j=0;j<i;j++) val[i][j]=0;
        val[1][0]=1;
        val[2][0]=-1;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<i;j++) {
                val[i][j]+=val[i-1][j];
                dp[z][j]=val[i][j];
                val[i+1][j+1]+=dp[z][j]*p[i];
                val[i+a[i]+1][j+1]-=dp[z][j]*p[i];
            }
        }
    }
    Mint ans;
    for(int i=1;i<=n;i++) ans+=dp[0][i]*dp[0][i];
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}