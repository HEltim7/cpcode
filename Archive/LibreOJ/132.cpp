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

    explicit Fenwick(
        int n,
        F add=[](T &x,const T &y) { x+=y; },
        F sub=[](T &x,const T &y) { x-=y; })
        : add(add),sub(sub) {
        resize(n);
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    Fenwick<LL> dif(n),idif(n);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        dif.modify(i, in);
        dif.modify(i+1, -in);
        idif.modify(i, 1LL*i*in);
        idif.modify(i+1, -1LL*(i+1)*in);
    }

    while(q--) {
        int op;
        cin>>op;
        if(op==1) {
            int l,r,x;
            cin>>l>>r>>x;
            dif.modify(l, x);
            dif.modify(r+1, -x);
            idif.modify(l, 1LL*l*x);
            idif.modify(r+1, -1LL*(r+1)*x);
        }
        else {
            int l,r;
            cin>>l>>r;
            auto get=[&](int x) {
                return dif.query(x)*(x+1)-idif.query(x);
            };
            cout<<get(r)-get(l-1)<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}