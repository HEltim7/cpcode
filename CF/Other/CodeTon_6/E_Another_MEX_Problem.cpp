#include <algorithm>
#include <array>
#include <bitset>
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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=5e3+10,M=1<<13;
using BS=bitset<M>;
int mex[N][N],ed[N][N];
BS dp[N];

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    set<int> bak,st;
    for(int i=0;i<=n;i++) bak.insert(i);
    for(int i=1;i<=n;i++) {
        st=bak;
        for(int j=i,last=i;j<=n;j++) {
            auto it=st.find(arr[j]);
            if(it!=st.end()) st.erase(arr[j]);
            mex[i][j]=*st.begin();
            if(j==i||mex[i][j-1]==mex[i][j]) ed[i][last]=j;
            else last=j,ed[i][last]=j;
        }
    }

    for(int i=1;i<=n;i++) dp[i].reset();
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        dp[i][0]=1;
        for(int j=i;j<=n;j=ed[i][j]+1) {
            for(int k=dp[i-1]._Find_first();k<M;k=dp[i-1]._Find_next(k)) {
                dp[j][k^mex[i][j]]=1;
            }
        }
        dp[i]|=dp[i-1];
    }

    for(int i=M-1;i>=0;i--) if(dp[n][i]) {
        cout<<i<<endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}