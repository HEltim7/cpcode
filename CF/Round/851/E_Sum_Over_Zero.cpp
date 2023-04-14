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
constexpr int N=2e5+10,INF=1e9;
LL pre[N];
int arr[N];

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        int maxx;
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].maxx=max(tr[lch].maxx,tr[rch].maxx);
    }

    void pushdn(int u) {

    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) { tr[u].maxx=max(tr[u].maxx,val); }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    int query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { return tr[u].maxx; }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            int res=-INF;
            if(mid>=l) res=max(res,query(lch, l, r));
            if(mid<r) res=max(res,query(rch, l, r));
            return res;
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) { tr[u].maxx=-INF; }
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
    vector<LL> num;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        pre[i]=pre[i-1]+arr[i];
        num.push_back(pre[i]);
    }
    num.push_back(0);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        arr[i]=lower_bound(num.begin(),num.end(),pre[i])-num.begin()+1;
    
    int m=num.size()+5;
    sgt.build(1, 1, m);
    int ans=0;
    int zero=lower_bound(num.begin(),num.end(),0)-num.begin()+1;
    debug(zero);
    debug(arr,1,n);
    sgt.modify(1,zero,zero,0);
    for(int i=1;i<=n;i++) {
        int res=i+sgt.query(1, 1, arr[i]);
        ans=max(ans,res);
        debug(i,arr[i],res,ans);
        int t=sgt.query(1, arr[i], arr[i]);
        sgt.modify(1, arr[i], arr[i], ans-i);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}