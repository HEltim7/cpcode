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
    map<int,int> mp;
    vector<int> arr(n);
    for(int &x:arr) cin>>x;
    LL sum=accumulate(arr.begin(),arr.end(),0LL);
    if(sum%n) {
        cout<<"No"<<endl;
        return;
    }

    int avg=sum/n;
    for(int x:arr) mp[x-avg]++;
    debug(avg);
    debug(mp);
    for(auto [x,y]:mp) {
        auto it=mp.find(-x);
        if(it==mp.end()||it->second!=y) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}