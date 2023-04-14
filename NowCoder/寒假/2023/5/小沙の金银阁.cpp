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

void solve() {
    LL n,m;
    cin>>n>>m;
    // if(floor(log2((long double)m))+1<n) cout<<"-1";

    auto check=[&](LL pre,LL r) {
        while(r<n&&pre<=m) pre*=2,r++;
        return r==n&&pre<=m;
    };

    if(!check(1,1)) cout<<"-1";
    else {
        LL pre=0;
        for(int i=1;i<=n;i++) {
            LL l=pre,r=m-pre;
            while(l<r) {
                LL mid=l+r+1>>1;
                if(check(pre+mid,i)) l=mid;
                else r=mid-1;
            }
            pre+=l;
            cout<<l<<' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}