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
    LL l=2,r=LL(2e9);
    while(l<r) {
        LL mid=(l+r+1)/2;
        if(mid*(mid-1)/2>n) r=mid-1;
        else l=mid;
    }
    cout<<l+n-(l*(l-1)/2)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}