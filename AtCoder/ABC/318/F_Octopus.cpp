#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
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
constexpr LL N=3e18;

void solve() {
    int n;
    cin>>n;
    vector<LL> arr(n+2),len(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>len[i];
    arr[0]=-N,arr[n+1]=N;
    LL ans=0;
    for(LL i=-N,h=0;i<=N;) {
        vector<LL> dis;
        for(int j=1;j<=n;j++) dis.emplace_back(abs(i-arr[j]));
        sort(dis.begin(),dis.end());
        bool valid=true;
        LL min_len=arr[h+1]-i+1;
        for(int j=0;j<n;j++) {
            valid&=len[j+1]>=dis[j];
            min_len=min(min_len,abs(len[j+1]-dis[j]));
        }
        min_len=max(1LL,min_len);

        debug(i,valid,min_len,dis);
        if(valid) ans+=min_len;
        i+=min_len;
        if(i>=arr[h+1]) h++;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}