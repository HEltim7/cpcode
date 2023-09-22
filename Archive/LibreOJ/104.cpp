#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
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
using LL = long long;
auto rnd=mt19937(random_device()());

struct Treap {
    #define lch (tr[u].ch[0])
    #define rch (tr[u].ch[1])
    struct Node {
        int ch[2];
        int key,prio,sz;
        Node(int key=0): key(key),sz(1) {
            ch[0]=ch[1]=0;
            prio=rnd();
        }
    };
    vector<Node> tr;
    int root=0;

    int new_node(int key) {
        tr.emplace_back(key);
        return tr.size()-1;
    }

    void pushup(int u) {
        tr[u].sz=tr[lch].sz+tr[rch].sz+1;
    }

    pair<int,int> split_by_key(int u,int key) {
        if(!u) return {};
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

    tuple<int,int,int> extract_by_key(int u,int lkey,int rkey) {
        auto [t,r]=split_by_key(u, rkey);
        auto [l,m]=split_by_key(t, lkey-1);
        return {l,m,r};
    }

    pair<int,int> split_by_rank(int u,int rk) {
        if(!u) return {};
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

    int find(int u,int key) {
        if(!u||tr[u].key==key) return u;
        if(tr[u].key>key) return find(lch,key);
        return find(rch,key);
    }

    void insert(int key) {
        int u=new_node(key);
        auto [l,r]=split_by_key(root, key);
        root=merge(l,u,r);
    }

    void erase(int key) {
        if(find(root,key)) {
            auto [l,t]=split_by_key(root, key-1);
            auto [m,r]=split_by_rank(t, 1);
            root=merge(l,r);
        }
    }

    int rank(int key) {
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

    int prev(int key) {
        return kth(rank(key)-1);
    }

    int next(int key) {
        return kth(rank(key+1));
    }

    void clear() {
        root=0;
        tr.clear();
        new_node(0);
        tr[0].sz=0;
    }

    Node &operator[](int rk) {
        return tr[rk];
    }

    const Node &operator[](int rk) const {
        return tr[rk];
    }

    Treap(int sz=0) { tr.reserve(sz),clear(); }
};

void solve() {
    Treap tr(1e5+10);

    int q;
    cin>>q;
    while(q--) {
        int op,x;
        cin>>op>>x;
        if(op==1) tr.insert(x);
        if(op==2) tr.erase(x);
        if(op==3) cout<<tr.rank(x)<<endl;
        if(op==4) cout<<tr[tr.kth(x)].key<<endl;
        if(op==5) cout<<tr[tr.prev(x)].key<<endl;
        if(op==6) cout<<tr[tr.next(x)].key<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}