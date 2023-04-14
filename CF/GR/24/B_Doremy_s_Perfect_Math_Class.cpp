#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    int maxx=0;
    for(int i=0;i<n;i++) cin>>arr[i],maxx=max(maxx,arr[i]);
    int g=arr[0];
    for(int i=1;i<n;i++) g=gcd(g,arr[i]);
    cout<<maxx/g<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}