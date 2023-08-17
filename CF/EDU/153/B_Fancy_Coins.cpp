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
    LL m,k,a1,ak;
    cin>>m>>k>>a1>>ak;
    LL t=min(ak,m/k);
    m-=t*k;
    t=min(a1,m);
    m-=t;

    LL ans=m/k;
    m%=k;
    if(m) {
        if(m+a1>=k) ans++;
        else ans+=m;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}