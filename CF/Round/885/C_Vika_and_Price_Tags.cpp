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
constexpr int N=1e5+10;
int arr[N],brr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>brr[i];
    if(n==1) {
        cout<<"YES"<<endl;
        return;
    }

    auto work=[&]() {
        for(int i=1;i<=n;i++) {
            int c=abs(arr[i]-brr[i]);
            arr[i]=brr[i],brr[i]=c;
        }
    };

    auto same=[&]() {
        for(int i=1;i<=n;i++) {
            if(brr[i]) return false;
        }
        return true;
    };

    for(int i=1;i<=100;i++) {
        if(same()) {
            debug(arr,1,n);
            debug(brr,1,n);
            cout<<"YES"<<endl;
            return;
        }
        work();
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}