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

auto rnd=mt19937(random_device()());
struct Treap {
    #define lch (tr[u].ch[0])
    #define rch (tr[u].ch[1])
    struct Node {
        int ch[2];
        int prio,sz;
        bool rev;
        int idx;
        LL key,add,sum;
        Node(LL key,int idx):
        idx(idx),key(key),sum(key),add(0),sz(1),rev(false) {
            ch[0]=ch[1]=0;
            prio=rnd();
        }

        friend ostream &operator<<(ostream &os,const Node &x) {
            return os<<x.key;
        }
    };
    vector<Node> tr;
    int root;

    int new_node(LL key,int idx) {
        tr.emplace_back(key,idx);
        return tr.size()-1;
    }

    void pushup(int u) {
        tr[u].sz=tr[lch].sz+tr[rch].sz+1;
        tr[u].sum=tr[lch].sum+tr[rch].sum+tr[u].key;
    }

    void pushrev(int u) {
        if(u) {
            swap(lch,rch);
            tr[u].key=-tr[u].key;
            tr[u].sum=-tr[u].sum;
            tr[u].add=-tr[u].add;
            tr[u].rev^=1;
        }
    }

    void update(int u,LL add) {
        if(u) {
            tr[u].key+=add;
            tr[u].sum+=tr[u].sz*add;
            tr[u].add+=add;
        }
    }

    void pushdn(int u) {
        if(tr[u].rev) {
            pushrev(lch);
            pushrev(rch);
            tr[u].rev=0;
        }
        if(tr[u].add) {
            update(lch, tr[u].add);
            update(rch, tr[u].add);
            tr[u].add=0;
        }
    }

    pair<int,int> split_by_key(int u,LL key) {
        if(!u) return {};
        pushdn(u);
        if(tr[u].key<=key) {
            auto [l,r]=split_by_key(rch, key);
            rch=l;
            pushup(u);
            return {u,r};
        }
        else {
            auto [l,r]=split_by_key(lch, key);
            lch=r;
            pushup(u);
            return {l,u};
        }
    }
    tuple<int,int,int> extract_by_key(int u,LL lkey,LL rkey) {
        auto [t,r]=split_by_key(u, rkey);
        auto [l,m]=split_by_key(t, lkey-1);
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

    int find(int u,LL key) {
        if(!u||tr[u].key==key) return u;
        pushdn(u);
        if(tr[u].key>key) return find(lch,key);
        return find(rch,key);
    }

    void insert(LL key,int idx) {
        int u=new_node(key,idx);
        auto [l,r]=split_by_key(root, key);
        root=merge(l,u,r);
    }

    void erase(LL key) {
        if(find(root,key)) {
            auto [l,t]=split_by_key(root, key-1);
            auto [m,r]=split_by_rank(t, 1);
            root=merge(l,r);
        }
    }

    int rank(LL key) {
        auto [l,r]=split_by_key(root, key-1);
        int rk=tr[l].sz+1;
        root=merge(l,r);
        return rk;
    }

    int kth(int rk) {
        auto [l,m,r]=extract_by_rank(root, rk, rk);
        root=merge(l,m,r);
        return m;
    }

    int prev(LL key) { return kth(rank(key)-1); }
    int next(LL key) { return kth(rank(key+1)); }

    void reverse(LL key) {
        auto [l,r]=split_by_key(root, key);
        pushrev(l);
        root=merge(l,r);
    }

    void modify(int x) {
        reverse(x-1);
        update(root, x);
    }

    int build(const vector<pair<LL,int>> &arr,int l,int r) {
        if(l>r) return 0;
        int m=(l+r)/2;
        int u=new_node(arr[m].first, arr[m].second);
        lch=build(arr, l, m-1);
        rch=build(arr, m+1, r);
        pushup(u);
        return u;
    }

    void dump(int u,vector<pair<LL,int>> &arr) {
        if(!u) return;
        arr[tr[u].idx]={tr[u].key,tr[u].idx};
        pushdn(u);
        dump(lch, arr);
        dump(rch, arr);
    }

    void print(int u) {
        if(!u) return;
        pushdn(u);
        print(lch);
        cerr<<tr[u]<<' ';
        print(rch);
    }

    void clear() {
        root=0;
        tr.clear();
        new_node(0,0);
        tr[0].sz=0;
    }

    Node &operator[](int id) { return tr[id]; }
    const Node &operator[](int id) const { return tr[id]; }

    Treap(int sz=0) { tr.reserve(sz),clear(); }

    #undef lch
    #undef rch
};

namespace sqrt_div {
    constexpr int N=1e5+10,B=320,C=N/B+1;
    vector<Treap> tr(C,Treap(B+1));
    vector<int> lbd,rbd;
    vector<pair<LL,int>> arr(N);

    int getid(int x) {
        return x/B;
    }

    void modify(int l,int r,int x) {
        int id=getid(l);
        tr[id].dump(tr[id].root, arr);
        for(int i=l;i<=r;i++) {
            LL &v=arr[i].first;
            if(v<x) v=-v;
            v+=x;
        }

        tr[id].clear();
        sort(arr.begin()+lbd[id],arr.begin()+rbd[id]+1);
        tr[id].root=tr[id].build(arr, lbd[id], rbd[id]);
    }

    void block_modify(int id,int x) {
        tr[id].modify(x);
    }

    void range_modify(int l,int r,int x) {
        int lid=getid(l),rid=getid(r);
        if(lid==rid) modify(l, r, x);
        else {
            modify(l, rbd[lid], x);
            for(int i=lid+1;i<rid;i++) block_modify(i, x);
            modify(lbd[rid], r, x);
        }
    }

    LL query(int l,int r) {
        int id=getid(l);
        tr[id].dump(tr[id].root, arr);
        LL res=0;
        for(int i=l;i<=r;i++) res+=arr[i].first;
        return res;
    }

    LL block_query(int id) {
        return tr[id][tr[id].root].sum;
    }

    LL range_query(int l,int r) {
        LL res=0;
        int lid=getid(l),rid=getid(r);
        if(lid==rid) res=query(l, r);
        else {
            res+=query(l, rbd[lid]);
            for(int i=lid+1;i<rid;i++) res+=block_query(i);
            res+=query(lbd[rid], r);
        }
        return res;
    }

    void init(int n) {
        for(int l=1,r=B-1;l<=n;l=r+1,r+=B)
            lbd.emplace_back(l),rbd.emplace_back(r);
        rbd.back()=n;
        for(int i=0;i<lbd.size();i++) {
            sort(arr.begin()+lbd[i],arr.begin()+rbd[i]+1);
            tr[i].root=tr[i].build(arr, lbd[i], rbd[i]);
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        auto &[v,id]=sqrt_div::arr[i];
        cin>>v,id=i;
    }
    sqrt_div::init(n);

    while(m--) {
        int op,l,r,x;
        cin>>op>>l>>r;
        if(op==1) {
            cin>>x;
            sqrt_div::range_modify(l, r, x);
        }
        else cout<<sqrt_div::range_query(l, r)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}