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
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;

struct Info {
    int minn=0,cnt=0;

    void init(int l,int r) {
        
    }
    void init(int l) { init(l,l); }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.minn=min(l.minn,r.minn);
        res.cnt=l.cnt+r.cnt;
        return res;
    }
    
    friend Info operator-(const Info &l,const Info &r) {
        Info res;
        res.cnt=l.cnt-r.cnt;
        return res;
    }

    Info &operator+=(const Info &v) {
        minn=v.minn;
        cnt+=v.cnt;
        return *this;
    }
};

template<class Info,int node_size>
struct PersistentSegmentTree {
    int idx,rng_l,rng_r;
    vector<int> root;
    array<Info, node_size> info;
    array<int, node_size> lch,rch;

    int ver() {
        return root.size()-1;
    }

    int new_node() {
        assert(idx<node_size);
        return ++idx;
    }

    int new_root() {
        root.emplace_back();
        return ver();
    }

    void clone(int u,int v) {
        info[u]=info[v];
        lch[u]=lch[v];
        rch[u]=rch[v];
    }

    void pushup(int u) {
        info[u]=info[lch[u]]+info[rch[u]];
    }

    Info query(int u,int l,int r,int x,int y) {
        if(l>y||r<x) return {};
        if(l>=x&&r<=y) return info[u];
        int mid=(l+r)/2;
        return query(lch[u],l,mid,x,y)+query(rch[u],mid+1,r,x,y);
    }
    Info query(int u,int l,int r) {
        return query(root[u],rng_l,rng_r,l,r);
    }

    Info range_query(int u,int v,int l,int r,int x,int y) {
        if(l>y||r<x) return {};
        if(l>=x&&r<=y) return info[u]-info[v];
        int mid=(l+r)/2;
        return range_query(lch[u],lch[v],l,mid,x,y)+
               range_query(rch[u],rch[v],mid+1,r,x,y);
    }
    Info range_query(int u,int v,int l,int r) {
        return range_query(root[u],root[v],rng_l,rng_r,l,r);
    }

    void modify(int &u,int v,int l,int r,int p,const Info &val) {
        u=new_node();
        clone(u, v);
        if(l==r) info[u]+=val;
        else {
            int mid=(l+r)/2;
            if(p<=mid) modify(lch[u],lch[v],l,mid,p,val);
            else modify(rch[u],rch[v],mid+1,r,p,val);
            pushup(u);
        }
    }
    void modify(int u,int v,int p,const Info &val) {
        modify(root[u],root[v],rng_l,rng_r,p,val);
    }

    int update(int p,const Info &val) {
        new_root();
        modify(root[ver()],root[ver()-1],rng_l,rng_r,p,val);
        return ver();
    }

    template<class F>
    int find_first(int u,int l,int r,int x,int y,F check) {
        if(l>y||r<x||l>=x&&r<=y&&!check(info[u])) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        int res=find_first(lch[u],l,mid,x,y,check);
        if(res==-1) res=find_first(rch[u],mid+1,r,x,y,check);
        return res;
    }
    template<class F> int find_first(int u,int l,int r,F check) {
        return find_first(root[u],rng_l,rng_r,l,r,check);
    }

    template<class F>
    int find_last(int u,int l,int r,int x,int y,F check) {
        if(l>y||r<x||l>=x&&r<=y&&!check(info[u])) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        int res=find_last(rch[u],mid+1,r,x,y,check);
        if(res==-1) res=find_last(lch[u],l,mid,x,y,check);
        return res;
    }
    template<class F> int find_last(int u,int l,int r,F check) {
        return find_last(root[u],rng_l,rng_r,l,r,check);
    }

    void build(int &u,int l,int r) {
        u=new_node();
        info[u].init(l,r);
        if(l!=r) {
            int mid=(l+r)>>1;
            build(lch[u],l,mid);
            build(rch[u],mid+1,r);
            pushup(u);
        }
    }
    void build(int l,int r) {
        build(root[new_root()],rng_l=l,rng_r=r);
    }
};

PersistentSegmentTree<Info, N*__lg(N)*4> sgt;

int rtid[N];

void solve() {
    int n;
    cin>>n;
    sgt.build(1,N);
    
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        in=min(in,n+5);
        rtid[i]=sgt.update(in, Info{i,1});
    }

    int q;
    cin>>q;
    while(q--) {
        int l,r;
        cin>>l>>r;
        int mex=sgt.find_first(rtid[r],1,N,[&](const Info &x) {
            return x.minn<l;
        });
        cout<<r-l+1-sgt.range_query(rtid[r],rtid[l-1],1,mex-1).cnt<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}