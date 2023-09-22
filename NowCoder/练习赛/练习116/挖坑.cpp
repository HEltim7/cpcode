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
    LL n,k;
    cin>>n>>k;
    LL step=3+n-2;
    k-=step;
    if(k<0||(k&1)) {
        cout<<-1<<endl;
        return;
    }
    LL cnt=k/4;
    LL len=cnt*4+1;
    LL tot=cnt*4;
    if(k%4) {
        len+=4;
        tot+=3;
    }
    if(len>n) cout<<-1<<endl;
    else cout<<tot<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}