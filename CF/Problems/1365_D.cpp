#include <algorithm>
#include <array>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#include <cstring>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

constexpr int N=55;
constexpr int mvr[]={-1,1,0,0};
constexpr int mvc[]={0,0,1,-1};
char grid[N][N];
bool mark[N][N];

void solve() {
    int n,m;
    cin>>n>>m;
    int good=0;

    #define yes() { \
        cout<<"Yes"<<endl; \
        return; \
    }

    #define no() { \
        cout<<"No"<<endl; \
        return; \
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>grid[i][j];
            good+=grid[i][j]=='G';
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(grid[i][j]=='B') {
                for(int k=0;k<4;k++) {
                    int x=i+mvr[k];
                    int y=j+mvc[k];
                    if(x>=1&&x<=n&&y>=1&&y<=m) {
                        if(grid[x][y]=='G') no();
                        if(grid[x][y]=='.') grid[x][y]='#';
                    }
                }
            }
        }
    }

    if(grid[n][m]=='B') no();
    if(!good) yes();
    if(grid[n][m]=='#') no();

    memset(mark, 0, sizeof mark);
    queue<pair<int,int>> q;
    q.emplace(n,m);
    mark[n][m]=1;
    while(q.size()) {
        auto [r,c]=q.front();
        if(grid[r][c]=='G') good--;
        q.pop();
        for(int i=0;i<4;i++) {
            int x=r+mvr[i];
            int y=c+mvc[i];
            if(x>=1&&x<=n&&y>=1&&y<=m&&!mark[x][y]&&grid[x][y]!='#') {
                q.emplace(x,y);
                mark[x][y]=1;
            }
        }
    }

    if(good) no()
    else yes();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}