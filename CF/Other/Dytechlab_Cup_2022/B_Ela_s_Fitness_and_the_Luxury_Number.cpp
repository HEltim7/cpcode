#include <cmath>
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
using LD=long double;

void solve() {
    LL l,r;
    cin>>l>>r;

    auto get1=[](LL x) {
        LL lx=sqrt(LD(x));
        debug(lx);
        LL lx2=lx*lx;
        return (x-lx2)/lx+1;
    };

    auto get2=[](LL x) {
        LL lx=sqrt(LD(x));
        debug(lx);
        LL lx2=lx*lx;
        return (x-lx2+lx-1)/lx+1;
    };
//999999999
//999999998000000001
    LL lx=sqrt(LD(l));
    LL rx=sqrt(LD(r));

    if(lx==rx) {
        LL ans=get1(r)-get2(l)+1;
        cout<<ans<<endl;
        return;
    }

    LL ans=max(0LL,(rx-lx-1)*3);
    debug(lx,rx,ans);
    debug(get1(r),get2(l));
    ans+=get1(r)+4-get2(l);
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