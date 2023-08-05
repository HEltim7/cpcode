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
    vector<LL> arr(n+1);
    LL sub=0,more=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(n==1) {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=1;i<=n;i++) {
        if(arr[i]>1) sub+=arr[i]-1;
        else more++;
    }
    debug(sub,more);
    cout<<((sub>=more)?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}