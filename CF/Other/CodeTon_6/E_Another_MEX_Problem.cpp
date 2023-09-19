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
    auto work=[&]() {
        vector<int> r(n+1,n+1);
        vector<tuple<int,int,int>> seg;
        for(int i=n;i>=1;i--) {
            r[arr[i]]=i;
            int idx=i;
            for(int j=0;j<arr[i];j++) idx=max(idx,r[j]);
            if(idx<=n) {
                vector<bool> mark(n+1);
                for(int j=i;j<=idx;j++) mark[arr[j]]=1;
                int m=0;
                while(mark[m]) m++;
                seg.emplace_back(i,idx,m);
            }
        }
        return seg;
    };

    auto seg=vector(n+1,vector<pair<int,int>>());
    auto tmp=work();
    for(auto [l,r,m]:tmp) seg[l].emplace_back(r,m);
    reverse(arr.begin()+1,arr.end());
    tmp=work();
    for(auto [l,r,m]:tmp) seg[n-r+1].emplace_back(n-l+1,m);

    auto dp=vector(n+1,vector<bool>(n+1));
    dp[0][0]=1;
    for(int i=0;i<n;i++) {
        for(auto [r,m]:seg[i+1])
            for(int j=0;j<=n;j++)
                dp[r][j^m]=max(dp[r][j^m],dp[i][j]);
        for(int j=0;j<=n;j++) dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
    }

    int ans=n;
    while(!dp[n][ans]) ans--;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}