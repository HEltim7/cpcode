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
constexpr int N=2e5+10;
constexpr LL INF=1LL*N*N;
int arr[N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector<pair<LL,LL>> seg;
    for(int i=1;i<=n;i++) {
        if(seg.empty()) seg.emplace_back(arr[i],arr[i]);
        else if(arr[i]==seg.back().second+1) seg.back().second=arr[i];
        else seg.emplace_back(arr[i],arr[i]);
    }

    auto check=[&](LL mid) {
        LL res=0;
        for(auto [l,r]:seg) {
            LL len=r-l+1;
            LL t=min(mid/r,k*1LL);
            res+=t*len;

            // if(mid/r<k) res+=max(0LL,(mid-1)%r+1-l+1);
            debug(l,r,t,res);
        }
        return res>=mid;
    };

    check(9);

    // LL l=1,r=INF;
    // while(l<r) {
    //     LL mid=(l+r+1)/2;
    //     if(check(mid)) l=mid;
    //     else r=mid-1;
    // }
    // cout<<l+1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}