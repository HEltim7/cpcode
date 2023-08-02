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

void solve() {
    int n;
    cin>>n;
    vector<LL> arr(n+1);
    LL maxx=-1e9,minn=1e9,idx1=1,idx2=1;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(arr[i]>maxx) maxx=arr[i],idx1=i;
        if(arr[i]<minn) minn=arr[i],idx2=i;
    }
    if(maxx==0&&minn==0) {
        cout<<0<<endl;
        return;
    }

    vector<pair<int,int>> ans;
    if(maxx>0) {
        for(int i=1;i<=6;i++) {
            arr[idx1]+=arr[idx1];
            maxx+=maxx;
            ans.emplace_back(idx1,idx1);
        }
        for(int i=2;i<=n;i++) {
            while(arr[i]<arr[i-1]) {
                arr[i]+=maxx;
                ans.emplace_back(i,idx1);
                if(arr[i]>maxx) maxx=arr[i],idx1=i;
            }
        }
    }
    else {
        for(int i=1;i<=6;i++) {
            arr[idx2]+=arr[idx2];
            minn+=minn;
            ans.emplace_back(idx2,idx2);
        }
        for(int i=n-1;i>=1;i--) {
            while(arr[i]>arr[i+1]) {
                arr[i]+=minn;
                ans.emplace_back(i,idx2);
                if(arr[i]<minn) minn=arr[i],idx2=i;
            }
        }
    }
    debug(arr,1,n);
    assert(is_sorted(arr.begin()+1,arr.end()));
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}