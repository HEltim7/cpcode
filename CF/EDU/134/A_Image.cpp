#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
int cnt[1<<7];
int v[5];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

void solve() {
    memset(cnt, 0, sizeof(cnt));
    memset(v, 0, sizeof(v));
    for(int i=0;i<4;i++) {
        char in;
        cin>>in;
        v[cnt[in]]--;
        cnt[in]++;
        v[cnt[in]]++;
    }
    debug(v,1,4);
    if(v[4]) cout<<0<<endl;
    else if(v[3]||v[2]==2) cout<<1<<endl;
    else if(v[2]==1) cout<<2<<endl;
    else cout<<3<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}