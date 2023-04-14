#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
vector<int> adj[N];
int id[N],ed[N],ori[N],idx;
int ans[N];

void dfs(int u) {
    id[u]=++idx;
    ori[id[u]]=u;
    for(int v:adj[u]) dfs(v);
    ed[u]=idx;
}

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        int h;
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].h=min(tr[lch].h,tr[rch].h);
    }

    void pushdn(int u) {

    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            tr[u].h=min(tr[u].h,val);
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    int query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            return tr[u].h;
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            int res=N;
            if(mid>=l) res=min(res,query(lch, l, r));
            if(mid<r) res=min(res,query(rch, l, r));
            return res;
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) { tr[u].h=ans[ori[l]]; }
        else {
            int mid=l+r>>1;
            build(lch, l, mid);
            build(rch, mid+1, r);
            pushup(u);
        }
    }

    #undef lch
    #undef rch
} sgt;

int find(int u) {
    int p=sgt.query(1, id[ans[u]], ed[ans[u]]);
    if(p==u) return u;
    int res=find(p);
    sgt.modify(1, id[u], id[u], res);
    return ans[u]=res;
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) ans[i]=i;
    for(int i=2;i<=n;i++) {
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    dfs(1);
    sgt.build(1, 1, n);

    int q;
    cin>>q;
    while(q--) {
        int op,u,v;
        cin>>op>>u;
        debug(op,u);
        if(op==1) {
            cin>>v;
            sgt.modify(1, id[u], id[u], find(v));
        }
        else {
            cout<<find(u)<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}