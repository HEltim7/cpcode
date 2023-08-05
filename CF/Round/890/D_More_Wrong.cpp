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

using LL=long long;

void solve() {
    int n;
    cin>>n;

    LL tot=n*n*5;
    auto ask=[&](int l,int r) {
        if(l==r) return 0;
        LL cur=1LL*(r-l)*(r-l);
        tot-=cur;
        assert(tot>=0);
        cout<<"? "<<l<<' '<<r<<endl;
        int in;
        cin>>in;
        return in;
    };

    function<int(int,int)> sol=[&](int l,int r) {
        if(l==r) return l;
        int mid=(l+r)/2;
        int x=sol(l,mid);
        int y=sol(mid+1,r);
        if(ask(x,y)==ask(x,y-1)) return y;
        else return x;
    };

    int ans=sol(1,n);
    cout<<"! "<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}