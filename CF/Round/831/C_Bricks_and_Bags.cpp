#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<LL> arr(n);
    for(auto &x:arr) cin>>x;
    sort(arr.begin(),arr.end());
    
    LL ans=arr.back()-arr.front();
    for(int i=2;i<arr.size();i++) {
        ans=max(ans,arr[i]-arr[i-1]+arr[i]-arr.front());
        ans=max(ans,arr.back()-arr[i-2]+arr[i-1]-arr[i-2]);
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