#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,B=31;
map<int,int> mp;
int arr[N];

int root[N*B],rtid[N];
struct PersistentSegmentTree {

    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    constexpr static int MAX_SIZE=N*B*B;

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
        tr[u].cnt=tr[lch].cnt+tr[rch].cnt;
    }

    void modify(int &u,int v,int l,int r,int p,int val) {
        u=new_node();
        tr[u]=tr[v];
        if(l==r) tr[u].cnt+=val;
        else {
            int mid=l+r>>1;
            if(p<=mid) modify(lch, tr[v].ch[0], l, mid, p, val);
            else modify(rch, tr[v].ch[1], mid+1, r, p, val);
            pushup(u);
        }
    }

    int query(int u,int l,int r,int p) {
        if(l>=p) return tr[u].cnt;
        int mid=l+r>>1;
        int res=0;
        if(p<=mid) return query(lch, l, mid, p)+query(rch, mid+1, r, p);
        return query(rch, mid+1, r, p);
    }

    int kth(int u,int v,int l,int r,int k) {
        if(l==r) return l;
        int mid=l+r>>1;
        int lcnt=tr[lch].cnt-tr[tr[v].ch[0]].cnt;
        if(lcnt>=k) return kth(lch, tr[v].ch[0], l, mid, k);
        return kth(rch, tr[v].ch[1], mid+1, r, k-lcnt);
    }

    void build(int &u,int l,int r) {
        u=new_node();
        tr[u]={l,r};
        if(l!=r) {
            int mid=l+r>>1;
            build(lch,l,mid);
            build(rch,mid+1,r);
        }
    }

    #undef lch
    #undef rch

} psgt;

struct Info {
    int val;
    void init(int l,int r) {
        if(l!=r) return;
        val=arr[l];
    }
    void init(int l) { init(l,l); }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.val=l.val&r.val;
        return res;
    }
};

template<class Info,int size> struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)

    struct Node {
        int l,r;
        Info info;
        void init(int l,int r) {
            this->l=l;
            this->r=r;
            info.init(l, r);
        }
    };

    array<Node, 1<<__lg(size)<<2|1> tr;
    array<int, size+1> leaf;

    void pushup(int u) {
        tr[u].info=tr[lch].info+tr[rch].info;
    }

    Info query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { return tr[u].info; }
        else {
            int mid=(tr[u].l+tr[u].r)/2;
            if(mid>=l&&mid<r) return query(lch,l,r)+query(rch,l,r);
            else if(mid>=l) return query(lch,l,r);
            return query(rch,l,r);
        }
    }
    Info query(int l,int r) { return query(1,l,r); }

    void modify(int p,const Info &v) {
        int u=leaf[p];
        tr[u].info=v;
        while(u>>=1) pushup(u);
    }

    int find(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r&&(tr[u].info.val&val)==val) return 0;
        if(tr[u].l==tr[u].r) return tr[u].l;
        int mid=tr[u].l+tr[u].r>>1;
        if(mid<r) {
            int t=find(rch, l, r, val);
            if(t) return t;
        }
        if(mid>=l) {
            int t=find(lch, l, r, val);
            if(t) return t;
        }
        return 0;
    }

    void build(int u,int l,int r) {
        tr[u].init(l,r);
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
            pushup(u);
        }
        else leaf[l]=u;
    }
    void build(int l=1,int r=size) { build(1,l,r); }

    #undef lch
    #undef rch
};
SegmentTree<Info, N> sgt;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sgt.build(1,n);
    psgt.build(root[0], 1, n);
    for(int i=1,id=0;i<=n;i++) {
        int val=arr[i];
        for(int idx=i;idx;) {
            val&=arr[idx];
            auto it=mp.find(val);
            if(it!=mp.end()) {
                int p=it->second;
                id++;
                psgt.modify(root[id], root[id-1], 1, n, p, -1);
                debug(val,p,-1);
            }
            mp[val]=idx;
            id++;
            psgt.modify(root[id], root[id-1], 1, n, idx, 1);
            debug(val,idx,1);
            idx=sgt.find(1, 1, idx, val);
            assert(!idx||(val&arr[idx])!=val);
        }
        rtid[i]=id;
    }
    debug(mp);

    int q,ans=0;
    cin>>q;
    while(q--) {
        int l,r;
        cin>>l>>r;
// #define LOCAL
#ifndef LOCAL
        l=(l^ans)%n+1;
        r=(r^ans)%n+1;
        if(l>r) swap(l,r);
#endif
        debug(l,r,rtid[r]);
        ans=psgt.query(root[rtid[r]], 1, n, l);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}