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
constexpr int N=1e6+10;

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
    int find_first(int u,int l,int r,int x,int y,F check,Info &suf) {
        if(l==r&&!check(info[u]+suf)) return -1;
        if(l>=x&&r<=y&&check(info[u]+suf)) return suf=info[u]+suf,l;
        int mid=(l+r)/2;
        if(mid>=x&&mid<y) {
            int res=find_first(rch,mid+1,r,x,y,check,suf);
            if(res==mid+1) {
                int t=find_first(lch,l,mid,x,y,check,suf);
                if(t!=-1) res=t;
            }
            return res;
        }
        else if(mid>=x) return find_first(lch,l,mid,x,y,check,suf);
        return find_first(rch,mid+1,r,x,y,check,suf);
    }
    template<class F> int find_first(int l,int r,F check,Info suf={}) {
        l=max(l,rng_l),r=min(r,rng_r);
        return l>r?-1:find_first(1,rng_l,rng_r,l,r,check,suf);
    }

    template<class F>
    int find_last(int u,int l,int r,int x,int y,F check,Info &pre) {
        if(l==r&&!check(pre+info[u])) return -1;
        if(l>=x&&r<=y&&check(pre+info[u])) return pre=pre+info[u],r;
        int mid=(l+r)/2;
        if(mid>=x&&mid<y) {
            int res=find_last(lch,l,mid,x,y,check,pre);
            if(res==mid) {
                int t=find_last(rch,mid+1,r,x,y,check,pre);
                if(t!=-1) res=t;
            }
            return res;
        }
        else if(mid>=x) return find_last(lch,l,mid,x,y,check,pre);
        return find_last(rch,mid+1,r,x,y,check,pre);
    }
    template<class F> int find_last(int l,int r,F check,Info pre={}) {
        l=max(l,rng_l),r=min(r,rng_r);
        return l>r?-1:find_last(1,rng_l,rng_r,l,r,check,pre);
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

int arr[N],pre[N];

struct Info {
    int minn=N;
    int sum=0;

    void init(int l,int r) {
        if(l!=r) return;
        minn=sum=arr[l];
    }
    void init(int l) { init(l,l); }

    friend Info operator+(const Info &l,const Info &r) {
        Info res;
        res.minn=min(l.minn,l.sum+r.minn);
        res.sum=l.sum+r.sum;
        return res;
    }

    Info &operator+=(const Info &v) {
        
        return *this;
    }
};

SegmentTree<Info, N> sgt;
vector<int> pos[2*N];
constexpr int off=N;

void solve() {
    string s;
    cin>>s;

    pos[off].emplace_back(-1);
    for(int i=0;i<s.size();i++) {
        arr[i+1]=s[i]=='('?1:-1;
        pre[i+1]=pre[i]+arr[i+1];
        auto &cur=pos[off+pre[i+1]];
        if(cur.empty()) cur.emplace_back(-1);
        cur.emplace_back(i+1);
    }
    int n=s.size();
    sgt.build(1,n);
    
    int maxx=0,cnt=1;
    for(int i=1;i<n;i++) {
        int idx=sgt.find_last(i,n,[](const Info &x) {return x.minn>=0;});
        auto &cur=pos[off+pre[i-1]];
        auto it=upper_bound(cur.begin(),cur.end(),idx);
        int p=*--it;
        if(p>i) {
            int len=p-i+1;
            if(maxx==len) cnt++;
            else if(len>maxx) maxx=len,cnt=1;
        }
    }

    cout<<maxx<<' '<<cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}