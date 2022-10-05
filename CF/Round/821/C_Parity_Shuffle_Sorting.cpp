#include <utility>
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
constexpr int N=1e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int val=arr[1]&1;
    int pos=n;
    vector<pair<int, int>> ans;
    for(int i=n;i>=1;i--) if((arr[i]&1)==val) {
        pos=i;
        break;
    }
    for(int i=1;i<pos;i++)
        if((arr[i]&1)==val) {
            arr[i]=arr[pos];
            ans.emplace_back(i,pos);
        }
    for(int i=2;i<=n;i++)
        if((arr[i]&1)!=val) {
            arr[i]=arr[1];
            ans.emplace_back(1,i);
        }
    debug(arr,1,n);
    cout<<ans.size()<<endl;
    for(auto [l,r]:ans) cout<<l<<' '<<r<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}