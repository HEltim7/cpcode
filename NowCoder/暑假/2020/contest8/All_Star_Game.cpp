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

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;

struct DisjointUnionSet {
    vector<int> fa,sz;
    vector<pair<int&,int>> fah,szh;

    void init(int n) {
        fah.clear();
        szh.clear();
        fa.resize(n+1);
        sz.assign(n+1,1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        while(x!=fa[x]) x=fa[x];
        return x;
    }

    bool same(int x,int y) {
        return find(x)==find(y);
    }

    bool join(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y) {
            fah.emplace_back(fa[0],fa[0]);
            szh.emplace_back(sz[0],sz[0]);
            return false;
        }
        if(sz[x]<sz[y]) swap(x,y);
        fah.emplace_back(fa[y],fa[y]);
        szh.emplace_back(sz[x],sz[x]);
        sz[x]+=sz[y];
        fa[y]=x;
        return true;
    }

    void undo() {
        assert(!fah.empty());
        fah.back().first=fah.back().second;
        szh.back().first=szh.back().second;
        fah.pop_back(),szh.pop_back();
    }

    int size(int x) {
        return sz[find(x)];
    }

    DisjointUnionSet() = default;
    DisjointUnionSet(int n) { init(n); }
} dsu(N*2);

namespace sd {
    #define lch (u<<1)
    #define rch (u<<1|1)
    using T=pair<int,int>;
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

    int ans[N],res;
    void solve(int u,int l,int r) {
        // apply
        int cur=0;
        for(auto [u,v]:seg[u]) {
            if(dsu.join(u, v)) res++,cur++;
        }

        // update ans
        if(l==r) ans[l]=res;
        else {
            int mid=(l+r)/2;
            solve(lch,l,mid);
            solve(rch,mid+1,r);
        }

        // undo
        for(auto x:seg[u]) dsu.undo();
        res-=cur;
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

int cnt[N*2];
void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    int lcnt=n,rcnt=m;
    sd::init(0, q);
    map<pair<int,int>,int> mp;
    for(int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) {
            int v;
            cin>>v;
            v+=N;
            mp[{i,v}]=0;
            if(++cnt[i]==1) lcnt--;
            if(++cnt[v]==1) rcnt--;
        }
    }

    vector<int> add(q+1);
    for(int i=1;i<=q;i++) {
        int u,v;
        cin>>v>>u;
        v+=N;
        auto it=mp.find({u,v});
        if(it!=mp.end()) {
            sd::add(it->second,i-1,{u,v});
            mp.erase(it);
            if(--cnt[u]==0) lcnt++;
            if(--cnt[v]==0) rcnt++;
        }
        else {
            mp[{u,v}]=i;
            if(++cnt[u]==1) lcnt--;
            if(++cnt[v]==1) rcnt--;
        }
        if(rcnt) add[i]=-1;
        else add[i]=lcnt;
    }

    for(auto [e,t]:mp) sd::add(t,q,e);
    sd::solve();
    for(int i=1;i<=q;i++) {
        if(add[i]==-1) cout<<-1<<endl;
        else cout<<n+m-sd::ans[i]-add[i]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}