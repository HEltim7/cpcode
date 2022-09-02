#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int root[N],fa[N],id[N];

int findfa(int x) {
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

struct MergeSplitSegmentTree {

    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    constexpr static int MAX_SIZE=N*20;
    
    struct Node {
        int ch[2];
        int cnt;
    } tr[MAX_SIZE];
    int idx;

    int new_node() {
        assert(idx<MAX_SIZE);
        return ++idx;
    }

    void pushup(int u) {
        if(lch&&rch) tr[u].cnt=tr[lch].cnt+tr[rch].cnt;
        else if(lch) tr[u].cnt=tr[lch].cnt;
        else if(rch) tr[u].cnt=tr[rch].cnt;
    }
    
    void merge(int &u,int v) {
        if(!u||!v) u=max(u,v);
        else {
            merge(lch,tr[v].ch[0]);
            merge(rch,tr[v].ch[1]);
            pushup(u);
        }
    }

    int kth(int u,int l,int r,int k) {
        if(tr[u].cnt<k) return -1;
        if(l==r) return id[l];
        int mid=l+r>>1;
        if(tr[lch].cnt>=k) return kth(lch, l, mid, k);
        return kth(rch, mid+1, r, k-tr[lch].cnt);
    }

    void build(int &u,int l,int r,int p) {
        u=new_node();
        if(l==r) tr[u].cnt=1;
        else {
            int mid=l+r>>1;
            if(p<=mid) build(lch,l,mid,p);
            else build(rch,mid+1,r,p);
            pushup(u);
        }
    }

    #undef lch
    #undef rch

} sgt;

void solve() {
    int n,m,q;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        fa[i]=i;
        int rank;
        cin>>rank;
        id[rank]=i;
        sgt.build(root[i], 1, n, rank);
    }
    while(m--) {
        int u,v;
        cin>>u>>v;
        u=findfa(u),v=findfa(v);
        if(u!=v) sgt.merge(root[u], root[v]);
        fa[v]=u;
    }
    cin>>q;
    while(q--) {
        char op;
        int x,y;
        cin>>op>>x>>y;
        if(op=='Q') cout<<sgt.kth(root[findfa(x)], 1, n, y)<<endl;
        else {
            x=findfa(x),y=findfa(y);
            if(x!=y) sgt.merge(root[x], root[y]);
            fa[y]=x;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}