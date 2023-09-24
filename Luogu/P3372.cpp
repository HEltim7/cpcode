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
        LL key,sum,add;
        Node(LL key=0): key(key),sum(key),add(0),sz(1),rev(false) {
            ch[0]=ch[1]=0;
            prio=rnd();
        }
    };
    vector<Node> tr;
    int root;

    int new_node(LL key) {
        tr.emplace_back(key);
        return tr.size()-1;
    }

    void pushup(int u) {
        tr[u].sz=tr[lch].sz+tr[rch].sz+1;
        tr[u].sum=tr[lch].sum+tr[rch].sum+tr[u].key;
    }

    void pushrev(int u) {
        if(u) {
            swap(lch,rch);
            tr[u].rev^=1;
        }
    }

    void update(int u,LL add) {
        if(u) {
            tr[u].add+=add;
            tr[u].key+=add;
            tr[u].sum+=tr[u].sz*add;
        }
    }

    void pushdn(int u) {
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

    void insert(LL key) {
        int u=new_node(key);
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

    void reverse(int lrk,int rrk) {
        auto [l,m,r]=extract_by_rank(root, lrk, rrk);
        pushrev(m);
        root=merge(l,m,r);
    }

    int build(const vector<int> &arr,int l,int r) {
        if(l>r) return 0;
        int m=(l+r)/2;
        int u=new_node(arr[m]);
        lch=build(arr, l, m-1);
        rch=build(arr, m+1, r);
        pushup(u);
        return u;
    }

    void clear() {
        root=0;
        tr.clear();
        new_node(0);
        tr[0].sz=0;
    }

    Node &operator[](int id) { return tr[id]; }
    const Node &operator[](int id) const { return tr[id]; }

    Treap(int sz=0) { tr.reserve(sz),clear(); }

    #undef lch
    #undef rch
};

void solve() {
    int n,m;
    cin>>n>>m;
    Treap tr;
    vector<int> arr(n);
    for(int &x:arr) cin>>x;
    tr.root=tr.build(arr, 0, n-1);
    while(m--) {
        int op,x,y,k;
        cin>>op>>x>>y;
        if(op==1) {
            cin>>k;
            auto [l,m,r]=tr.extract_by_rank(tr.root, x, y);
            tr.update(m, k);
            tr.root=tr.merge(l,m,r);
        }
        else {
            auto [l,m,r]=tr.extract_by_rank(tr.root, x, y);
            cout<<tr[m].sum<<endl;
            tr.root=tr.merge(l,m,r);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}