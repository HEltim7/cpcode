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

#define endl '\n'
using LL=long long;
constexpr int N=20;
int n,t,m,maxx,zero;
int team[N],cnt[N];
vector<int> dif[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

LL ans=0;
void dfs(int idx) {
    if(idx>n) {
        ans++;
        return;
    }

    for(int i=1;i<=t;i++) {
        team[idx]=i;
        if(cnt[i]+1>maxx) continue;
        if(n-idx<zero-(!cnt[i])) continue;
        bool flag=0;
        for(int x:dif[idx]) 
            if(team[x]==i) {
                flag=1;
                break;
            }
        if(flag) continue;
        if(++cnt[i]==1) zero--;
        dfs(idx+1);
        if(--cnt[i]==0) zero++;
    }
    team[idx]=0;
}

void solve() {
    cin>>n>>t>>m;
    for(int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        dif[a].push_back(b);
        dif[b].push_back(a);
    }
    maxx=n-t+1;
    zero=t;
    dfs(1);
    for(int i=1;i<=t;i++) ans/=i;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}