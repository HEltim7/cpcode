#include <algorithm>
#include <array>
#include <bitset>
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
constexpr int N=1e5+10,M=61;

using DSU=struct DisjointUnionSet {
    vector<int> fa,sz;

    void init(int n) {
        fa.resize(n+1);
        sz.assign(n+1,1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }

    bool same(int x,int y) {
        return find(x)==find(y);
    }

    bool join(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y) return false;
        if(sz[x]<sz[y]) swap(x,y);
        sz[x]+=sz[y];
        fa[y]=x;
        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }

    DisjointUnionSet() = default;
    DisjointUnionSet(int n) { init(n); }
};

void solve() {
    LL val;
    int n,m,q;
    cin>>n>>m>>q>>val;
    
    vector<pair<LL,DSU>> vec;
    for(LL i=M,pre=0;i>=0;i--) {
        bool cur=val>>i&1;
        if(!pre&&!cur) {
            vec.emplace_back(1LL<<i,DSU(N));
        }
        else {
            if(cur) pre|=1LL<<i;
            else vec.emplace_back(pre|(1LL<<i),DSU(N));
        }
    }
    vec.emplace_back(val,DSU(N));

    while(m--) {
        int u,v;
        LL w;
        cin>>u>>v>>w;
        for(auto &[x,dsu]:vec) {
            if((x&w)==x) {
                dsu.join(u, v);
            }
        }
    }

    while(q--) {
        int u,v;
        cin>>u>>v;
        bool ans=0;
        for(auto &[x,dsu]:vec) {
            if(dsu.same(u, v)) {
                ans=1;
                break;
            }
        }
        cout<<(ans?"Yes":"No")<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}