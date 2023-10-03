#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr.begin()+1,arr.end());

    vector<int> cu(n+1),lim(n+1);
    for(int l=1,r=5;r<=n;l++,r++) {
        for(int j=l;j<r;j++) cu[r]+=arr[j];
        lim[r]=cu[r]-arr[r]-1;
    }
    
    int ans=-1;
    lim[0]=1e9;
    vector<int> stk({0,5});
    for(int i=6;i<n;i++) {
        int l=0,r=stk.size()-1;
        while(l<r) {
            int m=(l+r+1)/2;
            if(arr[i]<=lim[stk[m]]) l=m;
            else r=m-1;
        }
        if(l) {
            int j=stk[l];
            int ag=arr[i]+arr[j];
            int idx=lower_bound(arr.begin()+i+1,arr.end(),ag)-arr.begin()-1;
            if(idx>i) ans=max(ans,cu[j]+ag+arr[idx]);
        }
        while(lim[i]>=lim[stk.back()]) stk.pop_back();
        stk.emplace_back(i);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}