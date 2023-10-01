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
    vector<int> res(n),arr(n);
    for(int &x:res) cin>>x;
    iota(arr.begin(),arr.end(),1);
    int cnt=0;
    do {
        auto t=arr;
        for(int i=m-1;i<=n-1;i++)
            sort(t.begin()+i-m+1,t.begin()+i+1);
        if(t==res) debug(arr),cnt++;
    }while (next_permutation(arr.begin(),arr.end()));
    debug(cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}