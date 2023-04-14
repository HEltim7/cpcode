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
int dep[N];

void solve() {
    int n;
    cin>>n;
    vector<int> dep_cnt(1,1);
    dep[1]=1;
    for(int i=2;i<=n;i++) {
        int p;
        cin>>p;
        dep[i]=dep[p]+1;
        dep_cnt.push_back(dep[i]);
    }
    sort(dep_cnt.begin(),dep_cnt.end(),greater<>());
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr.begin(),arr.end(),greater<>());
    LL ans=0;
    for(int i=0;i<n;i++) {
        ans+=1LL*dep_cnt[i]*arr[i];
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}