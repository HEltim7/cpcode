#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
constexpr int N=1e5+10,M=2e5+10;

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

#define lch (u<<1)
#define rch (u<<1|1)
vector<pair<int,int>> seg[N*4];
bool ans[N];

void add(int u,int x,int y,int l,int r,pair<int,int> val) {
    if(x>r||y<l) return;
    if(x<=l&&y>=r) seg[u].emplace_back(val);
    else {
        int mid=(l+r)/2;
        add(lch,x,y,l,mid,val);
        add(rch,x,y,mid+1,r,val);
    }
}

void dfs(int u,int l,int r) {
    bool isok=1;
    for(auto [u,v]:seg[u]) {
        if(dsu.same(u, v)) isok=0;
        dsu.join(u, v+N);
        dsu.join(v, u+N);
    }
    if(l==r) ans[l]=isok;
    else if(isok) {
        int mid=(l+r)/2;
        dfs(lch,l,mid);
        dfs(rch,mid+1,r);
    }
    for(auto [u,v]:seg[u]) {
        dsu.undo();
        dsu.undo();
    }
}

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {
        int x,y,l,r;
        cin>>x>>y>>l>>r;
        add(1, l+1, r, 1, k, {x,y});
    }

    dfs(1, 1, k);
    for(int i=1;i<=k;i++) cout<<(ans[i]?"Yes":"No")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}