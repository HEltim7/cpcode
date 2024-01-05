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
    int n,k,d;
    cin>>n>>k>>d;
    vector<int> arr(n+1),v(k+1);
    int ans=0;
    for(int i=1;i<=n;i++) cin>>arr[i],ans+=arr[i]==i;
    for(int i=1;i<=k;i++) cin>>v[i];
    
    vector<int> vec,cnt(n+1);
    for(int i=1,j=1;i<=min(3*n,d);i++) {
        vec.emplace_back(v[j]);
        if(++j>n) j=1;
    }


    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}