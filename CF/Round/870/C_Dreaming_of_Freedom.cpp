#include <algorithm>
#include <array>
#include <cassert>
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

template<typename T> vector<T> get_prime_factor(T x) {
    vector<T> res;
    for(T i=2;i*i<=x;i++) {
        if(x%i==0) {
            while(x%i==0) x/=i;
            res.push_back(i);
        }
    }
    if(x>1) res.push_back(x);
    return res;
}

template<typename T> vector<T> get_factor(T x) {
    vector<T> res;
    for(T i=2;i*i<=x;i++) {
        if(x%i==0) {
            res.push_back(i);
            if(x/i!=i) res.push_back(x/i);
        }
    }
    return res;
}

void solve() {
    int n,m;
    cin>>n>>m;
    if(n==1) {
        cout<<"YES"<<endl;
        return;
    }

    if(n<=m) {
        cout<<"NO"<<endl;
        return;
    }

    auto &&v=get_factor(n);
    if(v.empty()) {
        cout<<"YES"<<endl;
        return;
    }
    int minn=v.front();
    if(minn<=m) {
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}