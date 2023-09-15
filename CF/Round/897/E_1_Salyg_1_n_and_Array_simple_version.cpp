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
    int n,k;
    cin>>n>>k;
    auto ask=[&](int idx) {
        cout<<"? "<<idx<<endl;
        int in;
        cin>>in;
        return in;
    };

    int xsum=0;
    auto fin=[&](int ans)  {
        cout<<"! "<<(ans)<<endl;
    };

    for(int i=1;i+k-1<=n;i+=k) {
        xsum^=ask(i);
    }

    if(n%k) {
        int t=n%k/2;
        xsum^=ask(n-t-k+1);
        xsum^=ask(n-k+1);
    }
    fin(xsum);
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}