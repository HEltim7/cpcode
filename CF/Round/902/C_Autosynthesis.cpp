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
    int n;
    cin>>n;
    vector<int> arr(n+1);
    vector<bool> has(n+1),vis(n+1),dir(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i],has[arr[i]]=1;

    auto dfs=[&](int i,bool d,bool keep) {
        vector<int> path;
        while(!vis[i]) {
            path.emplace_back(i);
            vis[i]=1;
            dir[i]=d;
            if(arr[i]!=i) d^=1;
            i=arr[i];
        }
        if(!keep) for(int i:path) vis[i]=dir[i]=0;
        debug(path);
        return dir[i]==d;
    };

    for(int i=1;i<=n;i++) {
        if(!has[i]) {
            if(!dfs(i,0,1)) {
                debug(i);
                cout<<-1<<endl;
                return;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            if(dfs(i,0,0)) {
                dfs(i,0,1);
            }
            else if(dfs(i,1,0)) {
                dfs(i,1,1);
            }
            else {
                cout<<-1<<endl;
                return;
            }
        }
    }

    vector<int> r;
    for(int i=1;i<=n;i++) {
        if(!dir[i]) {
            assert(dir[arr[i]]);
            r.emplace_back(arr[i]);
        }
    }

    cout<<r.size()<<endl;
    for(int x:r) cout<<x<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}