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

#define endl '\n'
using LL=long long;

void solve() {
    LL n;
    cin>>n;
    vector<LL> a(n),b(n);
    for(LL &x:a) cin>>x;
    for(LL &x:b) cin>>x;

    LL suma=0,sumb=0;
    for(LL x:a) suma+=x;
    for(LL x:b) sumb+=x;

    cout<<min(suma+n**min_element(b.begin(),b.end()),sumb+n**min_element(a.begin(),a.end()))<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}