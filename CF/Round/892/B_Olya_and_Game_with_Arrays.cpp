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

    LL ans=0;
    vector<pair<LL,LL>> vec;
    for(int i=1;i<=n;i++) {
        int m;
        cin>>m;
        vector<LL> arr(m);
        for(LL &x:arr) cin>>x;
        sort(arr.begin(),arr.end());
        vec.emplace_back(arr[1],arr[0]);
    }
    sort(vec.begin(),vec.end());

    LL minn=1e9;
    for(auto [x,y]:vec) ans+=x,minn=min(minn,y);
    ans-=vec[0].first;
    ans+=minn;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}