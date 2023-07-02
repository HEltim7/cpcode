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
constexpr int N=510;
char grid[N][N];
bool mark[N][N][10];
constexpr int mvr[]={1,-1,0,0};
constexpr int mvc[]={0,0,1,-1};
const string snuke("snuke");

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>grid[i][j];
        }
    }
    if(grid[1][1]!='s') {
        cout<<"No"<<endl;
        return;
    }

    auto bfs=[&]() {
        queue<tuple<int,int,int>> q;
        q.emplace(1,1,0);
        mark[1][1][0]=1;
        while(q.size()) {
            auto [r,c,v]=q.front();
            q.pop();
            if(r==n&&c==m) return true;
            for(int k=0;k<4;k++) {
                int x=r+mvr[k];
                int y=c+mvc[k];
                int ne=(v+1)%5;
                if(x>=1&&x<=n&&y>=1&&y<=m&&!mark[x][y][ne]&&grid[x][y]==snuke[ne]) {
                    q.emplace(x,y,ne);
                    mark[x][y][ne]=1;
                }
            }
        }
        return false;
    };

    cout<<(bfs()?"Yes":"No")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}