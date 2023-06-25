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

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    cin>>n>>k;
    
    vector<LL> arr(n),pre(n);
    for(LL &x:arr) cin>>x;
    sort(arr.begin(),arr.end());
    partial_sum(arr.begin(),arr.end(),pre.begin());
    
    LL sum=pre.back();
    LL ans=0;

    for(int i=0;i<=k;i++) {
        int j=k-i;
        LL res=sum;
        if(i) res-=pre[i*2-1];
        if(j) res-=pre.back()-*(pre.rbegin()+j);
        ans=max(ans,res);
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