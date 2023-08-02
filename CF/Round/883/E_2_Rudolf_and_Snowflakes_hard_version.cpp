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
constexpr LL INF=1e18;
set<LL> st;

void solve() {
    LL in;
    cin>>in;
    if(st.find(in)!=st.end()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    for(int k=2;k<=4;k++) {
        LL sum=1+k,cur=k;
        for(int i=1;;i++) {
            cur*=k;
            sum+=cur;
            if(sum>INF) break;
            st.insert(sum);
        }
    }
    debug(st);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}