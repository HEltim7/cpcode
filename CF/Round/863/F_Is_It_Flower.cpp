#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
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
vector<int> adj[N];
bool mark[N];
int ind[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) adj[i].clear(),mark[i]=0,ind[i]=0;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        ind[u]++,ind[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // k -> k+k*(k-1) -> k^2
    int k=floor(sqrt(1LL*n));
    if(k*k<n) {
        cout<<"NO"<<endl;
        return;
    }
    
    auto bfs=[&](int u,int aim) {
        queue<int> q;
        q.push(u);
        int res=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            res++;
            for(int v:adj[u]) {

            }
        }
    };
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}