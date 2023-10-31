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
    int n;
    cin>>n;
    vector<LL> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr.begin()+1,arr.end());
    debug(arr,1,n);
    LL ans=0,sum=0;
    int l=1,r=n;
    while(l<r) {
        LL t=min(arr[l],arr[r]-sum);
        sum+=t,ans+=t;
        arr[l]-=t;
        if(sum==arr[r]) ans++,sum=0,arr[r]=0,r--;
        if(arr[l]==0) l++;
    }
    if(l==r) {
        LL t=(arr[l]-sum)/2;
        sum+=t,ans+=t;
        if(sum) ans++;
        if(arr[l]-t-sum>0) ans++;
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