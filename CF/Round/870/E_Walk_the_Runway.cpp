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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=510,M=5e3+10;
int rt[N][M];
LL dp[M],p[M];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>p[i];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>rt[i][j];
        }
    }

    // cur>pre
    auto cmp=[&](int pre,int cur) {
        for(int k=1;k<=n;k++) {
            if(rt[k][pre]>=rt[k][cur])
                return false;
        }
        return true;
    };

    LL ans=0;
    vector<pair<LL,int>> stk;
    stk.emplace_back(0,0);
    for(int i=1;i<=m;i++) {
        int l=0,r=stk.size()-1;
        while(l<r) {
            int mid=l+r+1>>1;
            if(cmp(stk[mid].second,i)) l=mid;
            else r=mid-1;
        }
        dp[i]=stk[l].first+p[i];
        for(int k=1;l+k<stk.size();k++) stk[k+l].first+=dp[i],dp[stk[k].second]+=dp[i];
        while(l+1<stk.size()&&stk[l+1].first<=dp[i]&&!cmp(i, stk[l+1].second)) {
            stk.erase(stk.begin()+l+1);
        }
        if(l+1>=stk.size()) stk.emplace_back(dp[i],i);
        else stk.insert(stk.begin()+l+1,make_pair(dp[i],i));
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}