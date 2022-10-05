#include <functional>
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
int d[N],type[N];

void solve() {
    int n;
    cin>>n;
    vector<LL> arr[2];
    for(int i=1;i<=n;i++) cin>>type[i];
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++) arr[type[i]].push_back(d[i]);
    sort(arr[0].begin(),arr[0].end(),greater<LL>());
    sort(arr[1].begin(),arr[1].end(),greater<LL>());
    LL ans=0;
    int cnt=min(arr[0].size(),arr[1].size());
    int idx=arr[1].size()>arr[0].size();
    if(arr[1].size()==arr[0].size()) idx=arr[1].back()<arr[0].back();
    ans+=arr[idx].back();
    arr[idx].pop_back();
    for(int i=0;i<cnt&&i<arr[0].size();i++) ans+=2*arr[0][i];
    for(int i=0;i<cnt&&i<arr[1].size();i++) ans+=2*arr[1][i];
    for(int i=cnt;i<arr[0].size();i++) ans+=arr[0][i];
    for(int i=cnt;i<arr[1].size();i++) ans+=arr[1][i];
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