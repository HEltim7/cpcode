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
    int n,m;
    cin>>n>>m;

    auto dis1=vector(n+1,vector(m+1,1e9));
    auto dis2=dis1;
    using PII=pair<int,int>;

    int vx,vy;
    auto grid=vector(n+1,string(m+1,'#'));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='V') vx=i,vy=j;
        }
    }

    auto bfs=[&]() {
        auto mark1=vector(n+1,vector(m+1,false));
        auto mark2=mark1;
        queue<PII> q;
        auto add=[&](int i,int j) {
            dis1[i][j]=1;
            q.emplace(i,j);
        };
        for(int i=1;i<=m;i++) {
            if(grid[1][i]=='.') add(1,i);
            if(grid[n][i]=='.') add(n,i);
        }
        for(int i=2;i<n;i++) {
            if(grid[i][1]=='.') add(i,1);
            if(grid[i][m]=='.') add(i,m);
        }

        auto mvr=array{1,-1,0,0};
        auto mvc=array{0,0,1,-1};
        while(q.size()) {
            auto [r,c]=q.front();
            auto check=[&](int x,int y) {
                return x>=1&&x<=n&&y>=1&&y<=m&&grid[x][y]!='#';
            };
            q.pop();

            for(int i=0;i<4;i++) {
                int x=r+mvr[i];
                int y=c+mvc[i];
                if(check(x,y)) {

                }
            }
        }
    };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}