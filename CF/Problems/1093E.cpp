#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
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

int arr[N],bak[N];
vector<vector<int>> num(N);
vector<Fenwick<>> tr(N,Fenwick<>(0));
int lowbit(int x) { return x&(-x); }
void add_num(int pos,int x) {
    if(pos<=0) return;
    int t=pos;
    while(pos<N) {
        num[pos].emplace_back(x);
        pos+=lowbit(pos);
    }
    while(t) {
        num[t].emplace_back(x);
        t-=lowbit(t);
    }
}

int get(int pos,int x) {
    assert(binary_search(num[pos].begin(),num[pos].end(),x));
    return lower_bound(num[pos].begin(),num[pos].end(),x)-num[pos].begin();
}

void build() {
    for(int i=1;i<N;i++) {
        sort(num[i].begin(),num[i].end());
        num[i].erase(unique(num[i].begin(),num[i].end()),num[i].end());
        tr[i].resize(num[i].size());
    }
}

void add(int pos,int x,int v) {
    if(pos<=0) return;
    while(pos<N) {
        tr[pos].modify(get(pos,x), v);
        pos+=lowbit(pos);
    }
}

int query(int pos,int x,int y) {
    if(pos<=0) return 0;
    int res=0;
    while(pos) {
        res+=tr[pos].range_query(get(pos,x), get(pos,y));
        pos-=lowbit(pos);
    }
    return res;
}

int range_query(int l,int r,int x,int y) {
    int res=query(r, x, y);
    res-=query(l-1, x, y);
    return res;
}

void modify(int x,int y) {
    add(x, arr[x], -1);
    add(x, arr[y], 1);
    add(y, arr[y], -1);
    add(y, arr[x], 1);
    swap(arr[x],arr[y]);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> pos(n+1);
    vector<tuple<int,int,int,int,int>> qry(m);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        pos[in]=i;
    }

    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        arr[i]=pos[arr[i]];
        bak[i]=arr[i];
        add_num(i, arr[i]);
    }

    for(auto &[op,x,y,l,r]:qry) {
        cin>>op>>x>>y;
        if(op==1) {
            cin>>l>>r;
            debug(l,r,x,y);
            add_num(r, x);
            add_num(r, y);
            add_num(l-1, x);
            add_num(l-1, y);
        }
        else {
            add_num(x, arr[y]);
            add_num(y, arr[x]);
            swap(arr[x],arr[y]);
        }
    }
    memcpy(arr, bak, sizeof bak);
    build();
    for(int i=1;i<=n;i++) add(i, arr[i], 1);

    for(auto [op,x,y,l,r]:qry) {
        if(op==1) cout<<range_query(l, r, x, y)<<endl;
        else modify(x, y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}