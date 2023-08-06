#include <algorithm>
#include <array>
#include <bitset>
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
constexpr int N=1e6+10;
vector<int> adj[N];
int sz[N];

template<int sz=1> int solve(int n,vector<int> &item) {
    if(sz<n+1) return solve<min(sz*2,N)>(n,item);
    bitset<sz> bs;
    bs[n]=1;
    for(int x:item) bs|=bs>>x;
    return bs._Find_first();
}

LL dfs(int u) {
    LL res=0;
    sz[u]=1;
    if(adj[u].empty()) return res;
    int maxsz=0;
    for(int v:adj[u]) {
        res+=dfs(v);
        sz[u]+=sz[v];
        maxsz=max(maxsz,sz[v]);
    }
    if(adj[u].size()==1) return res;
    if(maxsz>=(sz[u]-1)/2) return res+1LL*maxsz*(sz[u]-1-maxsz);
    
    map<int,int> mp;
    vector<int> item;
    for(int v:adj[u]) mp[sz[v]]++;
    for(auto [x,y]:mp) {
        for(int i=1;y;i<<=1) {
            int t=min(i,y);
            item.emplace_back(x*t);
            y-=t;
        }
    }
    int n=(sz[u]-1)/2;
    int maxx=n-solve(n, item);

    return res+1LL*maxx*(sz[u]-1-maxx);
}

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        int p;
        cin>>p;
        adj[p].emplace_back(i);
    }
    cout<<dfs(1)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}