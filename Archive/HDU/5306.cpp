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
constexpr int N=1e6+10,INF=2e9;
int arr[N];

template<class Info,class Tag,int size> struct SegmentTreeBeats {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int L,R;
    constexpr static int node_size=4<<__lg(size)|1;
    array<Tag, node_size> tag;
    array<Info, node_size> info;
    array<bool, node_size> clean;

    void pushup(int u) {
        info[u]=info[lch]+info[rch];
    }

    void update(int u, const Tag &t) {
        info[u].update(t);
        tag[u].update(t);
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
        int m=(l+r)/2;
        return query(lch,l,m,x,y)+query(rch,m+1,r,x,y);
    }
    Info query(int l,int r) { return query(1,L,R,l,r); }

    void modify(int u,int l,int r,int x,int y,const Tag &t) {
        if(l>y||r<x||info[u].check1(t)) return;
        if(l>=x&&r<=y&&info[u].check2(t)) update(u,t);
        else {
            pushdn(u);
            int m=(l+r)/2;
            modify(lch,l,m,x,y,t);
            modify(rch,m+1,r,x,y,t);
            pushup(u);
        }
    }
    void modify(int l,int r,const Tag &t) { modify(1,L,R,l,r,t); }

    void build(int u,int l,int r) {
        clean[u]=1;
        info[u].init(l,r);
        tag[u].clear();
        if(l!=r) {
            int m=(l+r)/2;
            build(lch,l,m);
            build(rch,m+1,r);
            pushup(u);
        }
    }
    void build(int l=1,int r=size) { build(1,L=l,R=r); }

    #undef lch
    #undef rch
};

struct Tag {
    int mn=INF;

    void clear() {
        mn=INF;
    }

    void update(const Tag &t) {
        mn=min(mn,t.mn);
    }
};

struct Info {
    int mx1=0,mx2=0,cnt=0;
    LL sum=0;

    void init(int l,int r) {
        if(l!=r) return;
        sum=mx1=arr[l];
        cnt=1;
    }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.mx1=max(l.mx1,r.mx1);
        res.sum=l.sum+r.sum;
        if(l.mx1==r.mx1) {
            res.mx2=max(l.mx2,r.mx2);
            res.cnt=l.cnt+r.cnt;
        }
        else if(l.mx1>r.mx1) {
            res.mx2=max(l.mx2,r.mx1);
            res.cnt=l.cnt;
        }
        else {
            res.mx2=max(l.mx1,r.mx2);
            res.cnt=r.cnt;
        }
        return res;
    }

    // 无法更新最值
    bool check1(const Tag &t) {
        return mx1<=t.mn;
    }

    // 无法更新次值且不相等
    bool check2(const Tag &t) {
        return mx2<t.mn;
    }

    void update(const Tag &t) {
        if(check1(t)) return;
        sum-=1LL*(mx1-t.mn)*cnt;
        mx1=t.mn;
    }
};

SegmentTreeBeats<Info, Tag, N> sgt;

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sgt.build(1,n);
    for(int i=1;i<=q;i++) {
        int op,l,r,x;
        cin>>op>>l>>r;
        if(op==0) {
            cin>>x;
            sgt.modify(l,r,{x});
        }
        else if(op==1) {
            cout<<sgt.query(l,r).mx1<<endl;
        }
        else {
            cout<<sgt.query(l,r).sum<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}