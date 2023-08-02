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
constexpr int N=2e5+10;

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

struct Binom {
    vector<Mint> faet,infaet;

    Mint operator()(int n,int m) {
        if(n<0||m<0||n<m) return {};
        return faet[n]*infaet[n-m]*infaet[m];
    }

    explicit Binom(int sz) {
        faet.resize(sz+1);
        infaet.resize(sz+1);

        faet[0]=faet[1]=1;
        infaet[0]=infaet[1]=1;
        for(int i=2;i<=sz;i++){
            faet[i]=faet[i-1]*i;
            infaet[i]=infaet[i-1]/i;
        }
    }
} binom(N);

void solve() {
    int n;
    cin>>n;

    // dp[i]=i号点，砍掉颜色与父边相同的边后所在连通块的大小
    vector<Mint> dp(n*2+1);
    vector<int> sz(n+1),up(n+1);
    vector<vector<int>> stk(n+1);
    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }

    for(int i=1;i<=n;i++) dp[i+n]=n;
    for(int i=1;i<=n;i++) stk[i].emplace_back(i+n);

    function<void(int,int)> dfs=[&](int u,int fa) {
        sz[u]=1;
        for(auto [v,w]:adj[u]) {
            if(v!=fa) {
                up[v]=stk[w].back();
                stk[w].emplace_back(v);
                dfs(v, u);
                stk[w].pop_back();
                dp[up[v]]-=sz[v];
                dp[v]+=sz[v];
                sz[u]+=sz[v];
            }
        }
    };

    dfs(1,0);
    Mint k2;
    for(int i=2;i<=n;i++) k2+=dp[i]*dp[up[i]];

    int ans=0;
    for(int k=2;k<=n;k++) ans^=(k2*binom(n-2,k-2)/binom(n,k)).v;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}