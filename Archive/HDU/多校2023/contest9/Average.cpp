#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <ostream>
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

struct Frac {
    LL sum;
    int len=1;
    auto operator<=>(const Frac &x) const {
        return sum*x.len<=>x.sum*len;
    }
    Frac operator+(const Frac &x) const {
        return Frac{sum+x.sum,len+x.len};
    }
    friend ostream &operator<<(ostream &os,const Frac &x) {
        LL g=gcd(x.sum,x.len);
        return os<<x.sum/g<<"/"<<x.len/g;
    }
};

void solve() {
    int n,k;
    cin>>n>>k;

    auto arr=vector(n+1,0LL);
    auto par=vector(n+1,0);
    auto adj=vector(n+1,vector<int>());
    auto mx1=vector(n+1,vector(k*2,Frac()));
    auto mx2=vector(n+1,vector(k*2,Frac()));
    auto res=vector(n+1,vector(k,Frac()));
    Frac ans{};

    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    
    auto upd_ans=[&](int u) {
        for(int i=0;i<=k-1;i++)
            ans=max(ans,res[u][i]);
    };

    auto merge=[&](int u,int v) {
        for(int i=0;i<=2*k-2;i++) {
            if(i&&!mx1[v][i].sum) continue;
            for(int j=max(k-i,1);j<=2*k-1-i;j++) {
                if(!mx1[u][j].sum) continue;
                res[u][i+j-k]=max(res[u][i+j-k],mx1[v][i]+mx1[u][j]);
            }
        }
        for(int i=1;i<=2*k-1;i++) {
            if(!mx1[v][i-1].sum) continue;
            Frac val=mx1[v][i-1]+Frac{arr[u],1};
            if(val>=mx1[u][i]) {
                mx2[u][i]=mx1[u][i];
                mx1[u][i]=val;
            }
            else mx2[u][i]=max(mx2[u][i],val);
        }
    };

    auto split=[&](int u,int v) {
        for(int i=1;i<=2*k-1;i++) {
            if(!mx1[v][i-1].sum) continue;
            Frac val=mx1[v][i-1]+Frac{arr[u],1};
            if(val>=mx1[u][i]) mx1[u][i]=mx2[u][i];
        }
    };

    function<void(int,int)> init=[&](int u,int fa) {
        par[u]=fa;
        mx1[u][1]={arr[u],1};
        if(k==1) res[u][0]={arr[u],1};
        for(int v:adj[u]) {
            if(v!=fa) {
                init(v,u);
                merge(u,v);
            }
        }
        upd_ans(u);
    };

    auto del=[&](int u) {
        vector<int> stk;
        for(int i=1;i<=2*k-1&&u;i++) {
            stk.emplace_back(u);
            u=par[u];
        }
        while(stk.size()>=2) {
            int p=stk.end()[-1];
            int u=stk.end()[-2];
            stk.pop_back();
            split(p, u);
        }
    };

    auto add=[&](int u,int v) {
        int p=par[u];
        arr[u]+=v;
        for(int i=0;i<=k-1;i++) {
            if(!res[u][i].sum) continue;
            res[u][i].sum+=v;
            ans=max(ans,res[u][i]);
        }
        for(int i=1;i<=2*k-1;i++) if(mx1[u][i].sum) mx1[u][i].sum+=v;
        for(int i=1;i<=2*k-1;i++) if(mx2[u][i].sum) mx2[u][i].sum+=v;
        for(int i=2;i<=2*k-1&&p;i++) {
            merge(p,u);
            upd_ans(p);
            u=p;
            p=par[p];
        }
    };

    init(1,0);

    int q;
    cin>>q;
    while(q--) {
        int u,x;
        cin>>u>>x;
        del(u);
        add(u,x);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}