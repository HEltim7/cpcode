#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],brr[N],pos[N];
bool mark[N];

template<typename T=int> struct Fenwick {
    std::vector<T> tr;
    int sz=0;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) {
        aim+=val;
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

    void modify(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { tr[u].maxx=0; }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r);
            if(mid<r) modify(rch, l, r);
            pushup(u);
        }
    }

    int query(int u,int l,int r,int val,bool dir) {
        if(tr[u].maxx<=val) return -1;
        else if(tr[u].l==tr[u].r) return tr[u].l;
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            int res=-1;

            if(dir) {
                if(mid>=l) res=query(lch, l, r, val, dir);
                if(res!=-1) return res;
                return query(rch, l, r, val, dir);
            }
            else {
                if(mid<r) res=query(rch, l, r, val, dir);
                if(res!=-1) return res;
                return query(lch, l, r, val, dir);
            }
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) {tr[u].maxx=arr[l];}
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> del;
    Fenwick<> tr(n+10);
    multiset<int> lens;

    arr[0]=arr[n+1]=n+1;
    for(int i=1;i<=n;i++) cin>>arr[i],pos[arr[i]]=i;
    for(int i=1;i<=n;i++) mark[i]=0;
    for(int i=1;i<=m;i++) cin>>brr[i],mark[brr[i]]=1;
    for(int i=n;i>=1;i--) if(!mark[i]) del.push_back(i);
    for(int i=1,in;i<=k;i++) cin>>in,lens.insert(in);
    sgt.build(1, 0, n+1);

    for(int i=1,j=1;i<=m;i++) {
        while(j+1<=n&&arr[j]!=brr[i]) j++;
        if(arr[j]!=brr[i]) {
            cout<<"NO"<<endl;
            return;
        }
    }

    if(k+m<n) {
        cout<<"NO"<<endl;
        return;
    }

    for(auto x:del) {
        int l=sgt.query(1, 0, pos[x]-1, x, 0)+1;
        int r=sgt.query(1, pos[x]+1, n+1, x, 1)-1;
        int d=tr.query(r)-tr.query(l-1);
        int len=r-l+1-d;
        auto it=lens.upper_bound(len);
        if(it==lens.begin()) {
            cout<<"NO"<<endl;
            return;
        }
        lens.erase(--it);
        sgt.modify(1, pos[x], pos[x]);
        tr.add(pos[x], 1);
        debug(x,len,lens);
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