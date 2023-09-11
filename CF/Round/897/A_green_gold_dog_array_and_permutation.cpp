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
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        v.emplace_back(in,i);
    }
    sort(v.begin(),v.end(),greater<>());
    vector<int> ans(n+1);
    for(int i=1;i<=n;i++) ans[v[i-1].second]=i;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}