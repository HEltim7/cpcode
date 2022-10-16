#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int l=1,r=n;
    while(l<n&&arr[l]==0) l++;
    while(r>1&&arr[r]==1) r--;
    if(l==r) cout<<0<<endl;
    else {
        int cnt=0;
        while(l<r) {
            l++,cnt++,r--;
            while(l<r&&arr[l]==0) l++;
            while(l<r&&arr[r]==1) r--;
        }
        cout<<cnt<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}