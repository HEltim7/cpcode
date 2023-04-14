#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10,INF=1e9;

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        int min,laz;
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].min=min(tr[lch].min,tr[rch].min);
    }

    void update(int u,int val) {
        tr[u].min+=val,tr[u].laz+=val;
    }

    void pushdn(int u) {
        update(lch, tr[u].laz);
        update(rch, tr[u].laz);
        tr[u].laz=0;
    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) { update(u, val); }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    int find(int u) {
        if(tr[u].min>=0) return 0;
        if(tr[u].l==tr[u].r) return tr[u].l;
        pushdn(u);
        int res=find(lch);
        if(res) return res;
        return find(rch);
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) { tr[u].min=l; }
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
    int n;
    cin>>n;
    LL sum=0,tot=0;
    sgt.build(1, 1, n+1);
    for(int i=1;i<=n;i++) {
        int cur;
        cin>>cur;
        tot++,sum+=cur;
        sgt.modify(1, cur, n+1, -1);
        int pos=sgt.find(1);
        if(pos) {
            tot--,sum-=pos;
            sgt.modify(1, pos, n+1, 1);
        }
        cout<<sum-tot*(tot+1)/2<<" \n"[i==n];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}