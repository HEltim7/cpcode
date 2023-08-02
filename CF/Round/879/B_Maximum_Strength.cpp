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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

void solve() {
    auto read=[&]() {
        string s;
        cin>>s;
        vector<int> res;
        for(auto x:s) res.push_back(x-'0');
        return res;
    };

    auto &&l=read();
    auto &&r=read();

    reverse(l.begin(),l.end());
    while(l.size()<r.size()) l.push_back(0);
    reverse(l.begin(),l.end());
    int n=l.size();

    int idx=-1;
    for(int i=0;i<l.size();i++) {
        if(l[i]==r[i]) continue;
        else {
            idx=i;
            break;
        }
    }
    if(idx==-1) cout<<0<<endl;
    else {
        int ans=r[idx]-l[idx];
        for(int i=idx+1;i<n;i++) ans+=9;
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}