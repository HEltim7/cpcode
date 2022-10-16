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
using PLL=pair<LL,LL>;
constexpr int N=2e5+10;
vector<int> adj[N];
LL s[N];

PLL dfs(int u,LL k) {
    if(adj[u].empty()) return {k*s[u],s[u]};
    LL p=k/adj[u].size();
    LL q=k-p*adj[u].size();
    debug(u,k,p,q);
    vector<LL> arr;
    LL a=s[u]*k;
    for(int v:adj[u]) {
        auto [x,y]=dfs(v,p);
        debug(v,x,y);
        a+=x;
        arr.push_back(y);
    }
    sort(arr.begin(),arr.end(),greater<LL>());
    for(int i=0;i<q;i++) a+=arr[i];
    return {a,arr[q]+s[u]};
}

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        adj[i].clear();
    }
    for(int i=2;i<=n;i++) {
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>s[i];
    cout<<dfs(1, k).first<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}