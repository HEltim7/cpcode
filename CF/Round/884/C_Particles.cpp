#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
constexpr int N=2e5+10;
LL arr[N];

void solve() {
    int n;
    cin>>n;
    LL ans=-1e9;
    for(int i=1;i<=n;i++) cin>>arr[i],ans=max(ans,arr[i]);

    LL odd=-1e9,even=-1e9;
    for(int i=1;i<=n;i++) {
        if(i&1) {
            odd=max(odd,odd+arr[i]);
            odd=max(odd,arr[i]);
        }
        else {
            even=max(even,even+arr[i]);
            even=max(even,arr[i]);
        }
        ans=max({ans,odd,even});
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}