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
int arr[N],cnt[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i],cnt[arr[i]]++;
    sort(arr+1,arr+1+n);
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++) if(cnt[arr[i]]) v.emplace_back(arr[i],cnt[arr[i]]),cnt[arr[i]]=0;
    debug(v);

    int ans=0;
    if(arr[1]>0) ans++;
    int tot=0;
    for(int i=0;i<v.size();i++) {
        auto [val,ct]=v[i];
        if(val<=tot+ct-1&&(i+1>=v.size()||v[i+1].first>tot+ct)) ans++;
        tot+=ct;
        debug(i,tot,ans);
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