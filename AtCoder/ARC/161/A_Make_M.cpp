#include <algorithm>
#include <array>
#include <cassert>
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
int arr[N],ans[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    for(int i=1;i<=(n+1)/2;i++) ans[i*2-1]=arr[i];
    for(int i=(n+1)/2+1,j=1;i<=n;i++,j++) ans[j*2]=arr[i];
    debug(ans,1,n);
    for(int i=2;i<=n;i+=2) 
        if(ans[i]<=ans[i-1]||ans[i]<=ans[i+1]) {
            cout<<"No"<<endl;
            return;
        }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}