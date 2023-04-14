#include <vector>
#include <iostream>
#include <algorithm>
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
    LL n;
    cin>>n;
    
    LL ans=1e18;
    LL l=1,r=1e9;
    while(l<r) {
        LL mid=l+r>>1;
        if(mid*mid*4>=n) r=mid;
        else l=mid+1;
    }
    ans=min(ans,l*2-1);

    l=1,r=1e9;
    while(l<r) {
        LL mid=l+r>>1;
        LL x=2*mid-1;
        if(x*x>=n) r=mid;
        else l=mid+1;
    }
    ans=min(ans,l*2-2);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}