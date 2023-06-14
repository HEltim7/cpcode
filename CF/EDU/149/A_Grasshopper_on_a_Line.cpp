#include <algorithm>
#include <array>
#include <cassert>
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
    LL x,k;
    cin>>x>>k;
    if(x%k) {
        cout<<1<<endl;
        cout<<x<<endl;
    }
    else {
        cout<<2<<endl;
        cout<<x-1<<' '<<1<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}