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
int arr[N];

void solve() {
    int n,m;
    cin>>n>>m;
    int l,r;
    cin>>l>>r;
    n-=2;

    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    
    int lidx=lower_bound(arr+1,arr+1+n,l)-arr;
    int ridx=upper_bound(arr+1,arr+1+n,r)-arr-1;

    int ans=2e9;
    for(int i=lidx;i>=1;i--) {
        int idx=i+m-1;
        if(idx>n) continue;
        ans=min(ans,max(0,l-arr[i])+max(0,arr[idx]-r));
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}