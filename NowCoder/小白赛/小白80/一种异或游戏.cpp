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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> cnta(1<<21),cntb(1<<21);
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i],cnta[a[i]]++;
    for(int i=1;i<=m;i++) cin>>b[i],cntb[b[i]]++;
    int suma=0,sumb=0;
    for(int i=1;i<=n;i++) if(cntb[k^a[i]]==0) suma++;
    for(int i=0;i<cntb.size();i++) {
        if(cntb[i]) {
            if(cnta[k^i]) sumb+=cnta[k^i]-1;
            else sumb+=cntb[i];
        }
    }
    debug(suma,sumb);

    if(sumb>=m) cout<<"Alice"<<endl;
    else if(suma+1>=n) cout<<"Alice"<<endl;
    else if(suma>sumb) cout<<"Alice"<<endl;
    else if(sumb+1>=m) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}