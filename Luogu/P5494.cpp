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
constexpr int N=2e5+10;

namespace sgt {
    #define lch (tr[u].lc)
    #define rch (tr[u].rc)

    struct Node {
        int lc=0,rc=0;
        LL cnt=0;
    };
    constexpr int M=N*(__lg(N)+1)*2;
    vector<Node> tr(M);
    int idx=0;

    int new_node() {
        assert(++idx<M);
        tr[idx]={};
        return idx;
    }

    void pushup(int u) {
        tr[u].cnt=tr[lch].cnt+tr[rch].cnt;
    }

    void update(int u) {
        if(!u) return;

    }

    void pushdn(int u) {

    }

    int kth(int u,int l,int r,int k) {
        if(tr[u].cnt<k) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        if(tr[lch].cnt>=k) return kth(lch, l, mid, k);
        return kth(rch, mid+1, r, k-tr[lch].cnt);
    }

    void merge(int &u,int v,int l,int r) {
        if(!u||!v) u=u|v;
        else if(l==r) {
            tr[u].cnt+=tr[v].cnt;
        }
        else {
            pushdn(u);
            int mid=(l+r)/2;
            merge(tr[u].lc, tr[v].lc, l, mid);
            merge(tr[u].rc, tr[v].rc, mid+1, r);
            pushup(u),pushup(v);
        }
    }

    pair<int,int> split(int u,int l,int r,int p) {
        if(r<p) return {u,0};
        if(l>=p) return {0,u};
        pushdn(u);
        int v=new_node();
        int mid=(l+r)/2;
        auto [a,b]=split(lch, l, mid, p);
        auto [c,d]=split(rch, mid+1, r, p);
        tr[u].lc=a,tr[u].rc=c;
        tr[v].lc=b,tr[v].rc=d;
        pushup(u),pushup(v);
        return {u,v};
    }

    pair<int,int> extract(int u,int l,int r,int x,int y) {
        auto [a,b]=split(u, l, r, x);
        auto [c,d]=split(b, l, r, y+1);
        merge(a, d, l, r);
        return {a,c};
    }

    LL query(int u,int l,int r,int x,int y) {
        if(!u||l>y||r<x) return {};
        if(l>=x&&r<=y) return tr[u].cnt;
        pushdn(u);
        int mid=(l+r)/2;
        return query(lch, l, mid, x, y)+query(rch, mid+1, r, x, y);
    }

    void modify(int &u,int l,int r,int p,int v) {
        if(!u) u=new_node();
        if(l==r) {
            tr[u].cnt+=v;
        }
        else {
            int mid=(l+r)/2;
            pushdn(u);
            if(p<=mid) modify(lch, l, mid, p, v);
            else modify(rch, mid+1, r, p, v);
            pushup(u);
        }
    }

    #undef lch
    #undef rch
}

void solve() {
    int n,m;
    cin>>n>>m;
    int idx=1;
    vector<int> rt(m+2);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        sgt::modify(rt[1], 1, n, i, in);
    }

    while(m--) {
        int op;
        cin>>op;
        if(op==0) {
            int p,l,r;
            cin>>p>>l>>r;
            tie(rt[p],rt[++idx])=sgt::extract(rt[p], 1, n, l, r);
        }
        else if(op==1) {
            int p,q;
            cin>>p>>q;
            sgt::merge(rt[p], rt[q], 1, n);
        }
        else if(op==2) {
            int p,x,q;
            cin>>p>>x>>q;
            sgt::modify(rt[p], 1, n, q, x);
        }
        else if(op==3) {
            int p,l,r;
            cin>>p>>l>>r;
            cout<<sgt::query(rt[p], 1, n, l, r)<<endl;
        }
        else {
            int p,k;
            cin>>p>>k;
            cout<<sgt::kth(rt[p], 1, n, k)<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}