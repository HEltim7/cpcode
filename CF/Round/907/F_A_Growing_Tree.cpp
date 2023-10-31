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
constexpr int N=5e5+10;

template<typename T=int,T init=T()> struct Fenwick {
    using F=function<void(T&,const T&)>;
    F add,sub;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }
    void resize(int n) { tr.resize(n+2,init); }

    void modify(int pos,T val) {
        if(++pos<=0) return;
        while(pos<tr.size()) add(tr[pos],val),pos+=lowbit(pos);
    }

    void reset(int pos) {
        if(++pos<=0) return;
        while(pos<tr.size()) tr[pos]=init,pos+=lowbit(pos);
    }

    T query(int pos) {
        if(++pos<0) return init;
        T res=init;
        while(pos) add(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }
    
    T range_query(int l,int r) {
        T res=query(r);
        sub(res,query(l-1));
        return res;
    }

    explicit Fenwick(
        int n,
        F add=[](T &x,const T &y) { x+=y; },
        F sub=[](T &x,const T &y) { x-=y; })
        : add(add),sub(sub) {
        resize(n);
    }
};

void solve() {
    int q;
    cin>>q;
    vector<vector<int>> adj(q+10);
    vector<tuple<int,int,int>> qry(q);
    for(int idx=1; auto &[t,x,y]:qry) {
        cin>>t;
        if(t==1) {
            cin>>x;
            adj[x].emplace_back(++idx);
            x=idx;
        }
        else cin>>x>>y;
    }

    int idx=0;
    vector<int> id(q+10),ed(q+10);
    function<void(int,int)> dfs=[&](int u,int fa) {
        id[u]=++idx;
        for(int v:adj[u]) {
            if(v!=fa) {
                dfs(v,u);
            }
        }
        ed[u]=idx;
    };
    dfs(1,0);

    Fenwick<LL> tr(q+10);
    vector<LL> ans(q+10);
    reverse(qry.begin(),qry.end());
    for(auto [t,x,y]:qry) {
        if(t==1) {
            ans[x]=tr.query(id[x]);
        }
        else {
            tr.modify(id[x], y);
            tr.modify(ed[x]+1, -y);
        }
    }
    ans[1]=tr.query(id[1]);
    for(int i=1;i<=idx;i++) cout<<ans[i]<<" \n"[i==idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}