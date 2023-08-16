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
constexpr int INF=200;

constexpr int N=1e6+10;
int cache[N];

map<LL,int> mp;
int solve(LL x) {
    if(x<=1) return 0;
    if(x<N) return cache[x];
    auto it=mp.find(x);
    if(it!=mp.end()) return it->second;
    int res=x-1>=INF?INF:x-1;
    
    if(x%2==0) res=min(res,solve(x/2)+1);
    else res=min(res,solve(x/2)+2);

    if(x%3==0) res=min(res,solve(x/3)+1);
    else if((x-1)%3==0) res=min(res,solve(x/3)+2);
    else res=min(res,solve(x/3)+3);
    return mp[x]=res;
}

int cache_up(LL x) {
    if(x<=1) return 0;
    int res=x-1;
    
    if(x%2==0) res=min(res,solve(x/2)+1);
    else res=min(res,solve(x/2)+2);

    if(x%3==0) res=min(res,solve(x/3)+1);
    else if((x-1)%3==0) res=min(res,solve(x/3)+2);
    else res=min(res,solve(x/3)+3);
    return cache[x]=res;
}

void solve() {
    LL n;
    cin>>n;
    mp.clear();
    cout<<solve(n)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<N;i++) cache_up(i);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}