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
#include <functional>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;


void solve() {
    int n,k;
    LL m;
    cin>>n>>m>>k;

    k=min(n,k-1);
    if(k==n) {
        cout<<0<<endl;
        return;
    }

    vector<pair<LL,LL>> seg;
    vector<pair<LL,int>> arr(1,{-1,0});
    map<LL,int> cnt;
    for(int i=1;i<=n;i++) {
        LL in;
        cin>>in;
        cnt[in]++;
    }
    for(auto [x,y]:cnt) arr.emplace_back(x,y);
    arr.emplace_back(m+1,0);
    n=arr.size()-1;

    int tot=0;
    int r=0,l=1;
    while(r<n&&tot<k) {
        tot+=arr[++r].second;
    }

    for(LL i=-1;i<=m;) {
        function<LL(void)> get_next=[&]() -> LL {
            if(r==n) return m+1;
            tot+=arr[++r].second;
            LL x=arr[l].first;
            LL y=arr[r].first;
            if((y-x)%2==0) return (x+y)/2;
            while(r<n&&tot-arr[l].second<=k) {
                tot+=arr[++r].second;
            }
            tot-=arr[l++].second;
            if(tot<=k) return m+1;
            return (arr[r].first+x+1)/2;
        };

        bool flag=tot==k;
        LL ne=get_next();
        debug(i,ne);
        if(!flag) seg.emplace_back(i+1,ne-2);
        i=ne;
    }
    debug(seg);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}