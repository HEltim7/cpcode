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
    int pos=0,neg=0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(arr[i]>0) pos++;
        else if(arr[i]<0) neg++;
        if(arr[i]>maxx) maxx=arr[i],idx1=i;
        if(arr[i]<minn) minn=arr[i],idx2=i;
    }
    maxx=max(maxx,0LL);
    minn=min(minn,0LL);

    if(pos==0&&neg==0) {
        cout<<0<<endl;
        return;
    }

    LL t=maxx;
    int max_step=0;
    while(maxx&&abs(t)<abs(minn)) {
        max_step++;
        t+=t;
    }

    t=minn;
    int min_step=0;
    while(minn&&abs(t)<abs(maxx)) {
        min_step++;
        t+=t;
    }

    vector<pair<int,int>> ans;
    if(maxx&&max_step+neg+19<=31) {
        while(max_step--) {
            ans.emplace_back(idx1,idx1);
            arr[idx1]+=arr[idx1];
            maxx+=maxx;
        }
        for(int i=1;i<=n;i++) {
            if(arr[i]<0) {
                arr[i]+=maxx;
                ans.emplace_back(i,idx1);
            }
        }
        for(int i=2;i<=n;i++) {
            arr[i]+=arr[i-1];
            ans.emplace_back(i,i-1);
        }
    }
    else {
        while(min_step--) {
            ans.emplace_back(idx2,idx2);
            arr[idx2]+=arr[idx2];
            minn+=minn;
        }
        for(int i=1;i<=n;i++) {
            if(arr[i]>0) {
                arr[i]+=minn;
                ans.emplace_back(i,idx2);
            }
        }
        for(int i=n-1;i>=1;i--) {
            arr[i]+=arr[i+1];
            ans.emplace_back(i,i+1);
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