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
    int n,m;
    cin>>n>>m;
    vector<LL> arr(n);
    for(LL &x:arr) cin>>x;
    sort(arr.begin(),arr.end(),greater<>());
    vector<LL> vec;
    while(arr.size()>m) {
        vec.emplace_back(arr.back());
        arr.pop_back();
    }
    reverse(arr.begin(),arr.end());
    reverse(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++) arr[i]+=vec[i];
    LL ans=0;
    for(int i=0;i<m;i++) ans+=arr[i]*arr[i];
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}