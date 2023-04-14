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
constexpr int N=3e5+10;
constexpr LL INF=1e15;
int arr[N],cold[N],hot[N];

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        LL val,laz;
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].val=min(tr[lch].val,tr[rch].val);
    }

    void pushdn(int u) {
        tr[lch].laz+=tr[u].laz;
        tr[rch].laz+=tr[u].laz;
        tr[lch].val+=tr[u].laz;
        tr[rch].val+=tr[u].laz;
        tr[u].laz=0;
    }

    void modify(int u,int l,int r,LL val) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            tr[u].val+=val;
            tr[u].laz+=val;
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    void modify(int u,int p,LL val) {
        if(tr[u].l==tr[u].r) {
            tr[u].val=min(tr[u].val,val);
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=p) modify(lch,p,val);
            else modify(rch,p,val);
            pushup(u);
        }
    }

    LL query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            return tr[u].val;
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            LL res=INF;
            if(mid>=l) res=min(res,query(lch, l, r));
            if(mid<r) res=min(res,query(rch, l, r));
            return res;
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) {tr[u].val=INF;}
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
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=k;i++) cin>>cold[i];
    for(int i=1;i<=k;i++) cin>>hot[i];

    LL ans=0;
    vector<int> v(1,0);
    for(int i=1;i<=n;i++) {
        if(v.back()!=arr[i]) {
            v.push_back(arr[i]);
        }
        else ans+=hot[arr[i]];
    }
    debug(v);

    auto get=[&](int l,int r) {
        return l==r?hot[r]:cold[r];
    };

    n=v.size();
    sgt.build(1, 0, k);
    sgt.modify(1,0,0);
    for(int i=1;i<n;i++) {
        int cur=v[i],pre=v[i-1];
        LL res=sgt.query(1, cur, cur)+hot[cur];
        res=min(res,sgt.query(1, 0, k)+cold[cur]);

        sgt.modify(1,0,k,get(pre,cur));
        sgt.modify(1, pre, res);
    }
    cout<<ans+sgt.query(1, 0, k)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}