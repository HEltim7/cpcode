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
    int n,m;
    cin>>n>>m;
    vector<LL> arr(n+1),k(n+1),c(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>k[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    partial_sum(arr.begin(),arr.end(),arr.begin());
    debug(arr,1,n);

    int maxb=0;
    vector<int> R(n+1);
    for(int i=1;i<=n;i++) {
        int l=i-1,r=n;
        while(l<r) {
            int mid=(l+r+1)/2;
            if(arr[mid]-arr[i-1]<=k[i]*c[i]) l=mid;
            else r=mid-1;
        }
        R[i]=l;
        maxb=max(maxb,l-i+1);
    }
    debug(R,1,n);
    debug(maxb);

    auto check=[&](int b) {
        LL cnt=m;
        for(int i=1;i<=n;i++) {
            if(R[i]-i+1>=b) continue;
            int r=b+i-1;
            if(r>n) return false;
            LL sum=arr[r]-arr[i-1];
            LL aimc=(sum+k[i]-1)/k[i];
            cnt-=aimc-c[i];
            if(cnt<0) return false;
        }
        return true;
    };

    int l=0,r=maxb;
    while(l<r) {
        int b=(l+r+1)/2;
        if(check(b)) l=b;
        else r=b-1;
    }
    cout<<maxb-l<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}