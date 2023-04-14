#include <set>
#include <map>
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
constexpr int N=2e5+10,INF=0x3f3f3f3f;
int a[N],b[N],h[N],R[N];

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        int minn,laze;
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].minn=min(tr[lch].minn,tr[rch].minn);
    }

    void pushdn(int u) {
        tr[lch].minn=min(tr[lch].minn,tr[u].laze);
        tr[rch].minn=min(tr[rch].minn,tr[u].laze);
        tr[lch].laze=min(tr[lch].laze,tr[u].laze);
        tr[rch].laze=min(tr[rch].laze,tr[u].laze);
    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            tr[u].minn=min(tr[u].minn,val);
            tr[u].laze=min(tr[u].laze,val);
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    int query(int u,int p) {
        if(tr[u].l==tr[u].r) {
            return tr[u].minn;
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=p) return query(lch, p);
            return query(rch, p);
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r,INF,INF};
        if(l==r) {
            tr[u].minn=a[l];
        }
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

template<typename T=int> struct Fenwick {
    std::vector<T> tr;
    int sz=0;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) {
        aim=max(aim,val);
    }

    void add(int pos,T val) {
        while(pos<=sz) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=0;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int n) { tr.resize(sz=n+1); }
};

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    multiset<int> st;
    int m;
    cin>>m;
    for(int i=1;i<=m;i++) cin>>h[i],st.insert(h[i]);
    sgt.build(1, 1, n);

    Fenwick<> tr(n+5);
    for(int i=n;i>=1;i--) {
        int l=i,r=n;
        while(l<r) {
            int mid=l+r+1>>1;
            if(tr.query(mid)>b[i]) r=mid-1;
            else l=mid;
        }
        R[i]=l;
        tr.add(i, b[i]);
    }

    for(int i=1;i<=n;i++) {
        int cur=sgt.query(1, i);
        if(cur<b[i]) {
            cout<<"NO"<<endl;
            return;
        }
        else if(cur>b[i]) {
            auto it=st.find(b[i]);
            if(it==st.end()) {
                cout<<"NO"<<endl;
                return;
            }
            st.erase(it);
            sgt.modify(1, i, R[i], b[i]);
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}