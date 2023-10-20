#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
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

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,double>>> adj(n+1);
    vector<tuple<int,int,int,int>> edg(m);
    for(auto &[u,v,a,b]:edg) cin>>u>>v>>a>>b;
    
    auto check=[&](double m) {
        for(int i=1;i<=n;i++) adj[i].clear();
        vector<double> dis(n+1,-1e18);
        vector<int> ind(n+1);
        for(auto [u,v,a,b]:edg) {
            double w=a-m*b;
            adj[u].emplace_back(v,w);
            ind[v]++;
        }

        queue<int> q;
        q.emplace(1);
        dis[1]=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            for(auto [v,d]:adj[u]) {
                dis[v]=max(dis[v],dis[u]+d);
                if(--ind[v]==0) q.emplace(v);
            }
        }
        return dis[n]>=0;
    };

    constexpr double eps=1e-12;
    double l=0,r=1e4;
    while(r-l>eps) {
        double m=(l+r)/2;
        if(check(m)) l=m;
        else r=m;
    }
    cout<<fixed<<setprecision(20)<<(l+r)/2<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}