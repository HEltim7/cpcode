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
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    LL res=3e9;
    for(int i=0,j=1,k=2;k<arr.size();i++,j++,k++) {
        res=min(res,arr[k]-arr[j]+arr[j]-arr[i]);
    }
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}