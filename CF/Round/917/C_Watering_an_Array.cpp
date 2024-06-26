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
    vector<int> arr(n+1),b(k);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int &x:b) cin>>x;
    int ans=0;
    for(int i=0,j=0;i<=min(3*n,d-1);i++,j=(j+1)%k) {
        int res=0;
        for(int l=1;l<=n;l++) res+=arr[l]==l;
        for(int l=1;l<=b[j];l++) arr[l]++;
        ans=max(ans,res+(d-i-1)/2);
    }
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