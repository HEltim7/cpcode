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
    LL n;
    cin>>n;
    if(n==1) cout<<1<<endl;
    else if(n==2) cout<<-1<<endl;
    else {
        LL len=(n+1)/2;
        LL l=len,r=n;
        while(l<r) {
            LL mid=l+r+1>>1;
            if(len+(mid-len)*3>n) r=mid-1;
            else l=mid;
        }
        cout<<l<<endl;
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