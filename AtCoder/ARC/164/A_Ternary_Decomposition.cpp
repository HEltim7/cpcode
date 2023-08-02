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
    LL n,k;
    cin>>n>>k;
    vector<int> v;
    LL tot=0;
    LL t=n;
    while(t) {
        v.push_back(t%3);
        t/=3;
        tot+=v.back();
    }

    debug(v);
    debug(tot,k);
    if(tot>k||k>n||(tot%2!=k%2)) {
        cout<<"No"<<endl;
        return;
    }

    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}