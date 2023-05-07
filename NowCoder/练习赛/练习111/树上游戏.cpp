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
constexpr int N=1e5+10;
vector<pair<int,int>> adj[N];
int type[N],id[N],ed[N],idx;
bool ans[N],tort[N],toleaf[N],isleaf[N];

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

void init(int u,int fa) {
    int ch=0;
    id[u]=++idx;
    for(auto [v,_]:adj[u]) {
        if(v!=fa) {
            ch++;
            init(v, u);
        }
    }
    if(!ch) isleaf[u]=1;
    ed[u]=idx;
}

void dfs(int u,int fa) {
    for(auto [v,_]:adj[u]) {
        if(v!=fa) {
            if(type[v]==1||type[v]==3) {
                tort[v]|=!tort[u];
            }
            if(type[v]==2||type[v]==3) {
                tort[v]|=!tort[fa];
            }
            dfs(v,u);
            if(type[v]==1||type[v]==3) {
                toleaf[u]|=!toleaf[v];
            }
            if(type[v]==2||type[v]==3) {
                toleaf[fa]|=!toleaf[v];
            }
        }
    }
    debug(u,toleaf[u]);
}

void solve(int u,int fa) {
    for(auto [v,eid]:adj[u]) {
        if(v!=fa) {
            int cur=tr.query(N);
            cur-=tr.query(ed[v])-tr.query(id[v]-1);
            if(cur) ans[eid]=1;
            if(toleaf[v]) ans[eid]=1;
            debug(u,v,cur,toleaf[v]);
            solve(v,u);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>type[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
    }
    init(1, 0);
    tort[0]=1;
    dfs(1, 0);

    for(int i=1;i<=n;i++) {
        if(tort[i]&&isleaf[i]) {
            tr.add(id[i], 1);
        }
    }
    solve(1,0);

    for(int i=1;i<n;i++) {
        if(ans[i]) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}