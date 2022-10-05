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

void solve() {
    int n;
    vector<int> arr;
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    int cnt=n-arr.size();
    while(cnt--) arr.push_back(2e9);
    int ans=0;
    for(int i=0;i<arr.size();i++) {
        bool flag=1;
        while(arr[i]-ans>=2&&flag) {
            if(arr.size()-i>=2) {
                arr.pop_back();
                arr.pop_back();
                ans++;
            }
            else flag=0;
        }
        debug(ans,i,flag);
        if(flag&&i<arr.size()) ans++;
        else break;
    }
    
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}