#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
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
constexpr int N=1e5+10;

void solve() {
    int n;
    cin>>n;
    auto adj=vector(n+1,vector<int>());
    auto dp=vector(n+1,array<LL,2>());
    vector<LL> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    function<void(int,int)> dfs=[&](int u,int fa) {
        auto check=[&](LL x) {
            LL t=sqrt(x);
            return t*t==x;
        };

        bool ok=false;
        LL mx=-1e9;
        for(int v:adj[u]) {
            if(v!=fa) {
                dfs(v,u);
                dp[u][0]+=max(dp[v][1],dp[v][0]);
                if(check(arr[u]*arr[v])) {
                    if(dp[v][0]>=dp[v][1]) dp[u][1]+=dp[v][0],ok=true;
                    else dp[u][1]+=dp[v][1],mx=max(mx,dp[v][0]+2-dp[v][1]);
                }
                else dp[u][1]+=max(dp[v][0],dp[v][1]);
            }
        }
        if(ok) dp[u][1]+=2;
        else if(mx==LL(-1e9)) dp[u][1]=-1e9;
        else dp[u][1]+=mx;
    };
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1])<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}