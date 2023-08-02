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
constexpr int N=2e5+10;
int a[N],b[N];

void solve() {
    int n;
    cin>>n;
    
    LL ans=0;
    multiset<int,greater<>> pos;
    multiset<int> neg;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
        ans+=min(a[i],b[i]);
        if(a[i]>b[i]) pos.insert(a[i]-b[i]);
        else neg.insert(b[i]-a[i]);
    }
    debug(pos,neg);

    while(pos.size()||neg.size()) {
        if(pos.size()) {
            int x=*pos.begin();
            neg.insert(x);
            pos.erase(pos.begin());
        }
        else {
            int x=*neg.begin();
            pos.insert(x);
            neg.erase(neg.begin());
        }
        debug(pos,neg);

        if(pos.size()) {
            ans+=*pos.begin();
            pos.erase(pos.begin());
        }
        else {
            neg.erase(neg.begin());
        }
        debug(pos,neg,ans);
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}