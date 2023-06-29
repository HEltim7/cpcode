#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
    int xa,ya;
    int xb,yb;
    int xc,yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;

    int xab=xb-xa;
    int yab=yb-ya;
    int xac=xc-xa;
    int yac=yc-ya;

    int ans=max({0,min(xab,xac),min(-xab,-xac)});
    ans+=max({0,min(yab,yac),min(-yab,-yac)});
    cout<<ans+1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}