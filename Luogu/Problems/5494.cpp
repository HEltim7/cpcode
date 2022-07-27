#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10,M=36*N;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

int root[N],id,idx;

struct Node {
    int l,r;
    LL cnt;
} tr[M];

int new_node() {
    assert(idx<M);
    return ++idx;
}

void pushup(int u) {
    assert(u);
    tr[u].cnt=0;
    if(tr[u].l) tr[u].cnt+=tr[tr[u].l].cnt;
    if(tr[u].r) tr[u].cnt+=tr[tr[u].r].cnt;
}

void modify(int u,int l,int r,int p,int v) {
    if(l==r) tr[u].cnt+=v;
    else {
        int mid=l+r>>1;
        if(p<=mid) {
            if(!tr[u].l) tr[u].l=new_node();
            modify(tr[u].l, l, mid, p, v);
        }
        else {
            if(!tr[u].r) tr[u].r=new_node();
            modify(tr[u].r, mid+1, r, p, v);
        }
        pushup(u);
    }
}

//merge v to u
void merge(int &u,int v) {
    if(!u||!v) u=u+v;
    else {
        tr[u].cnt+=tr[v].cnt;
        merge(tr[u].l, tr[v].l);
        merge(tr[u].r, tr[v].r);
    }
}

//split u to v [1-k]->u [k+1-INF]->v
void split(int &u,int &v,int l,int r,int k) {
    if(!u||k>=r) return;
    if(k<l) swap(u,v);
    else {
        v=new_node();
        int mid=l+r>>1;
        if(k<=mid) swap(tr[u].r,tr[v].r);
        if(k<mid) split(tr[u].l, tr[v].l, l, mid, k);
        else split(tr[u].r, tr[v].r, mid+1, r, k);
        pushup(u),pushup(v);
    }
}

LL count(int u,int l,int r,int x,int y) {
    if(!u) return 0;
    if(l>=x&&r<=y) return tr[u].cnt;
    int mid=l+r>>1;
    LL res=0;
    if(mid>=x) res+=count(tr[u].l,l,mid,x,y);
    if(mid<y) res+=count(tr[u].r,mid+1,r,x,y);
    return res;
}

int kth(int u,int l,int r,LL k) {
    if(tr[u].cnt<k) return -1;
    if(l==r) return l;
    int mid=l+r>>1;
    if(tr[tr[u].l].cnt>=k) return kth(tr[u].l, l, mid, k);
    return kth(tr[u].r, mid+1, r, k-tr[tr[u].l].cnt);
}

void solve() {
    root[++id]=++idx;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        modify(root[1], 1, N-1, i, in);
    }
    while(m--) {
        int op,p,x,y;
        cin>>op>>p>>x;
        if(op==0||op==2||op==3) cin>>y;
        if(op==0) {
            int tmp=0;
            split(root[p], root[++id], 1, N-1, x-1);
            split(root[id], tmp, 1, N-1, y);
            merge(root[p],tmp);
        }
        else if(op==1) {
            merge(root[p],root[x]);
        }
        else if(op==2) {
            modify(root[p], 1, N-1, y, x);
        }
        else if(op==3) {
            cout<<count(root[p], 1, N-1, x, y)<<endl;
        }
        else if(op==4) {
            cout<<kth(root[p], 1, N-1, x)<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}