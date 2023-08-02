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
constexpr int N=210;
bool grid[N][N],vis[N][N],mark[N][N];
constexpr int mvr[]={1,0,-1,0};
constexpr int mvc[]={0,1,0,-1};

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            char in;
            cin>>in;
            grid[i][j]=in=='.';
        }
    }

    auto go=[&](int r,int c,int d) {
        vis[r][c]=1;
        while(grid[r+mvr[d]][c+mvc[d]]) {
            vis[r][c]=1;
            r+=mvr[d];
            c+=mvc[d];
        }
        return pair{r,c};
    };

    queue<pair<int,int>> q;
    mark[2][2]=1;
    q.emplace(2,2);
    while(q.size()) {
        auto [r,c]=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            auto [x,y]=go(r, c, i);
            if(!mark[x][y]) {
                q.emplace(x,y);
                mark[x][y]=1;
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans+=vis[i][j];
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}