#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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
vector<LL> ans(N);
vector<pair<int,int>> p(N);

struct DisjointUnionSet {
    vector<int> fa,sz,dx,dy;
    vector<pair<int&,int>> hfa,hsz,hdx,hdy;

    void init(int n) {
        hfa.clear();
        hsz.clear();
        hdx.clear();
        hdy.clear();

        fa.resize(n+1);
        sz.assign(n+1,1);
        dx.assign(n+1,1);
        dy.assign(n+1,1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        while(x!=fa[x]) x=fa[x];
        return x;
    }

    bool same(int x,int y) {
        return find(x)==find(y);
    }

    LL join(int x,int y,bool addx,bool addy) {
        x=find(x);
        y=find(y);
        if(x==y) {
            hfa.emplace_back(fa[0],fa[0]);
            hsz.emplace_back(sz[0],sz[0]);
            hdx.emplace_back(dx[0],dx[0]);
            hdy.emplace_back(dy[0],dy[0]);
            return 0;
        }
        LL pre=1LL*dx[x]*dy[x]+1LL*dx[y]*dy[y];
        if(sz[x]<sz[y]) swap(x,y);
        hfa.emplace_back(fa[y],fa[y]);
        hsz.emplace_back(sz[x],sz[x]);
        hdx.emplace_back(dx[x],dx[x]);
        hdy.emplace_back(dy[x],dy[x]);
        fa[y]=x;
        sz[x]+=sz[y];
        if(addx) dx[x]+=dx[y];
        if(addy) dy[x]+=dy[y];
        LL cur=1LL*dx[x]*dy[x];
        return cur-pre;
    }

    void undo() {
        assert(!hfa.empty());
        hfa.back().first=hfa.back().second;
        hsz.back().first=hsz.back().second;
        hdx.back().first=hdx.back().second;
        hdy.back().first=hdy.back().second;
        hfa.pop_back(),hsz.pop_back();
        hdx.pop_back(),hdy.pop_back();
    }

    int size(int x) {
        return sz[find(x)];
    }

    DisjointUnionSet() = default;
    DisjointUnionSet(int n) { init(n); }
} dsu(N);

namespace sd {
    #define lch (u<<1)
    #define rch (u<<1|1)
    using T=int;
    vector<vector<T>> seg;
    int rng_l,rng_r;

    void add(int u,int x,int y,int l,int r,T val) {
        if(x>r||y<l) return;
        if(x<=l&&y>=r) seg[u].emplace_back(val);
        else {
            int mid=(l+r)/2;
            add(lch,x,y,l,mid,val);
            add(rch,x,y,mid+1,r,val);
        }
    }
    void add(int x,int y,T val) {
        add(1,x,y,rng_l,rng_r,val);
    }

    auto res=vector<LL>(1);
    auto cnt=vector<int>();
    auto lastx=vector(N,vector<int>());
    auto lasty=vector(N,vector<int>());
    
    void solve(int u,int l,int r) {
        for(int id:seg[u]) {
            auto [x,y]=p[id];
            LL sum=res.back()+1;
            if(lastx[x].empty()&&lasty[y].empty()) cnt.emplace_back(0);
            else if(lasty[y].empty()) {
                sum+=dsu.join(id, lastx[x].back(), false, true);
                cnt.emplace_back(1);
            }
            else if(lastx[x].empty()) {
                sum+=dsu.join(id, lasty[y].back(), true, false);
                cnt.emplace_back(1);
            }
            else {
                sum+=dsu.join(lastx[x].back(), lasty[y].back(), true, true);
                sum+=dsu.join(id, lastx[x].back(), false, false);
                cnt.emplace_back(2);
            }
            lastx[x].emplace_back(id);
            lasty[y].emplace_back(id);
            res.emplace_back(sum);
        }

        if(l==r) ans[l]=res.back();
        else {
            int mid=(l+r)/2;
            solve(lch,l,mid);
            solve(rch,mid+1,r);
        }

        for(int id:seg[u]) {
            auto [x,y]=p[id];
            while(cnt.back()--) dsu.undo();
            cnt.pop_back();
            lastx[x].pop_back();
            lasty[y].pop_back();
            res.pop_back();
        }
    }
    void solve() {
        solve(1,rng_l,rng_r);
    }

    void init(int l,int r) {
        rng_l=l,rng_r=r;
        seg.clear();
        seg.resize(4<<__lg(r-l+1)|1);
    }

    #undef lch
    #undef rch
}

void solve() {
    int q;
    cin>>q;
    sd::init(1, q);

    map<pair<int,int>,int> last;
    for(int i=1;i<=q;i++) {
        int x,y;
        cin>>x>>y;
        auto it=last.find({x,y});
        if(it==last.end()) last[{x,y}]=i,p[i]={x,y};
        else {
            int l=it->second;
            int r=i-1;
            sd::add(l,r,l);
            last.erase(it);
        }
    }

    for(auto [x,y]:last) sd::add(y,q,y);
    sd::solve();
    for(int i=1;i<=q;i++) cout<<ans[i]<<" \n"[i==q];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}