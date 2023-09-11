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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n+1);
    vector<bool> mark(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n&&k==1;i++) if(arr[i]!=i) {
        cout<<"NO"<<endl;
        return;
    }
    auto dfs=[&](int u) {
        map<int,int> mp;
        mp[u]=0;
        for(int i=1;;i++) {
            u=arr[u];
            if(mp.find(u)!=mp.end()) {
                int len=i-mp[u];
                if(len!=k) {
                    cout<<"NO"<<endl;
                    return true;
                }
                break;
            }
            if(mark[u]) break;
            mp[u]=i;
        }
        for(auto [u,d]:mp) mark[u]=1;
        return false;
    };

    for(int i=1;i<=n;i++) if(!mark[i]) if(dfs(i)) return;
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}