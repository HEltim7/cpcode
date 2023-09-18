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
    int n,k;
    cin>>n;
    vector<int> c(n+1),mn(n+1),mid(n+1),ans(n+2);
    for(int i=1;i<=n;i++) cin>>c[i];
    cin>>k;
    mn[n]=c[n],mid[n]=n;
    for(int i=n-1;i>=1;i--) {
        mn[i]=mn[i+1];
        mid[i]=mid[i+1];
        if(c[i]<mn[i+1]) {
            mn[i]=c[i];
            mid[i]=i;
        }
    }

    vector<pair<int,int>> stk;
    stk.emplace_back(mid[1],k/mn[1]);
    k-=(k/mn[1])*mn[1];
    for(int i=2;i<=n;i++) {
        int cnt=0;
        while(stk.size()&&mn[i]-mn[stk.back().first]<=k) {
            int v=mn[i]-mn[stk.back().first];
            int t=stk.back().second;
            if(v>0) t=min(k/v,t);
            cnt+=t;
            k-=v*t;
            stk.back().second-=t;
            if(stk.back().second==0) stk.pop_back();
        }
        if(cnt>0) stk.emplace_back(mid[i],cnt);
    }

    for(auto [id,cnt]:stk) {
        ans[1]+=cnt;
        ans[id+1]-=cnt;
    }
    for(int i=1;i<=n;i++) cout<<(ans[i]+=ans[i-1])<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}