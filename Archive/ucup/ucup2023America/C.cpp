#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10,M=3e3+10;
vector<pair<int,int>> adj[N];
int w[M];
bool isok[M];

void solve() {
    int n,m;
    cin>>n>>m;
    vector<tuple<int,bool,int,int,int>> edg;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v>>w[i];
        edg.emplace_back(w[i],i>=n,u,v,i);
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
        isok[i]=i<n;
    }
    sort(edg.begin(),edg.end());
    vector<pair<int,int>> ans;

    for(int i=0;i<m;i++) {
        auto [l,t,x,y,id]=edg[i];
        function<int(int,int)> dfs=[&](int u,int fa) {
            for(auto [v,id]:adj[u]) {
                if(v!=fa&&isok[id]) {
                    int res=0;
                    if(v==y) res=id;
                    else res=dfs(v, u);
                    if(res) return w[id]>w[res]?id:res;
                }
            }
            return 0;
        };
        
        int res=dfs(x, y);
        debug(x,y,id,res);
        if(res&&w[res]>l) {
            isok[res]=0;
            isok[id]=1;
            ans.emplace_back(res,id);
        }
    }
    
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}

/*
10 14
1 8 6
2 3 5
2 8 3
2 4 7
5 6 6
6 9 4
6 8 6
7 8 9
7 10 8

1 4 1
3 6 3
1 7 2
7 9 3
6 7 5
*/