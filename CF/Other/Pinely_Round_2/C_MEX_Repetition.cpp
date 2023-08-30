#include <algorithm>
#include <array>
#include <bitset>
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
constexpr int N=1e5+10;
bitset<N> bs;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n+1);
    
    for(int i=1;i<=n;i++) cin>>arr[i],bs[arr[i]]=0;
    for(int i=1;i<=n;i++) {
        int t=bs._Find_first();
        bs[arr[i]].flip();
        bs[t].flip();
        arr[i]=t;
    }

    arr[0]=bs._Find_first();
    for(int i=1;i<=n;i++) bs[arr[i]]=1;
    debug(arr,1,n);
    k--;
    k%=(n+1);
    for(int i=1;i<=n;i++) {
        int j=(i-k+n+1)%(n+1);
        cout<<arr[j]<<" \n"[i==n];
    }
}

int main() {
    bs.set();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}