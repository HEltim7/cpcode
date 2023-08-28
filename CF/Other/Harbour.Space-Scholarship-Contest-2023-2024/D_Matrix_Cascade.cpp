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

void solve() {
    int n;
    cin>>n;
    auto grid=vector(n,string{});
    for(int i=0;i<n;i++) cin>>grid[i];
    vector<int> lef(n),rig(n);
    vector<int> dn(n);
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j+1<n;j++) lef[j]=lef[j+1];
        for(int j=n-1;j-1>=0;j--) rig[j]=rig[j-1];
        lef.back()=rig.front()=0;
        for(int j=0;j<n;j++) dn[j]^=(lef[j]&1)^(rig[j]&1);

        auto cur=dn;
        for(int j=0;j<n;j++) {
            if(grid[i][j]=='1') {
                cur[j]^=1;
            }
        }

        for(int j=0;j<n;j++) {
            if(cur[j]) {
                ans++;
                dn[j]^=1;
                lef[j]++;
                rig[j]++;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}