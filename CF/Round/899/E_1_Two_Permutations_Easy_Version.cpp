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
constexpr int N=2.5e3+10;

vector<int> rot(vector<int> &a,int x) {
    vector<int> res;
    res.reserve(a.size());
    for(int i=x+1;i<a.size();i++) res.emplace_back(a[i]);
    res.emplace_back(a[x]);
    for(int i=0;i<x;i++) res.emplace_back(a[i]);
    return res;
}

void solve() {
    int n,m;
    cin>>n>>m;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}