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
constexpr int X=2.5e5+10,K=1e5+10;
multiset<int> st[K];

template<int size> struct SegmentTree {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int rng_l,rng_r;
    constexpr static int node_size=1<<__lg(size)<<2|1;
    array<int, node_size> cnt,sum;

    void pushup(int u) {
        sum[u]=cnt[u];
        if(rch<node_size) sum[u]+=max(sum[lch],sum[rch]);
    }

    void modify(int u,int l,int r,int x,int y,int t) {
        if(l>y||r<x) return;
        if(l>=x&&r<=y) cnt[u]+=t,pushup(u);
        else {
            int mid=(l+r)/2;
            if(mid>=x) modify(lch,l,mid,x,y,t);
            if(mid<y) modify(rch,mid+1,r,x,y,t);
            pushup(u);
        }
    }
    void modify(int l,int r,int t) { modify(1,rng_l,rng_r,l,r,t); }

    void build(int u,int l,int r) {
        cnt[u]=sum[u]=0;
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
            pushup(u);
        }
    }
    void build(int l=1,int r=size) { build(1,rng_l=l,rng_r=r); }

    #undef lch
    #undef rch
};
SegmentTree<X> sgt;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<tuple<int,int,int>> p(n);
    for(auto &[x,y,c]:p) cin>>x>>y>>c;
    sort(p.begin(),p.end());

    auto check=[&](int len) {
        sgt.build();
        for(int i=1;i<=k;i++) st[i].emplace(-1e9),st[i].emplace(1e9);
        auto add=[&](int y,int c) {
            int l=y,r=y+len;
            int pre=*--st[c].upper_bound(y);
            int suf=*st[c].lower_bound(y);
            l=max(l,pre+len+1);
            r=min(r,suf-1);
            if(l<=r) sgt.modify(l,r,1);
            st[c].emplace(y);
        };

        auto del=[&](int y,int c) {
            st[c].erase(st[c].find(y));
            int l=y,r=y+len;
            int pre=*--st[c].upper_bound(y);
            int suf=*st[c].lower_bound(y);
            l=max(l,pre+len+1);
            r=min(r,suf-1);
            if(l<=r) sgt.modify(l,r,-1);
        };

        bool valid=false;
        for(int l=0,r=0,x=len;x<X;x++) {
            while(r<p.size()&&get<0>(p[r])<=x) {
                auto [x,y,c]=p[r++];
                add(y, c);
            }
            while(l<p.size()&&get<0>(p[l])<x-len) {
                auto [x,y,c]=p[l++];
                del(y, c);
            }
            assert(sgt.sum[1]<=k);
            if(sgt.sum[1]==k) {
                valid=true;
                break;
            }
        }

        for(int i=1;i<=k;i++) st[i].clear();
        return valid;
    };

    int l=0,r=2.5e5;
    while(l<r) {
        int m=(l+r)/2;
        if(check(m)) r=m;
        else l=m+1;
    }
    cout<<l<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}