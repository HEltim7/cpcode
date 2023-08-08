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
constexpr int N=410;
vector<string> vs[N];

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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        vs[s.length()].emplace_back(s);
    }

    auto solve_long=[&](int len,vector<string> &v) {
        auto dp=vector(len+1,vector(1<<v.size(),Mint{}));
        dp[0][(1<<v.size())-1]=1;
        for(int i=0;i<len;i++) {
            for(int j=1;j<1<<v.size();j++) {
                if(dp[i][j]>0) {
                    for(char c='0';c<='1';c++) {
                        int ne=0;
                        for(int k=0;k<v.size();k++) {
                            if((j>>k&1)&&(v[k][i]=='?'||v[k][i]==c)) ne|=1<<k;
                        }
                        dp[i+1][ne]+=dp[i][j];
                    }
                }
            }
        }
        Mint res;
        for(int j=1;j<1<<v.size();j++) res+=dp[len][j];
        return res;
    };

    auto solve_short=[&](int len,vector<string> &v) {
        Mint res=0;
        for(int i=0;i<1<<len;i++) {
            string s;
            for(int j=0;j<len;j++) s.push_back((i>>j&1)+'0');
            for(string &t:v) {
                bool ok=true;
                for(int i=0;i<len&&ok;i++) {
                    if(t[i]!='?'&&s[i]!=t[i]) ok=false;
                }
                if(ok) {
                    res++;
                    break;
                }
            }
        }
        return res;
    };

    Mint ans=0;
    for(int i=1;i<N;i++) {
        if(vs[i].empty()) continue;
        if(i<=20) ans+=solve_short(i,vs[i]);
        else ans+=solve_long(i,vs[i]);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}