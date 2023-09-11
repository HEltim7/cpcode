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
    string s;
    cin>>s;
    int dif=0,sam=0,odd=n&1;
    for(int i=0,j=n-1;i<j;i++,j--) {
        if(s[i]!=s[j]) dif++;
        else sam+=2;
    }
    debug(dif);

    for(int i=0;i<=n;i++) {
        if(i<dif) cout<<0;
        else if(i>dif+sam+odd) cout<<0;
        else {
            if((i-dif)%2==1&&!odd) cout<<0;
            else cout<<1;
        }
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}