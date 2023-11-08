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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<vector<int>> adj(n),add(n);
    
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        arr[i]--;
        int t=(i-arr[i]+n)%n;
        if(arr[i]<n) add[t].emplace_back(arr[i]);
    }
    
    for(int i=0;i<n;i++) {
        for(int x:add[i]) {
            int t=(i+x+1)%n;
            adj[t].emplace_back(i);
        }
    }

    vector<bool> mark(n);
    function<int(int)> dfs=[&](int u) -> int {
        if(mark[u]) return k;
        mark[u]=1;
        int res=0;
        for(int v:adj[u]) {
            res=max(res,dfs(v)+1);
        }
        mark[u]=0;
        return res;
    };

    if(dfs(0)>=k) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}