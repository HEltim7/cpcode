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
    int x;
    cin>>x;
    vector<int> res;
    while(x>1) {
        res.emplace_back(x);
        int t=x,cnt=0;
        while(t%2==0) cnt++,t/=2;
        int pw=x/t;
        if(pw<x) x-=pw;
        else x-=pw/2;
    }
    res.emplace_back(1);
    cout<<res.size()<<endl;
    for(int x:res) cout<<x<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}