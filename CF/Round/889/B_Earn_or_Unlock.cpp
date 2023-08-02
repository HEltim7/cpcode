#include <algorithm>
#include <array>
#include <bitset>
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
using BS=bitset<N>;

void solve() {
    int n;
    cin>>n;
    vector<LL> arr(N),pre(N);
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(arr[1]==0) {
        cout<<0<<endl;
        return;
    }

    BS bs,mask;
    mask.set();
    constexpr int bgn=N-5;
    bs[bgn]=1;
    for(int l=bgn;l>=0&&l>=bs._Find_first();l--) {
        int cur=arr[bgn-l+1];
        if(cur!=0) bs|=(bs&mask)>>cur;
        mask[l]=0;
    }

    LL ans=0;
    partial_sum(arr.begin(),arr.end(),pre.begin());
    for(int i=bgn;i>=0;i--) {
        if(bs[i]) {
            int idx=bgn-i+1;
            debug(idx,pre[idx]);
            ans=max(ans,pre[idx]-(idx-1));
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}