#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
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
constexpr int N=110,M=1e6+10;
using BS=bitset<M>;

void solve() {
    int n,w,f;
    cin>>w>>f>>n;
    int sum=0;
    vector<int> arr(n);
    for(int &x:arr) cin>>x,sum+=x;
    BS dp;
    dp[0]=1;
    for(int x:arr) dp|=dp<<x;

    LL ans=numeric_limits<LL>::max();
    for(int i=0;i<M;i=dp._Find_next(i)) {
        int j=sum-i;
        LL t=max((i+w-1)/w,(j+f-1)/f);
        ans=min(ans,t);
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