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
    LL n,l,r,L,R;
    cin>>n>>l>>r>>L>>R;
    if(r+R<n||l+L>n) cout<<0<<endl;
    else {
        LL t=n-l-L;
        LL x=min(t,r-l);
        LL l1=l+x;
        t-=x;
        LL l2=L+t;
        debug(l1,l2);
        cout<<min(l1-l+1,R-l2+1)<<endl;
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