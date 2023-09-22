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
    struct Node {
        Node *ch[2];
        int val, prio, cnt, siz;

        Node(int val) : val(val), cnt(1), siz(1) {
            ch[0] = ch[1] = nullptr;
            prio = rnd();
        }

        void upd_siz() {
            siz = cnt;
            if (ch[0] != nullptr) siz += ch[0]->siz;
            if (ch[1] != nullptr) siz += ch[1]->siz;
        }
    };
    Node *root=nullptr;

    pair<Node*,Node*> split_by_key(Node *cur,int key) {
        if(cur==nullptr) return {nullptr,nullptr};
        if(cur->val<=key) {
            auto [l,r]=split_by_key(cur->ch[1], key);
            cur->ch[1]=l;
            cur->upd_siz();
            return {cur,r};
        }
        else {
            auto [l,r]=split_by_key(cur->ch[0], key);
            cur->ch[0]=r;
            cur->upd_siz();
            return {l,cur};
        }
    }
    
    tuple<Node*,Node*,Node*> split_by_rank(Node *cur,int rk) {
        if(cur==nullptr) return {nullptr,nullptr,nullptr};
        int lsz=cur->ch[0]==nullptr?0:cur->ch[0]->siz;
        if(rk<=lsz) {
            auto [l,m,r]=split_by_rank(cur->ch[0], rk);
            cur->ch[0]=r;
            cur->upd_siz();
            return {l,m,cur};
        }
        else if(rk<=lsz+cur->cnt) {
            Node *l=cur->ch[0],*r=cur->ch[1];
            cur->ch[0]=cur->ch[1]=nullptr;
            cur->upd_siz();
            return {l,cur,r};
        }
        else {
            auto [l,m,r]=split_by_rank(cur->ch[1], rk-lsz-cur->cnt);
            cur->ch[1]=l;
            cur->upd_siz();
            return {cur,m,r};
        }
    }

    Node* merge(Node *u,Node *v) {
        if(u==nullptr&&v==nullptr) return nullptr;
        if(u!=nullptr&&v==nullptr) return u;
        if(u==nullptr&&v!=nullptr) return v;
        if(u->prio<v->prio) {
            u->ch[1]=merge(u->ch[1], v);
            u->upd_siz();
            return u;
        }
        else {
            v->ch[0]=merge(u, v->ch[0]);
            v->upd_siz();
            return v;
        }
    }

    void insert(int val) {
        auto [t,r]=split_by_key(root, val);
        auto [l,m]=split_by_key(t, val-1);
        Node *new_node;
        if(m==nullptr) new_node=new Node(val);
        else {
            m->cnt++;
            m->upd_siz();
        }
        root=merge(merge(l, m==nullptr?new_node:m), r);
    }

    void erase(int val) {
        auto [t,r]=split_by_key(root, val);
        auto [l,m]=split_by_key(t, val-1);
        if(m->cnt>1) {
            m->cnt--;
            m->upd_siz();
            l=merge(l, m);
        }
        else {
            if(t==m) t=nullptr; //?
            delete m;
            m=nullptr;
        }
        root=merge(l, r);
    }

    int get_rank_by_val(Node *cur,int val) {
        auto [l,r]=split_by_key(cur, val-1);
        int rk=(l==nullptr?0:l->siz)+1;
        root=merge(l, r);
        return rk;
    }

    int get_val_by_rank(Node *cur,int rk) {
        auto [l,m,r]=split_by_rank(cur, rk);
        int val=m->val;
        root=merge(merge(l, m), r);
        return val;
    }

    int prev(int val) {
        auto [l,r]=split_by_key(root, val-1);
        int res=get_val_by_rank(l, l->siz);
        root=merge(l, r);
        return res;
    }

    int next(int val) {
        auto [l,r]=split_by_key(root, val);
        int res=get_val_by_rank(r, 1);
        root=merge(l, r);
        return res;
    }

    void _del(Node *cur) {
        if(cur==nullptr) return;
        _del(cur->ch[0]);
        _del(cur->ch[1]);
        delete cur;
    }

    ~Treap() {_del(root);}
};

void solve() {
    Treap tr;
    int q;
    cin>>q;
    while(q--) {
        int op,x;
        cin>>op>>x;
        if(op==1) tr.insert(x);
        if(op==2) tr.erase(x);
        if(op==3) cout<<tr.get_rank_by_val(tr.root, x)<<endl;
        if(op==4) cout<<tr.get_val_by_rank(tr.root, x)<<endl;
        if(op==5) cout<<tr.prev(x)<<endl;
        if(op==6) cout<<tr.next(x)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}