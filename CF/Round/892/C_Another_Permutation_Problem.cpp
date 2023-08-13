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
    vector<int> arr(n+1);
    iota(arr.begin(), arr.end(), 0);
    
    LL ans=0;
    for(int i=1;i<=n;i++) {
        auto cur=arr;
        reverse(cur.begin()+i,cur.end());
        LL res=0,maxx=0;
        for(int j=1;j<=n;j++) {
            res+=1LL*cur[j]*j;
            maxx=max(maxx,1LL*cur[j]*j);
        }
        res-=maxx;
        ans=max(ans,res);
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