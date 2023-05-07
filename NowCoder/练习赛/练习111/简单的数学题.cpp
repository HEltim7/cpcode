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

#define endl '\n'
using LL=long long;
using LLL=__int128;
constexpr LL INF=1e18;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

void solve() {
    LL m,x;
    cin>>m>>x;
    LL k=m/x;

    auto findl=[&]() {
        LLL l=1,r=INF;
        while(l<r) {
            LLL mid=l+r+1>>1;
            if(k*mid<=m) l=mid;
            else r=mid-1;
        }
        return l;
    };

    auto findr=[&]() {
        LLL l=1,r=INF;
        while(l<r) {
            LLL mid=l+r>>1;
            if((k+1)*mid>m) r=mid;
            else l=mid+1;
        }
        return l;
    };

    cout<<LL(findl()-findr()+1)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}