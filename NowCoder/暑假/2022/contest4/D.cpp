#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <bitset>
using namespace std;

#define endl '\n'
using LL=long long;
const LL mod=998244353;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

LL qpow(LL a,LL b) {
    LL res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

template<typename T=long long,T mod=998244353> struct Modint {
    T v;
    T inv() {
        T res=1,a=v,b=mod-2;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }

    Modint &operator+=(const Modint &x) { v+=x.v; if(v>mod) v-=mod; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; if(v<0) v+=mod; return *this; }
    Modint &operator*=(const Modint &x) { v=v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=v*x.inv()%mod; return *this; }

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
using Mod=Modint<>;
const int N=12,M=400;

using bs=bitset<M+10>;
bs dp[N][M+10][M+10];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        int a,b,c,m;
        cin>>m;
        while(m--) {
            cin>>a>>b>>c;
            dp[i][a][b][c]=1;
        }
        for(int x=1;x<=M;x++)
            for(int y=1;y<=M;y++) {
                bs tmp;
                tmp.set();
                dp[i][x][y]=dp[i][x][y]|(tmp<<dp[i][x][y]._Find_first());
            }
        for(int x=1;x<=M;x++)
            for(int y=1;y<=M;y++)
                dp[i][x][y]=(dp[i][x][y]|dp[i][x-1][y]|dp[i][x][y-1]);
    }
    LL seed;
    cin>>seed;
    mt19937 rng(seed);
    uniform_int_distribution<> u(1,400);
    
    Mod ans;
    int lastans=0;
    for (int i=1;i<=q;i++)
    {
        int IQ=(u(rng)^lastans)%400+1;  // The IQ of the i-th friend
        int EQ=(u(rng)^lastans)%400+1;  // The EQ of the i-th friend
        int AQ=(u(rng)^lastans)%400+1;  // The AQ of the i-th friend
        lastans=0;
        for(int j=1;j<=n;j++) lastans+=dp[j][IQ][EQ][AQ];
        ans+=Mod(lastans)*Mod(qpow(seed,q-i));
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}