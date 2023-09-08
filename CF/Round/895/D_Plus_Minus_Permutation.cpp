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

#define endl '\n'
using LL=long long;

void solve() {
    LL n,x,y;
    cin>>n>>x>>y;
    LL add=n/x-n/lcm(x,y);
    LL sub=n/y-n/lcm(x,y);
    auto get=[&](LL l,LL r) {
        return (l+r)*(r-l+1)/2;
    };
    cout<<get(n-add+1,n)-get(1,sub)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}