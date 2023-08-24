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
constexpr int N=2e5+10;
pair<int,int> edg[N];
vector<int> v2id[N],est[N],fac[N];
vector<pair<int,int>> adj[N];
int arr[N];
LL ans[N];

template<typename T> vector<T> get_prime_factor(T x) {
    vector<T> res;
    for(T i=2;i*i<=x;i++) {
        if(x%i==0) {
            while(x%i==0) x/=i;
            res.push_back(i);
        }
    }
    if(x>1) res.push_back(x);
    return res;
}

template<typename T> vector<T> get_factor(T x) {
    vector<T> res;
    for(T i=1;i*i<=x;i++) {
        if(x%i==0) {
            res.push_back(i);
            if(x/i!=i) res.push_back(x/i);
        }
    }
    return res;
}

void init_est(int u,int fa) {
    for(auto [v,id]:adj[u]) {
        if(v!=fa) {
            init_est(v, u);
            int x=arr[u],y=arr[v];
            if(fac[x].size()>fac[y].size()) swap(x,y);
            for(int i:fac[x]) {
                if(binary_search(fac[y].begin(),fac[y].end(),i)) {
                    est[i].emplace_back(id);
                }
            }
        }
    }
}

struct DisjointUnionSet {
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
} dsu(N);

void solve() {
    for(int i=1;i<N;i++) {
        for(int j=1;i*j<N;j++) {
            fac[i*j].emplace_back(i);
        }
    }

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        v2id[arr[i]].emplace_back(i);
    }
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        edg[i]={u,v};
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
    }
    init_est(1, 0);

    for(int i=1;i<N;i++) {
        vector<int> cur;
        for(int j=1;i*j<N;j++) {
            for(int u:v2id[i*j]) {
                cur.emplace_back(u);
                dsu.fa[u]=u;
                dsu.sz[u]=1;
            }
        }
        if(cur.empty()) continue;
        
        for(int id:est[i]) {
            auto [u,v]=edg[id];
            dsu.join(u, v);
        }
        for(int u:cur)
            if(dsu.find(u)==u)
                ans[i]+=1LL*dsu.size(u)*(dsu.size(u)+1)/2;
    }

    for(int i=N-1;i>=1;i--) {
        for(int j=2;i*j<N;j++) {
            ans[i]-=ans[i*j];
        }
    }
    for(int i=1;i<N;i++) if(ans[i]) cout<<i<<' '<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}