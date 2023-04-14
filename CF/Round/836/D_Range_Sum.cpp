#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    if(n&1) {
        int t=n+1;
        vector<int> arr;
        for(int l=t-n/2,r=t+n/2;l<=r;l++) arr.push_back(l);
        arr.front()--,arr.back()++;
        for(auto &x:arr) x++;
        arr[n-2]++;
        for(int i=0;i<n;i++) cout<<arr[i]<<" \n"[i==n-1];
    }
    else for(int l=n-n/2,r=n+n/2;l<=r;l++) if(l!=n) cout<<l<<" \n"[l==r];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}