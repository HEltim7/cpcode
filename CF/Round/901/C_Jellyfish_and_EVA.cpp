#include <algorithm>
#include <array>
#include <cassert>
#include <csetjmp>
#include <cstring>
#include <functional>
#include <iostream>
#include <iomanip>
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
using DB=double;
constexpr int N=5e3+10;
DB p[N][N];

void init() {
    p[1][1]=1;
    p[2][1]=0.5;
    for(int i=3;i<N;i++) {
        p[i][1]=DB(1)/i;
        for(int j=2;j<=i;j++) {
            DB pre=DB(j-2)/i;
            DB suf=DB(i-j)/i;
            p[i][j]=pre*p[i-2][j-2];
            if(j<i) p[i][j]+=suf*p[i-2][j-1];
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    auto adj=vector(n+1,vector<int>());
    auto res=vector(n+1,vector<DB>());
    vector<int> ind(n+1);
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[v].emplace_back(u);
        ind[u]++;
    }

    vector<DB> ans(n+1);
    ans[n]=1;
    queue<int> q;
    for(int i=1;i<=n;i++) if(!ind[i]) q.emplace(i);

    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:adj[u]) {
            res[v].emplace_back(ans[u]);
            if(--ind[v]==0) {
                sort(res[v].begin(),res[v].end(),greater<>());
                int cnt=res[v].size();
                for(int i=1;i<=cnt;i++) {
                    ans[v]+=res[v][i-1]*p[cnt][i];
                }
                q.emplace(v);
            }
        }
    }

    cout<<fixed<<setprecision(12);
    cout<<ans[1]<<endl;
}

int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}