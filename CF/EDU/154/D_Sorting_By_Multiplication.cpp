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
    vector<int> arr(n+1),suf(n+2);
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    for(int i=n-1;i>=1;i--) {
        suf[i]=suf[i+1];
        if(arr[i+1]<=arr[i]) suf[i]++;
    }
    int ans=suf[1];
    arr[0]=int(2e9);
    for(int i=1,pre=0;i<=n;i++) {
        if(arr[i]>=arr[i-1]) pre++;
        ans=min(ans,pre+1+suf[i+1]);
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