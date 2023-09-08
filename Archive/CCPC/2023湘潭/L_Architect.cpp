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
using I128=__int128;
constexpr int N=2e5+10;

template<int size> struct SegmentTree {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int rng_l,rng_r;
    constexpr static int node_size=1<<__lg(size)<<2|1;
    array<set<int>, node_size> info;
    array<int, size+1> leaf;

    bool check(int u,int l,int r,int x,int y,int p,int q) {
        if(l>y||r<x) return true;
        if(l>=x&&r<=y) {
            auto it=info[u].lower_bound(p);
            return it==info[u].end()||*it>q;
        }
        int mid=(l+r)/2;
        return check(lch,l,mid,x,y,p,q)&check(rch,mid+1,r,x,y,p,q);
    }
    bool check(int x,int y,int p,int q) {
        return check(1,rng_l,rng_r,x,y,p,q);
    }

    void insert(int p,int x) {
        int u=leaf[p];
        info[u].insert(x);
        while(u>>=1) info[u].insert(x);
    }

    void erase(int p,int x) {
        int u=leaf[p];
        info[u].erase(x);
        while(u>>=1) info[u].erase(x);
    }

    void build(int u,int l,int r) {
        info[u].clear();
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
        }
        else leaf[l]=u;
    }
    void build(int l=1,int r=size) { build(1,rng_l=l,rng_r=r); }

    #undef lch
    #undef rch
};
SegmentTree<N> sgt;

void solve() {
    int w,h,l;
    cin>>w>>h>>l;
    I128 totv=I128(w)*h*l;
    int n;
    cin>>n;
    vector<int> num;
    vector<tuple<int,bool,int,int,int,int>> p;
    for(int i=1;i<=n;i++) {
        int a,b,c,x,y,z;
        cin>>a>>b>>c>>x>>y>>z;
        totv-=I128(x-a)*(y-b)*(z-c);
        x--,y--,z--;
        num.emplace_back(a);
        num.emplace_back(x);
        p.emplace_back(c,true,a,b,x,y);
        p.emplace_back(z+1,false,a,b,x,y);
    }
    if(totv) {
        cout<<"No"<<endl;
        return;
    }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(auto &[c,add,a,b,x,y]:p) {
        a=lower_bound(num.begin(),num.end(),a)-num.begin()+1;
        x=lower_bound(num.begin(),num.end(),x)-num.begin()+1;
    }
    sort(p.begin(),p.end());

    int mx=num.size();
    sgt.build(1,mx);
    for(auto [c,add,a,b,x,y]:p) {
        if(add&&!sgt.check(a,x,b,y)) {
            cout<<"No"<<endl;
            return;
        }

        vector<pair<int,int>> vec;
        vec.emplace_back(a, b);
        if(b!=y) vec.emplace_back(a, y);
        if(a!=x) {
            vec.emplace_back(x, b);
            if(b!=y) vec.emplace_back(x, y);
        }

        if(add) for(auto [x,y]:vec) sgt.insert(x, y);
        else for(auto [x,y]:vec) sgt.erase(x, y);
    }

    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}