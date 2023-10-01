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
constexpr LL INF=2e18;

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
    int n,m;
    LL k;
    cin>>n>>m>>k;
    k--;

    vector<int> res(n),fix(n);
    vector<int> pos,unfix;
    for(int &x:res) cin>>x;
    for(int i=0;i<n;i++) {
        pos.emplace_back(min(i+m-1,n-1)-i+1);
        unfix.emplace_back(res[i]);
        for(int j=i+1;j<n;j++) {
            if(res[j]<res[i]) fix[j+m-1]=res[j];
            else {
                i=j-1;
                break;
            }
        }
    }
    
    vector<LL> suf(pos.size());
    suf.back()=pos.back();
    for(int i=2;i<=pos.size();i++) {
        double t=double(suf.end()[-i+1])*pos.end()[-i];
        if(t>=INF) suf.end()[-i]=INF;
        else suf.end()[-i]=suf.end()[-i+1]*pos.end()[-i];
    }

    Fenwick<> tr(pos.size());
    for(int i=0;i<=pos.size();i++) if(i==pos.size()||!fix[i]) tr.modify(i, 1);
    auto get=[&](int k) {
        int l=k-1,r=pos.size();
        while(l<r) {
            int m=(l+r)/2;
            if(tr.query(m)>=k) r=m;
            else l=m+1;
        }
        return l;
    };

    debug(pos);
    debug(suf);
    for(int i=0;i<suf.size();i++) {
        int t=0;
        if(i+1<suf.size()) {
            t=k/suf[i+1];
            k-=t*suf[i+1];
        }
        int idx=get(t+1);
        tr.modify(idx, -1);
        fix[idx]=unfix[i];
    }
    for(int i=0;i<n;i++) cout<<fix[i]<<" \n"[i==n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}