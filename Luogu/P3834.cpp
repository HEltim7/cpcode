#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

template<class Info> struct PersistentSegmentTree {
    int L,R;
    vector<int> lch,rch;
    vector<Info> info;

    int new_node() {
        lch.emplace_back();
        rch.emplace_back();
        info.emplace_back();
        return info.size()-1;
    }

    void clone(int v,int u) {
        info[u]=info[v];
        lch[u]=lch[v];
        rch[u]=rch[v];
    }

    void pushup(int u) {
        info[u]=info[lch[u]]+info[rch[u]];
    }

    Info query(int u,int l,int r,int x,int y) {
        if(!u||l>y||r<x) return {};
        if(l>=x&&r<=y) return info[u];
        int m=l+(r-l)/2;
        return query(lch[u],l,m,x,y)+query(rch[u],m+1,r,x,y);
    }
    Info query(int rt,int l,int r) { return query(rt,L,R,l,r); }

    Info query(int v,int u,int l,int r,int x,int y) {
        if(!u||l>y||r<x) return {};
        if(l>=x&&r<=y) return info[u]-info[v];
        int m=l+(r-l)/2;
        return query(lch[v],lch[u],l,m,x,y)+
            query(rch[v],rch[u],m+1,r,x,y);
    }
    Info query(int lrt,int rrt,int l,int r) {
        return query(lrt,rrt,L,R,l,r);
    }

    constexpr static int nil=numeric_limits<int>::min();
    template<class F> int find_first(int v,int u,int l,int r,Info p,F f) {
        if(!u) return nil;
        if(l==r) return l;
        int m=l+(r-l)/2;
        Info t=p+(info[lch[u]]-info[lch[v]]);
        if(f(t)) return find_first(lch[v],lch[u],l,m,p,f);
        return find_first(rch[v],rch[u],m+1,r,t,f);
    }
    template<class F> int find_first(int lrt,int rrt,F f) {
        return f(info[rrt]-info[lrt])?find_first(lrt,rrt,L,R,{},f):nil;
    }

    int modify(int v,int l,int r,int p,const Info &val) {
        int u=new_node();
        if(v) clone(v,u);
        else info[u].init(l,r);
        if(l==r) info[u].update(val);
        else {
            int m=l+(r-l)/2;
            if(p<=m) lch[u]=modify(lch[v],l,m,p,val);
            else rch[u]=modify(rch[v],m+1,r,p,val);
            pushup(u);
        }
        return u;
    }
    int modify(int rt,int p,const Info &val) {
        return modify(rt,L,R,p,val);
    }

    PersistentSegmentTree(int l,int r,int sz=0):L(l),R(r) {
        lch.reserve(sz),rch.reserve(sz),info.reserve(sz);
        new_node();
    }
};

struct Info {
    int cnt=0;

    void init(int l,int r) {
        if(l!=r) return;
        cnt=0;
    }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.cnt=l.cnt+r.cnt;
        return res;
    }
    
    friend Info operator-(const Info &l,const Info &r) {
        Info res;
        res.cnt=l.cnt-r.cnt;
        return res;
    }

    void update(const Info &v) {
        cnt+=v.cnt;
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    PersistentSegmentTree<Info> sgt(-1e9,1e9,1e7);
    vector<int> rt(n+1),arr(n+1);
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        rt[i]=sgt.modify(rt[i-1],arr[i],{1});
    }

    while(q--) {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<sgt.find_first(
            rt[l-1],rt[r],[&](const Info &x) { return x.cnt>=k; }
        )<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}