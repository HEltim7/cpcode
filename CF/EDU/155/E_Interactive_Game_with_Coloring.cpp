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

using LL=long long;
using ARR=array<int,4>;
constexpr int N=110;
int p[N],col[N];
vector<int> adj[N];

// 大坑 k=2时根可以选择每个子树以0开始还是1开始
bool valid=true;
map<ARR,int> go;
void dfs(int u,int c,int mod) {
    for(int v:adj[u]) {
        col[v]=c;
        ARR cur{};
        cur[c]=1;
        cur[c%mod+1]=adj[v].size();
        auto it=go.find(cur);
        if(it!=go.end()&&it->second!=c) valid=false;
        go[cur]=c;
        dfs(v, c%mod+1, mod);
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        cin>>p[i];
        adj[p[i]].emplace_back(i);
    }

    if(adj[1].size()+1==n) {
        cout<<1<<endl;
        for(int i=2;i<=n;i++) cout<<1<<' ';
        cout<<endl;
        cout<<1<<endl;
        return;
    }

    int k=2;
    auto read=[&]() {
        int st;
        cin>>st;
        if(st) exit(0);
        ARR cnt{};
        for(int i=1;i<=k;i++) cin>>cnt[i];
        return cnt;
    };

    for(;k<=3;k++) {
        valid=true;
        go.clear();
        dfs(1, 1, k);
        if(valid) break;
    }
    assert(valid);

    cout<<k<<endl;
    for(int i=2;i<=n;i++) {
        cout<<col[i]<<' ';
    }
    cout<<endl;

    for(;;) {
        ARR in=read();
        cout<<go[in]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}