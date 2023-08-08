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
constexpr int H=30;

void solve() {
    int n,k;
    cin>>n>>k;
    int cur=0,mask=0,init=0;
    vector<int> b(n+1);
    for(int i=1;i<n;i++) cin>>b[i];
    for(int i=1;i<n;i++) {
        if(!b[i]) continue;
        int h=__lg(b[i]);
        debug(h);
        if((mask>>h&1)&&(cur>>h&1)) {
            cout<<"-1"<<endl;
            return;
        }
        if(mask>>h&1^1) {
            int x=cur>>h&1;
            init|=x<<h;
            mask|=1<<h;
            if(cur>>h&1) cur^=1<<h;
        }
        cur^=b[i];
        debug(i,mask,cur);
    }

    k--;
    int ans=init;
    int cnt=__builtin_popcount(mask);
    for(int i=H-1;i>=0;i--) {
        if(mask>>i&1) cnt--;
        else {
            int t=i-cnt;
            if(1<<t<=k) {
                ans|=1<<i;
                k-=1<<t;
            }
        }
    }

    if(k) cout<<"-1"<<endl;
    else for(int i=0;i<n;i++) cout<<(ans^=b[i])<<" \n"[i==n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}