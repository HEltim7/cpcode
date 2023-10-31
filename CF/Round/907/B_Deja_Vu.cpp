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
    int n,q;
    cin>>n>>q;
    constexpr int H=30;
    vector<int> arr(n+1);
    vector<set<int>> pos(H+1);
    auto lowbit=[&](int x) {
        return __lg(x&(-x));
    };
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        int b=lowbit(arr[i]);
        pos[b].emplace(i);
    }

    while(q--) {
        int x;
        cin>>x;
        for(int i=x;i<=H;i++) {
            for(int p:pos[i]) {
                arr[p]|=1<<(x-1);
            }
            pos[x-1].merge(pos[i]);
        }
    }
    for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}