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

    int kth(int k) {
        int pos=0;
        for(int i=__lg(tr.size()-1);~i;i--)
            if(pos+(1<<i)<tr.size()&&tr[pos+(1<<i)]<k)
                pos+=1<<i,k-=tr[pos];
        return pos;
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
    cin>>n>>m;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    
    auto get=[&](int k) {
        Fenwick<> tr(n);
        for(int i=0;i<n;i++) tr.modify(i, 1);

        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        int idx=0,tot=n;
        for(int i=0;i<n;i++) {
            int step=(k-1)%tot+1;
            int pre=tr.query(idx-1);
            int suf=tot-pre;
            if(suf>=step) idx=tr.kth(pre+step);
            else idx=tr.kth(step-suf);

            p[i]=idx;
            tot--;
            tr.modify(idx, -1);
        }
        return p;
    };

    auto apply=[&](vector<int> &tar,vector<int> &p) {
        vector<int> res(n);
        for(int i=0;i<n;i++) res[i]=tar[p[i]];
        tar=res;
    };

    auto qpow=[&](int k,int x) {
        auto &&p=get(k);
        while(x) {
            if(x&1) apply(arr, p);
            x>>=1;
            auto t=p;
            apply(p, t);
        }
    };

    while(m--) {
        int k,x;
        cin>>k>>x;
        qpow(k, x);
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" \n"[i==n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}