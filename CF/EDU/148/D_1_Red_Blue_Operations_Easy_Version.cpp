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

constexpr int N=1e3+10;
int arr[N];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);

    while(q--) {
        int k;
        cin>>k;
        if(k&1) {
            
        }
        for(int i=1;i<=n;i++) {
            
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}
