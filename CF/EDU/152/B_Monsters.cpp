#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
    vector<pair<LL,int>> arr;
    for(int i=1;i<=n;i++) {
        LL a;
        cin>>a;
        LL left=a-a/k*k;
        if(left==0) left=k;
        arr.emplace_back(-left,i);
    }
    sort(arr.begin(),arr.end());
    debug(arr);
    for(auto [_,y]:arr) cout<<y<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}