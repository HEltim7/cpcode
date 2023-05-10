#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#include <functional>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
int arr[N],last[N];
LL ans[N];

template<class Info,class Tag,int size> struct SegmentTree {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int rng_l,rng_r;
    constexpr static int node_size=1<<__lg(size)<<2|1;
    array<Tag, node_size> tag;
    array<Info, node_size> info;
    array<bool, node_size> clean;

    void pushup(int u) {
        info[u]=info[lch]+info[rch];
    }

    void update(int u, const Tag &t) {
        info[u]+=t;
        tag[u]+=t;
        clean[u]=0;
    }

    void pushdn(int u) {
        if(clean[u]) return;
        update(lch, tag[u]);
        update(rch, tag[u]);
        clean[u]=1;
        tag[u].clear();
    }

    Info query(int u,int l,int r,int x,int y) {
        if(l>y||r<x) return {};
        if(l>=x&&r<=y) return info[u];
        pushdn(u);
        int mid=(l+r)/2;
        return query(lch,l,mid,x,y)+query(rch,mid+1,r,x,y);
    }
    Info query(int l,int r) { return query(1,rng_l,rng_r,l,r); }

    void modify(int u,int l,int r,int x,int y,const Tag &t) {
        if(l>y||r<x) return;
        if(l>=x&&r<=y) { update(u, t); }
        else {
            pushdn(u);
            int mid=(l+r)/2;
            if(mid>=x) modify(lch,l,mid,x,y,t);
            if(mid<y) modify(rch,mid+1,r,x,y,t);
            pushup(u);
        }
    }
    void modify(int l,int r,const Tag &v) { modify(1,rng_l,rng_r,l,r,v); }

    void build(int u,int l,int r) {
        clean[u]=1;
        info[u].init(l,r);
        tag[u].clear();
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

struct Tag {
    LL x,y,z;

    void clear() {
        x=0,y=0,z=0;
    }

    Tag &operator+=(const Tag &t) {
        z+=t.z;
        y+=x*t.z+t.y;
        x+=t.x;
        return *this;
    }
};

struct Info {
    int len;
    LL sum,hsum;

    void init(int l,int r) {
        if(l!=r) return;
        len=r-l+1;
        sum=hsum=l;
    }
    void init(int l) { init(l,l); }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.len=l.len+r.len;
        res.sum=l.sum+r.sum;
        res.hsum=l.hsum+r.hsum;
        return res;
    }

    Info &operator+=(const Tag &t) {
        hsum+=len*t.y+sum*t.z;
        sum+=len*t.x;
        return *this;
    }
};

SegmentTree<Info, Tag, N> sgt;

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    using Query=tuple<int,int,int,int,int>;
    vector<Query> qry;
    for(int i=1;i<=q;i++) {
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        auto add=[&](int l,int r,int x,int sign) {
            if(l>x) return;
            r=min(r,x);
            qry.emplace_back(x,l,r,i,sign);
        };
        add(l, r, y, 1);
        add(l, r, x-1, -1);
    }
    sort(qry.begin(),qry.end());

    set<int> st{0};
    sgt.build(1,n);
    for(int idx=1; auto [x,l,r,id,sign]:qry) {
        while(idx<=x) {
            st.emplace(idx);
            if(last[arr[idx]]) {
                auto it=st.find(last[arr[idx]]);
                int L=*prev(it)+1,R=*it;
                int val=*next(it);
                st.erase(it);
                sgt.modify(L,R,Tag{val-R,val-R,1});
                sgt.modify(1,L-1,Tag{0,0,1});
                sgt.modify(R+1,idx-1,Tag{0,0,1});
            }
            else sgt.modify(1,idx-1,Tag{0,0,1});
            last[arr[idx]]=idx;
            idx++;
        }
        ans[id]+=sign*sgt.query(l,r).hsum;
    }

    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}