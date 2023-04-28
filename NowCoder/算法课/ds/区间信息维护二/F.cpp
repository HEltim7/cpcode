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
constexpr int N=3e5+10;
int arr[N],mex[N],ans[N];

struct Info {
    int minn;

    void init(int l,int r) {
        if(l!=r) return;
        minn=0;
    }
    void init(int l) { init(l,l); }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.minn=min(l.minn,r.minn);
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

    int find(int u,int l) {
        if(tr[u].l==tr[u].r) return tr[u].l;
        if(tr[lch].info.minn>=l) return find(rch,l);
        return find(lch,l);
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

template<typename T=int,T init=T()> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim+=val; }

    void add(int pos,T val) {
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=init;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    void resize(int n) {
        size=n;
        tr.resize(size+1,init);
    }

    Fenwick()=default;
    Fenwick(int n):size(n) { tr.resize(size+1,init); }
};
Fenwick<> tr(N);

void solve() {
    int n;
    cin>>n;
    sgt.build(1,n+1);

    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(arr[i]>n) arr[i]=N-5;
    }
    int m;
    cin>>m;
    vector<tuple<int,int,int>> qry(m);

    int qid=0;
    for(auto &[r,l,id]:qry) {
        cin>>l>>r;
        id=++qid;
    }
    sort(qry.begin(),qry.end());
    
    int idx=0;
    vector<tuple<int,int,int>> ask;
    for(auto [r,l,id]:qry) {
        while(idx<r) {
            idx++;
            sgt.modify(arr[idx], Info{idx});
        }
        mex[id]=sgt.find(1,l);
        ask.emplace_back(r,id,-1);
        ask.emplace_back(l-1,id,1);
        ans[id]=r-l+1;
    }
    sort(ask.begin(),ask.end());
    debug(ans,1,m);
    debug(mex,1,m);

    idx=0;
    for(auto [p,id,sign]:ask) {
        while(idx<p) {
            idx++;
            tr.add(arr[idx], 1);
        }
        
        ans[id]+=sign*tr.query(mex[id]-1);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}