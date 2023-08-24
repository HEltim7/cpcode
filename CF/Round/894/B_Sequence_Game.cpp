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
    int n;
    cin>>n;
    vector<int> arr(n+1);
    vector<int> ans;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ans.emplace_back(arr[1]);
    for(int i=2;i<=n;i++) {
        if(arr[i]<arr[i-1]) ans.emplace_back(1);
        ans.emplace_back(arr[i]);
    }
    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<' ';
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