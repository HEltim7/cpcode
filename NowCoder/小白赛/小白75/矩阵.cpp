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
constexpr int N=1e3+10;
bool grid[N][N],mark[N][N][2];
int mvr[]={1,-1,0,0};
int mvc[]={0,0,1,-1};

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            char in;
            cin>>in;
            grid[i][j]=in=='1';
        }
    }

    auto bfs=[&]() {
        using TPL=tuple<int,int,int,bool>;
        priority_queue<TPL,vector<TPL>,greater<>> heap;
        heap.emplace(0,1,1,grid[1][1]);
        mark[1][1][grid[1][1]]=1;
        while(heap.size()) {
            auto [d,r,c,v]=heap.top();
            heap.pop();
            if(r==n&&c==m) return d;
            for(int i=0;i<4;i++) {
                int x=r+mvr[i];
                int y=c+mvc[i];
                if(x>=1&&x<=n&&y>=1&&y<=m&&!mark[x][y][!v]) {
                    mark[x][y][!v]=1;
                    if(grid[x][y]!=v) heap.emplace(d+1,x,y,!v);
                    else heap.emplace(d+2,x,y,!v);
                }
            }
        }
        return -1;
    };

    cout<<bfs()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}