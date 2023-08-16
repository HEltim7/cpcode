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

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> adj;
    for(int i=1;i<=k;i++) {
        int u,v;
        cin>>u>>v;
        if(u==m) adj.emplace_back(v);
        else if(v==m) adj.emplace_back(u);
    }

    vector<int> x(m+1),cnt(3);
    auto arr=vector(n+1,vector(m+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<m;i++) cin>>x[i];

    for(int i=1;i<=n;i++) {
        bool ok=true;
        for(int j:adj) {
            if(arr[i][j]!=x[j]) {
                ok=false;
                break;
            }
        }
        if(ok) cnt[arr[i][m]]++;
    }

    cout<<max_element(cnt.begin(),cnt.end())-cnt.begin()<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}