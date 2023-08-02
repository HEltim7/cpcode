#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
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
    int sum=arr[1];
    for(int i=2;i<=n;i++) sum&=arr[i];

    if(sum==0) {
        int ans=0;
        for(int i=1,len=0,cur=0;i<=n;i++) {
            if(len==0) cur=arr[i],ans++;
            else cur&=arr[i];
            len++;

            if(cur==sum) {
                len=0;
            }
            else if(i==n) ans--;
        }
        cout<<ans<<endl;
    }
    else cout<<1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}