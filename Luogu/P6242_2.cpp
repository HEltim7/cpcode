#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
constexpr int N=5e5+10,INF=1e9;
int arr[N];

struct Tag {
    // add1=区间最大值加法标记
    // add2=区间非最大值加法标记
    // 之所以要分add1,add2，是为了维护区间取min的操作
    // 本质上区间取min每次仅会修改最大值
    // 因此会导致最大值和非最大值需要加上的值不同

    // addhis1=区间历史最大值加法标记 即max(add1)
    // addhis2=区间历史非最大值加法标记 即max(add2)
    // addhis1 很好理解，保存历史最大的加法标记，以便更新历史最值
    // 而 addhis2 的存在是因为 add2 存在
    // 在 pushdn 时，如果某个子节点的最大值等于父节点的最大值，
    // 那么用 addhis1 更新，否则，用 addhis2 更新

    LL add1,add2,addhis1,addhis2;

    void clear() {
        add1=add2=addhis1=addhis2=0;
    }

    // 如果当前最大值就等于父节点最大值
    // 保持不变即可 add1,add2,addhis1,addhis2
    // 否则当前需要修改的量不论是否最值都是相等的
    // 变为 add2,add2,addhis2,addhis2
    void update(const Tag &t) {
        addhis1=max(addhis1,add1+t.addhis1);
        addhis2=max(addhis2,add2+t.addhis2);
        add1+=t.add1;
        add2+=t.add2;
    }
};

struct Info {
    int len=0,cnt=0;
    LL sum=0,max1=-INF,max2=-INF,maxhis=-INF;

    void init(int l,int r) {
        if(l!=r) return;
        sum=max1=maxhis=arr[l];
        len=cnt=1;
    }
    void init(int l) { init(l,l); }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.len=l.len+r.len;
        res.sum=l.sum+r.sum;
        res.max1=max(l.max1,r.max1);
        res.maxhis=max(l.maxhis,r.maxhis);
        if(l.max1==r.max1) {
            res.max2=max(l.max2,r.max2);
            res.cnt=l.cnt+r.cnt;
        }
        else if(l.max1>r.max1) {
            res.max2=max(l.max2,r.max1);
            res.cnt=l.cnt;
        }
        else {
            res.max2=max(l.max1,r.max2);
            res.cnt=r.cnt;
        }
        return res;
    }

    Info &operator+=(const Tag &t) {
        sum+=t.add1*cnt+t.add2*(len-cnt);
        maxhis=max(maxhis,max1+t.addhis1);
        max1+=t.add1;
        if(max2!=-INF) max2+=t.add2;
        return *this;
    }

    bool operator==(const Info &x) {
        return max1==x.max1;
    }
};

struct SegmentTree {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int rng_l,rng_r;
    constexpr static int size=N;
    constexpr static int node_size=1<<__lg(size)<<2|1;
    array<Tag, node_size> tag;
    array<Info, node_size> info;
    array<bool, node_size> clean;

    void pushup(int u) {
        info[u]=info[lch]+info[rch];
    }

    void update_max1(int u, const Tag &t) {
        info[u]+=t;
        tag[u].update(t);
        clean[u]=0;
    }

    void update_max2(int u,const Tag &t) {
        info[u]+=Tag{t.add2,t.add2,t.addhis2,t.addhis2};
        tag[u].update(Tag{t.add2,t.add2,t.addhis2,t.addhis2});
        clean[u]=0;
    }

    void pushdn(int u) {
        if(clean[u]) return;
        int maxx=max(info[lch].max1,info[rch].max1);
        if(maxx==info[lch].max1) update_max1(lch,tag[u]);
        else update_max2(lch,tag[u]);
        if(maxx==info[rch].max1) update_max1(rch,tag[u]);
        else update_max2(rch,tag[u]);
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

    void add(int u,int l,int r,int x,int y,LL val) {
        if(l>y||r<x) return;
        else if(l>=x&&r<=y) update_max1(u, Tag{val,val,val,val});
        else {
            pushdn(u);
            int mid=(l+r)/2;
            add(lch, l, mid, x, y, val);
            add(rch, mid+1, r, x, y, val);
            pushup(u);
        }
    }

    void chmin(int u,int l,int r,int x,int y,LL val) {
        if(l>y||r<x||val>=info[u].max1) return;
        if(l>=x&&r<=y&&val>info[u].max2) {
            LL k=val-info[u].max1;
            info[u].sum+=k*info[u].cnt;
            info[u].max1=val;
            tag[u].add1+=k;
            clean[u]=0;
            return;
        }
        pushdn(u);
        int mid=(l+r)/2;
        chmin(lch,l,mid,x,y,val);
        chmin(rch,mid+1,r,x,y,val);
        pushup(u);
    }

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
} sgt;

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sgt.build(1,n);
    while(m--) {
        int op,l,r,k;
        cin>>op>>l>>r;
        if(op<=2) cin>>k;
        if(op==1) sgt.add(1, 1, n, l, r, k);
        else if(op==2) sgt.chmin(1, 1, n, l, r, k);
        else if(op==3) cout<<sgt.query(l, r).sum<<endl;
        else if(op==4) cout<<sgt.query(l, r).max1<<endl;
        else cout<<sgt.query(l, r).maxhis<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}