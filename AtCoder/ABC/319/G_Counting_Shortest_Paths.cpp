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
    auto del=vector(n+1,vector<int>());
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        del[u].emplace_back(v);
        del[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++) sort(del[i].begin(),del[i].end());

    vector<int> dis(n+1,n+10);
    auto bfs=[&]() {
        set<int> st;
        for(int i=2;i<=n;i++) st.emplace(i);
        queue<int> q;
        dis[1]=1;
        q.emplace(1);
        while(q.size()&&st.size()) {
            int u=q.front();
            for(auto it=st.begin();it!=st.end();) {
                int v=*it;
                if(dis[u]+1>=dis[v]||
                    binary_search(del[u].begin(),del[u].end(),v)) it++;
                else {
                    dis[v]=dis[u]+1;
                    q.emplace(v);
                    it=st.erase(it);
                }
            }
            q.pop();
        }
    };

    bfs();
    if(dis[n]>n) {
        cout<<-1<<endl;
        return;
    }

    vector<Mint> dp(n+1),sum(n+1);
    auto lay=vector(n+1,vector<int>());
    for(int i=1;i<=n;i++) if(dis[i]<=n) lay[dis[i]].emplace_back(i);

    dp[1]=sum[1]=1;
    for(int i=2;i<=n;i++) {
        for(int u:lay[i]) {
            dp[u]+=sum[i-1];
            for(int v:del[u]) if(dis[v]+1==dis[u]) dp[u]-=dp[v];
            sum[i]+=dp[u];
        }
    }
    cout<<dp[n]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}