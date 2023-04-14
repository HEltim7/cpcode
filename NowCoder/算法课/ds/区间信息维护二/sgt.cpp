#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAX_SIZE=N;

    struct Node {
        int l,r;

    } tr[MAX_SIZE<<2];
    int leaf[MAX_SIZE];

    void pushup(int u) {

    }

    void pushdn(int u) {

    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) {}
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    void modify(int p,int val) {
        int u=leaf[p];
        do {
            
        } while(u>>=1);
    }

    int query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) {}
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            
            if(mid>=l) query(lch, l, r);
            if(mid<r) query(rch, l, r);
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) {}
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

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}