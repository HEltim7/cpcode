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
    string s;
    cin>>s;
    
    vector<int> v;
    char pre=' ';
    int len=0;
    for(auto x:s) {
        if(x!=pre) {
            if(len) v.push_back(len);
            pre=x;
            len=1;
        }
        else len++;
    }
    if(len) v.push_back(len);

    sort(v.begin(),v.end(),greater<>());
    LL k=0,tot=0,ans=0;
    for(int x:v) {
        k++;
        tot+=x;
        ans=max(ans,tot-k);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}