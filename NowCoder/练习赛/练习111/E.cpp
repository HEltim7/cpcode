#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
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
constexpr int N=1e5+10;
using BS=bitset<N>;
vector<pair<int,int>> adj[N];
int type[N],dfn[N],idx;
bool ans[N];
BS win[N];

void init(int u,int fa) {
    dfn[u]=idx++;
    for(auto [v,id]:adj[u]) {
        if(v!=fa) {
            init(v, u);
        }
    }
}

void dfs(int u,int fa) {
    for(auto [v,id]:adj[u]) {
        if(v!=fa) {
            // if(type[v]==1||type[v]==3) {
            //     win[v]|=los[u];
            // }
            // if(type[v]==2||type[v]==3) {
            //     win[v]|=los[fa];
            // }
            // los[v]=win[v];
            // los[v].flip();
            dfs(v,u);
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
    init(1,0);
    // los[0].set();
    // los[1].set();
    dfs(1,0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}