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
constexpr int N=5e4+10;

template<class Node> struct Treap {
    #define lch (tr[u].ch[0])
    #define rch (tr[u].ch[1])
    using I=const Node&;
    vector<Node> tr;
    int root;

    int new_node(I x) {
        tr.emplace_back(x);
        return tr.size()-1;
    }

    void pushup(int u) {
        tr[u].pushup(tr[lch], tr[rch]);
    }

    void pushdn(int u) {
        tr[lch].update(tr[u]);
        tr[rch].update(tr[u]);
        tr[u].clear_tag();
    }

    pair<int,int> split_by_key(int u,I key,bool le=true) {
        if(!u) return {};
        pushdn(u);
        if(tr[u]<key||le&&!(key<tr[u])) {
            auto [l,r]=split_by_key(rch, key, le);
            rch=l;
            pushup(u);
            return {u,r};
        }
        else {
            auto [l,r]=split_by_key(lch, key, le);
            lch=r;
            pushup(u);
            return {l,u};
        }
    }
    tuple<int,int,int> extract_by_key(int u,I lkey,I rkey) {
        auto [t,r]=split_by_key(u, rkey);
        auto [l,m]=split_by_key(t, lkey, false);
        return {l,m,r};
    }

    pair<int,int> split_by_rank(int u,int rk) {
        if(!u) return {};
        pushdn(u);
        if(tr[lch].sz+1<=rk) {
            auto [l,r]=split_by_rank(rch, rk-tr[lch].sz-1);
            rch=l;
            pushup(u);
            return {u,r};
        }
        else {
            auto [l,r]=split_by_rank(lch, rk);
            lch=r;
            pushup(u);
            return {l,u};
        }
    }
    tuple<int,int,int> extract_by_rank(int u,int lrk,int rrk) {
        auto [t,r]=split_by_rank(u, rrk);
        auto [l,m]=split_by_rank(t, lrk-1);
        return {l,m,r};
    }

    int merge(int u,int v) {
        if(!u||!v) return u|v;
        pushdn(u);pushdn(v);
        if(tr[u].prio<tr[v].prio) {
            tr[u].ch[1]=merge(tr[u].ch[1], v);
            pushup(u);
            return u;
        }
        else {
            tr[v].ch[0]=merge(u, tr[v].ch[0]);
            pushup(v);
            return v;
        }
    }
    int merge(int x,int y,int z) {
        return merge(merge(x,y),z);
    }

    int find(int u,I key) {
        if(!u||!(tr[u]<key)&&!(key<tr[u])) return u;
        pushdn(u);
        if(key<tr[u]) return find(lch,key);
        return find(rch,key);
    }

    void insert(I key) {
        int u=new_node(key);
        auto [l,r]=split_by_key(root, key);
        root=merge(l,u,r);
    }

    void erase(I key) {
        if(find(root,key)) {
            auto [l,t]=split_by_key(root, key, false);
            auto [m,r]=split_by_rank(t, 1);
            root=merge(l,r);
        }
    }

    template<class F> int build(int l,int r,F f) {
        if(l>r) return 0;
        int m=(l+r)/2;
        int u=new_node(f(m));
        lch=build(l,m-1,f);
        rch=build(m+1,r,f);
        pushup(u);
        return u;
    }

    int rank(I key,bool le=false) {
        auto [l,r]=split_by_key(root, key, le);
        int rk=tr[l].sz+1;
        root=merge(l,r);
        return rk;
    }

    int kth(int rk) {
        auto [l,m,r]=extract_by_rank(root, rk, rk);
        root=merge(l,m,r);
        return m;
    }

    int prev(I key) { return kth(rank(key)-1); }
    int next(I key) { return kth(rank(key,true)); }
    int prev_equal(I key) { return kth(rank(key,true)-1); }
    int next_equal(I key) { return kth(rank(key)); }

    bool empty() { return root==0; }

    void clear() {
        root=0;
        tr.clear();
        new_node({});
        tr[0].set_null();
    }

    Node &operator[](int id) { return tr[id]; }
    I operator[](int id) const { return tr[id]; }

    Treap(int sz=0) { tr.reserve(sz),clear(); }

    #undef lch
    #undef rch
};

auto rnd=mt19937(random_device()());
struct Node {
    int ch[2],prio,sz;
    int idx;

    Node(int idx=0): idx(idx) {
        ch[0]=ch[1]=0;
        prio=rnd();
        sz=1;
    }

    void set_null() {
        sz=0;
    }

    // lch + par + rch
    void pushup(const Node &l,const Node &r) {
        sz=l.sz+1+r.sz;
    }

    // update info and lazy tag
    void update(const Node &p) {

    }

    // clear lazy tag
    void clear_tag() {

    }

    bool operator<(const Node &r) const {
        return idx<r.idx;
    }
};

int arr[N];
struct SegmentTree {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int rng_l,rng_r;
    constexpr static int node_size=1<<__lg(N*2)<<2|1;
    array<Treap<Node>, node_size> tr;
    array<int, N*2+1> leaf;

    int count(int u,int l,int r) {
        return tr[u].rank(Node(r+1))-tr[u].rank(Node(l));
    }

    int count(int u,int l,int r,int x,int y,int p,int q) {
        if(l>y||r<x) return {};
        if(l>=x&&r<=y) return count(u,p,q);
        int m=(l+r)/2;
        return count(lch,l,m,x,y,p,q)+count(rch,m+1,r,x,y,p,q);
    }
    int range_rank(int p,int q,int x) {
        return count(1,rng_l,rng_r,0,x-1,p,q)+1;
    }
    
    int find(int u,int l,int r,int p,int q,int k,int cnt) {
        if(l==r) return l;
        int m=(l+r)/2;
        if(cnt+count(lch,p,q)>=k) return find(lch,l,m,p,q,k,cnt);
        return find(rch,m+1,r,p,q,k,cnt+count(lch,p,q));
    }
    int range_kth(int p,int q,int k) {
        int idx=find(1,rng_l,rng_r,p,q,k,0);
        return find(1,rng_l,rng_r,p,q,k,0);
    }

    void erase(int p) {
        int x=arr[p];
        int u=leaf[x];
        tr[u].erase(Node(p));
        while(u>>=1) tr[u].erase(Node(p));
    }

    void insert(int p,int x) {
        arr[p]=x;
        int u=leaf[x];
        tr[u].insert(Node(p));
        while(u>>=1) tr[u].insert(Node(p));
    }

    void modify(int p,int x) {
        erase(p);
        insert(p, x);
    }

    int prev(int p,int q,int x) {
        int rk=range_rank(p, q, x);
        return range_kth(p, q, rk-1);
    }

    int next(int p,int q,int x) {
        int rk=range_rank(p, q, x+1);
        return range_kth(p, q, rk);
    }

    void build(int u,int l,int r) {
        tr[u].tr.reserve(r-l);
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
        }
        else leaf[l]=u;
    }
    void build(int l,int r) { build(1,rng_l=l,rng_r=r); }

    #undef lch
    #undef rch
} sgt;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> num;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        num.emplace_back(arr[i]);
    }

    vector<tuple<int,int,int,int>> qry(m);
    for(auto &[op,l,r,x]:qry) {
        cin>>op>>l>>r;
        if(op!=3) cin>>x;
        if(op==3) num.emplace_back(r);
        if(op>=4) num.emplace_back(x);
    }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    auto get=[&](int x) {
        return lower_bound(num.begin(),num.end(),x)-num.begin();
    };
    for(int i=1;i<=n;i++) arr[i]=get(arr[i]);

    sgt.build(0,num.size()-1);
    for(int i=1;i<=n;i++) sgt.insert(i, arr[i]);

    for(auto [op,l,r,x]:qry) {
        if(op==1) cout<<sgt.range_rank(l, r, get(x))<<endl;
        if(op==2) cout<<num[sgt.range_kth(l, r, x)]<<endl;
        if(op==3) sgt.modify(l, get(r));
        if(op==4) cout<<num[sgt.prev(l, r, get(x))]<<endl;
        if(op==5) cout<<num[sgt.next(l, r, get(x))]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}