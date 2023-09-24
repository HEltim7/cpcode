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
constexpr int N=4e5+10;

vector<int> num;
template<int size> struct SegmentTree {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int rng_l,rng_r;
    constexpr static int node_size=1<<__lg(size)<<2|1;
    array<int, node_size> cnt,len,sum;

    void pushup(int u) {
        if(cnt[u]) sum[u]=len[u];
        else if(rch<node_size) sum[u]=sum[lch]+sum[rch];
        else sum[u]=0;
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
        len[u]=num[r+1]-num[l];
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
SegmentTree<N> sgt;

void solve() {
    int n;
    cin>>n;
    vector<array<int,4>> rect(n);
    for(auto &a:rect) for(int &x:a) cin>>x,num.emplace_back(x);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    int mx=num.size()-1;

    auto seg=vector(mx+1,vector<tuple<int,int,int>>());
    for(auto &a:rect) {
        for(int &x:a) x=lower_bound(num.begin(),num.end(),x)-num.begin();
        seg[a[0]].emplace_back(a[1],a[3]-1,1);
        seg[a[2]].emplace_back(a[1],a[3]-1,-1);
    }
    
    LL ans=0;
    sgt.build(0,mx);
    for(int i=0;i<=mx;i++) {
        if(i) ans+=1LL*(num[i]-num[i-1])*sgt.sum[1];
        for(auto [l,r,s]:seg[i]) sgt.modify(l,r,s);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}