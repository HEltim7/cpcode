#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <locale>
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
    int n,m;
    cin>>n>>m;
    auto grid=vector(n+1,string());
    auto ans=vector(n+1,vector(m+1,'.'));
    for(int i=1;i<=n;i++) cin>>grid[i],grid[i]=" "+grid[i];

    auto lcol=vector(m+1,vector<int>());
    auto urow=vector(n+1,vector<int>());
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(grid[i][j]=='L') lcol[j].emplace_back(i);
            else if(grid[i][j]=='U') urow[i].emplace_back(j);
        }
    }

    for(int i=1;i<=m;i++) {
        if(lcol[i].size()&1) {
            cout<<"-1"<<endl;
            return;
        }
        while(lcol[i].size()) {
            int r1=lcol[i].back();
            lcol[i].pop_back();
            int r2=lcol[i].back();
            lcol[i].pop_back();
            ans[r1][i]='W';
            ans[r1][i+1]='B';
            ans[r2][i]='B';
            ans[r2][i+1]='W';
        }
    }

    for(int i=1;i<=n;i++) {
        if(urow[i].size()&1) {
            cout<<"-1"<<endl;
            return;
        }
        while(urow[i].size()) {
            int c1=urow[i].back();
            urow[i].pop_back();
            int c2=urow[i].back();
            urow[i].pop_back();
            ans[i][c1]='W';
            ans[i+1][c1]='B';
            ans[i][c2]='B';
            ans[i+1][c2]='W';
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cout<<ans[i][j];
        }
        cout<<endl;
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