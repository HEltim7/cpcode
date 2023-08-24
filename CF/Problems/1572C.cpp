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
    auto pos=vector(n+1,vector<int>());
    auto dp=vector(n+1,vector(n+1,int(1e9)));
    for(int i=1;i<=n;i++) dp[i][i]=0;

    int idx=0;
    for(int i=1;i<=n;i++) {
        cin>>arr[++idx];
        if(arr[idx]==arr[idx-1]) idx--;
        else pos[arr[idx]].emplace_back(idx);
    }
    n=idx;

    for(int len=2;len<=n;len++) {
        for(int i=1,j=i+len-1;j<=n;i++,j++) {
            dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
            const auto &p=pos[arr[i]];
            int l=lower_bound(p.begin(),p.end(),i)-p.begin();
            for(int r=l+1;r<p.size()&&p[r]<=j;r++) {
                dp[i][j]=min(dp[i][j],dp[i+1][p[r]-1]+dp[p[r]][j]+1);
            }
        }
    }
    cout<<dp[1][n]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}