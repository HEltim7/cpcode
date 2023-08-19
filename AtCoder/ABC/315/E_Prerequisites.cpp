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

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    auto adj=vector(n+1,vector<int>());
    auto rad=vector(n+1,vector<int>());
    auto mark=vector(n+1,false);
    auto ind=vector(n+1,0);
    for(int i=1;i<=n;i++) {
        int c;
        cin>>c;
        while(c--) {
            int in;
            cin>>in;
            adj[i].emplace_back(in);
            rad[in].emplace_back(i);
        }
    }

    mark[1]=1;
    queue<int> q;
    q.emplace(1);

    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:adj[u]) {
            if(!mark[v]) {
                mark[v]=1;
                q.emplace(v);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        if(mark[i]) {
            for(int v:rad[i]) {
                if(mark[v]) ind[v]++;
            }
        }
    }

    for(int i=1;i<=n;i++) if(mark[i]&&!ind[i]) q.emplace(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        if(u>1) cout<<u<<' ';
        for(int v:rad[u]) {
            if(--ind[v]==0) q.emplace(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}