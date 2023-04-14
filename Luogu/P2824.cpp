#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=1e5+10,M=N*100;
map<int,pair<int,bool>> mp;

struct Node {
    int l,r;
    int cnt;
} tr[M];
int idx;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

int new_node() {
    assert(idx<M);
    return ++idx;
}

void pushup(int u) {
    tr[u].cnt=tr[tr[u].l].cnt+tr[tr[u].r].cnt;
}

void merge(int &u,int v) {
    if(!u||!v) u=u+v;
    else {
        merge(tr[u].l,tr[v].l);
        merge(tr[u].r,tr[v].r);
        tr[u].cnt+=tr[v].cnt;
    }
}

void split(int u,int &v,int k) { //1-k 归 u k>=1
    if(!u) return;
    v=new_node();
    if(k<=tr[tr[u].l].cnt) swap(tr[u].r,tr[v].r);
    if(k<tr[tr[u].l].cnt) split(tr[u].l, tr[v].l, k);
    else if(k>tr[tr[u].l].cnt) split(tr[u].r, tr[v].r, k-tr[tr[u].l].cnt);
    pushup(u),pushup(v);
}

void try_split(int p) {
    auto it=prev(mp.upper_bound(p));
    int l=it->first;
    if(l==p) return;
    auto [u,type]=it->second;
    int v=0;
    int r=next(it)->first;
    split(u, v, type?r-p:p-l);
    mp.erase(it);
    mp.insert({l,{type?v:u,type}});
    mp.insert({p,{type?u:v,type}});
}

void modify(int &u,int l,int r,int p) {
    if(!u) u=new_node();
    if(l==r) tr[u].cnt++;
    else {
        int mid=l+r>>1;
        if(p<=mid) modify(tr[u].l, l, mid, p);
        else modify(tr[u].r, mid+1, r, p);
        tr[u].cnt++;
    }
}

int query(int u,int l,int r,int k) {
    int mid=l+r>>1;
    if(l==r) return l;
    if(k<=tr[tr[u].l].cnt) return query(tr[u].l, l, mid, k);
    return query(tr[u].r, mid+1, r, k-tr[tr[u].l].cnt);
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        int u=0;
        modify(u, 1, n, in);
        mp.insert({i,{u,0}});
    }
    mp.insert({n+1,{0,0}});
    while(m--) {
        int op,l,r;
        cin>>op>>l>>r;
        try_split(l);
        try_split(r+1);
        auto it=mp.lower_bound(l);
        int u=it->second.first;
        for(it=next(it);it->first<=r;it=next(it)) merge(u,it->second.first);
        mp.erase(mp.lower_bound(l),it);
        mp.insert({l,{u,op}});
    }
    int q;
    cin>>q;
    auto it=prev(mp.upper_bound(q));
    int l=it->first;
    int r=next(it)->first;
    auto [u,type]=it->second;
    cout<<query(u, 1, n, type?r-q:q-l+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}