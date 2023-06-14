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
constexpr int N=2e5+10;
vector<int> arr;

template<class Info,int size> struct SegmentTree {
    #define lch ((u)<<1)
    #define rch ((u)<<1|1)

    int rng_l,rng_r;
    constexpr static int node_size=1<<__lg(size)<<2|1;
    array<Info, node_size> info;
    array<int, size+1> leaf;

    void pushup(int u) {
        info[u]=info[lch]+info[rch];
    }

    Info query(int u,int l,int r,int x,int y) {
        if(l>y||r<x) return {};
        if(l>=x&&r<=y) return info[u];
        int mid=(l+r)/2;
        return query(lch,l,mid,x,y)+query(rch,mid+1,r,x,y);
    }
    Info query(int l,int r) { return query(1,rng_l,rng_r,l,r); }

    void modify(int p,const Info &v) {
        int u=leaf[p];
        info[u]+=v;
        while(u>>=1) pushup(u);
    }

    template<class F>
    int find_first(int u,int l,int r,int x,int y,F check) {
        if(l>y||r<x||l>=x&&r<=y&&!check(info[u])) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        int res=find_first(lch,l,mid,x,y,check);
        if(res==-1) res=find_first(rch,mid+1,r,x,y,check);
        return res;
    }
    template<class F> int find_first(int l,int r,F check) {
        return find_first(1,rng_l,rng_r,l,r,check);
    }

    template<class F>
    int find_last(int u,int l,int r,int x,int y,F check) {
        if(l>y||r<x||l>=x&&r<=y&&!check(info[u])) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        int res=find_last(rch,mid+1,r,x,y,check);
        if(res==-1) res=find_last(lch,l,mid,x,y,check);
        return res;
    }
    template<class F> int find_last(int l,int r,F check) {
        return find_last(1,rng_l,rng_r,l,r,check);
    }

    void build(int u,int l,int r) {
        info[u].init(l,r);
        if(l!=r) {
            int mid=(l+r)/2;
            build(lch,l,mid);
            build(rch,mid+1,r);
            pushup(u);
        }
        else leaf[l]=u;
    }
    void build(int l=1,int r=size) { build(1,rng_l=l,rng_r=r); }

    #undef lch
    #undef rch
};

struct Info {
    int sum=0;
    int minn=N;

    void init(int l,int r) {
        if(l!=r) return;
        sum=arr[l];
        minn=arr[l];
    }
    void init(int l) { init(l,l); }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.sum=l.sum+r.sum;
        res.minn=min(l.minn,l.sum+r.minn);
        return res;
    }

    Info &operator+=(const Info &v) {
        sum=v.sum;
        minn=v.minn;
        return *this;
    }
};

SegmentTree<Info, N> sgt;

void solve() {
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    if(n==1) {
        while(q--) cout<<"NO"<<endl;
        return;
    }

    set<int> stl,str;

    auto add=[&](int idx) {
        if(idx<0||idx+1>=n) return;
        if(arr[idx]==1&&arr[idx+1]==1) stl.insert(idx);
        if(arr[idx]==-1&&arr[idx+1]==-1) str.insert(idx+1);
    };

    auto del=[&](int idx) {
        if(idx<0||idx+1>=n) return;
        if(arr[idx]==1&&arr[idx+1]==1) stl.erase(idx);
        if(arr[idx]==-1&&arr[idx+1]==-1) str.erase(idx+1);
    };
    
    for(auto x:s) arr.emplace_back(x=='('?1:-1);
    for(int i=0;i<n-1;i++) add(i);
    sgt.build(0,n-1);

    while(q--) {
        int idx;
        cin>>idx;
        idx--;
        
        del(idx-1),del(idx);
        arr[idx]=-arr[idx];
        add(idx-1),add(idx);

        sgt.modify(idx, Info{arr[idx],arr[idx]});
        if(sgt.query(0,n-1).sum%2) {
            cout<<"NO"<<endl;
            continue;
        }

        int lcnt=sgt.query(0,n-1).minn;
        if(lcnt<0) {
            lcnt=-lcnt;
            if(lcnt%2) lcnt++;
            if(stl.empty()) {
                cout<<"NO"<<endl;
                continue;
            }
            int l=*stl.begin();
            if(sgt.query(0,l-1).minn<0) {
                cout<<"NO"<<endl;
                continue;
            }
        }
        else lcnt=0;

        int rcnt=sgt.query(0,n-1).sum+lcnt;
        if(rcnt>0) {
            if(rcnt%2||str.empty()) {
                cout<<"NO"<<endl;
                continue;
            }
            int r=*str.rbegin();
            if(sgt.query(r+1,n-1).sum>0) {
                cout<<"NO"<<endl;
                continue;
            }
        }
        cout<<"YES"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}