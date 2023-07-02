#include <array>
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <testlib.h>
#include <chrono>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int files=1;

void solve() {
    int lim=100;
    for(int n=7;n<=18;n++) {
        for(;;) {
            vector<int> arr(n);
            for(int i=0;i<n;i++) arr[i]=rnd.next(2,lim);
            sort(arr.begin(),arr.end());
            if(unique(arr.begin(),arr.end())!=arr.end()) continue;

            LL mul=1,sum=0;
            for(int i=0;i<n;i++) mul*=arr[i];
            for(int i=0;i<n;i++) sum+=mul/arr[i];
            if(sum==mul) {
                debug(n,arr);
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    registerGen(argc, argv, 1);
    rnd.setSeed(chrono::system_clock().now().time_since_epoch().count());
    solve();
    return 0;
}