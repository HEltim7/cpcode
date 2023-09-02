#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
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
    LL d,p;
    cin>>n>>d>>p;
    vector<LL> arr(n+1);
    LL ans=numeric_limits<LL>::max();
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr.begin()+1,arr.end(),greater<>());
    partial_sum(arr.begin(),arr.end(),arr.begin());
    LL sum=arr.back();
    for(int i=0;i<=n;i+=d) {
        ans=min(ans,i/d*p+sum-arr[i]);
    }
    ans=min(ans,(n+d-1)/d*p);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}