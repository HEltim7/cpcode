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
    I _pow(L k) const {
        L res=1,x=v;
        while(k) { if(k&1) res=res*x%mod; k>>=1; x=x*x%mod; }
        return res;
    }
    I _inv() const { return _pow(mod-2); }
    Modint pow(L k) const { return Modint(_pow(k)); }
    Modint inv(L k) const { return Modint(_inv(k)); }

    Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=L(1)*v*x._inv()%mod; return *this; }

    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }
    friend Modint operator-(Modint r) { r.v=mod-r.v; return r; }

    Modint operator++(int) { auto res=*this; ++*this; return res; }
    Modint operator--(int) { auto res=*this; --*this; return res; }
    Modint &operator++() { v=v==mod-1?0:v+1; return *this; }
    Modint &operator--() { v=v?v-1:mod-1; return *this; }

    bool operator< (const Modint &x) const { return v< x.v; }
    bool operator> (const Modint &x) const { return v> x.v; }
    bool operator<=(const Modint &x) const { return v<=x.v; }
    bool operator>=(const Modint &x) const { return v>=x.v; }
    bool operator==(const Modint &x) const { return v==x.v; }
    bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    constexpr Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,int(1e9)+7>;

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
} binom(1e6+10);

template<typename T=int> struct CartesianTree {
    vector<int> lch,rch,stk;
    vector<T> val;
    int root,idx;

    void extend(int x) {
        idx++;
        lch.emplace_back(0);
        rch.emplace_back(0);
        val.emplace_back(x);
        
        while(stk.size()&&val[stk.back()]>x) {
            lch[idx]=stk.back();
            stk.pop_back();
        }
        if(stk.size()) rch[stk.back()]=idx;
        else root=idx;
        stk.emplace_back(idx);
    }

    void clear() {
        root=idx=0;
        lch.assign(1,{});
        rch.assign(1,{});
        val.assign(1,{});
        stk.clear();
    }

    CartesianTree(int sz=0) {
        lch.reserve(sz+1);
        rch.reserve(sz+1);
        val.reserve(sz+1);
        stk.reserve(sz+1);
        clear();
    }
};

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> h(n+1);
    CartesianTree<> tr(n);
    for(int i=1;i<=n;i++) cin>>h[i],tr.extend(h[i]);
    
    function<vector<Mint>(int,int)> dfs=[&](int u,int fa) {
        if(!u) return vector<Mint>(1,1);
        int cur=h[u]-h[fa];
        auto l=dfs(tr.lch[u],u);
        auto r=dfs(tr.rch[u],u);
        int sz=l.size()+r.size()-1;
        vector<Mint> tmp(sz+1),res(sz+1);
        for(int i=0;i<l.size();i++) {
            for(int j=0;j<r.size();j++) {
                tmp[i+j]+=l[i]*r[j];
            }
        }
        for(int i=0;i<=sz;i++) {
            for(int j=0;j<=min(i,cur);j++) {
                res[i]+=binom(sz-(i-j),j)*binom(cur,j)*binom.faet[j]*tmp[i-j];
            }
        }
        return res;
    };

    auto res=dfs(tr.root,0);
    cout<<res[k]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}