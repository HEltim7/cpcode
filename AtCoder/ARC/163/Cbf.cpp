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
    for(T i=1;i*i<=x;i++) {
        if(x%i==0) {
            res.push_back(i);
            if(x/i!=i) res.push_back(x/i);
        }
    }
    return res;
}

void solve() {
    LL x=1,y=1,z=1,lim=1e9;
    int cnt=0;
    for(int i=1;i<=30;i++) {
        x*=2;
        if(x>lim) break;
        for(int j=1;j<=30;j++) {
            y*=3;
            if(x*y>lim) break;
            for(int k=1;k<=30;k++) {
                z*=5;
                if(x*y*z>lim) break;
                debug(x,y,z);
                cnt++;
            }
            z=1;
        }
        y=1;
    }
    debug(cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}