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
constexpr LL M=1e18;

void solve() {
    LL n,k;
    cin>>n>>k;
    vector<LL> base{1,2};
    for(LL i=1;base.back()<=M;i*=2) base.push_back(base.back()+i);

    auto it=--upper_bound(base.begin(),base.end(),n);
    LL r=*it;
    LL l=*--it+1;

    auto get=[](LL sz,LL idx) {
        if(idx==1||idx+1==sz) return idx+1;
        return idx&1?idx-2:idx+2;
    };

    if(l==r) {
        cout<<get(l,k)<<endl;
        return;
    }

    r--;
    LL layer=1,len=(l+r)/2,sz=*--it;

    while(l<r) {
        LL mid=l+r>>1;
        if(mid==n) {
            LL gap=0;
            if(layer>1) gap=(len-layer*sz)/(layer-1);
            LL idx=k/(sz+gap)*(sz+gap);

        }
        if(mid<=n) {
            r=mid;
        }
        else l=mid;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}