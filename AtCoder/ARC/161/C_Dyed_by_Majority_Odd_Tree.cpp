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

constexpr int N=2e5+10;
bool arr[N],dp[N][2][2],ans[N];
vector<int> adj[N];

bool dfs(int u,int fa) {
    int ch=0;
    for(int v:adj[u]) {
        if(v!=fa) {
            ch++;
            if(!dfs(v,u)) return false;
            debug(v);
            debug(dp[v][0]);
            debug(dp[v][1]);
        }
    }

    if(!ch) {
        dp[u][0][arr[u]]=1;
        dp[u][1][arr[u]]=1;
        dp[u][0][!arr[u]]=0;
        dp[u][1][!arr[u]]=0;
        return true;
    }
    else {
        int sz=adj[u].size();
        for(int c=0;c<=1;c++) {
            dp[u][c][0]=dp[u][c][1]=0;
            int cnt=0;
            bool valid=1;
            for(int v:adj[u]) {
                if(v!=fa) {
                    cnt+=dp[v][arr[u]][c];
                    if(!dp[v][0][c]&&!dp[v][1][c]) {
                        valid=0;
                        break;
                    }
                }
            }
            if(!valid) continue;

            if(cnt>=(sz+1)/2) {
                dp[u][c][0]=dp[u][c][1]=1;
            }
            else if(u!=1&&cnt+1>=(sz+1)/2) {
                dp[u][c][arr[u]]=1;
            }
        }

        return dp[u][0][0]|dp[u][0][1]|dp[u][1][0]|dp[u][1][1];
    }
}

void get_ans(int u,int fa,bool c) {
    ans[u]=c;
    for(int v:adj[u]) {
        if(v!=fa) {
            if(dp[v][arr[u]][c]) get_ans(v, u, arr[u]);
            else get_ans(v, u, !arr[u]);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) memset(dp[i], 0, sizeof dp[i]);
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        arr[i]=in=='B';
    }
    debug(arr,1,n);

    if(!dfs(1,0)) {
        cout<<-1<<endl;
        return;
    }

    if(dp[1][0][!arr[1]]) get_ans(1, 0, 0);
    else get_ans(1, 0, 1);
    for(int i=1;i<=n;i++) cout<<(ans[i]?'B':'W');
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}