#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=810,INF=1e9;
char grid[N][N];
int dis[N][N];
int n,m,xs,ys;
int mvr[]={-1,1,0,0};
int mvc[]={0,0,-1,1};
bool mark[N][N];

bool check(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=m&&grid[x][y]!='#';
}

void bfs() {
    queue<pair<int,int>> q;
    q.emplace(xs,ys);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dis[i][j]=INF;
    dis[xs][ys]=0;
    while(q.size()) {
        auto [r,c]=q.front();
        q.pop();
        if(mark[r][c]) continue;
        mark[r][c]=1;
        for(int i=0;i<4;i++) {
            int x=r+mvr[i];
            int y=c+mvc[i];
            if(check(x,y)) {
                q.emplace(x,y);
                dis[x][y]=min(dis[x][y],dis[r][c]+1);
            }
        }
    }
}

vector<pair<int,int>> go(int xt,int yt) {
    vector<pair<int,int>> res;
    for(int i=1;i<=N*N&&check(xt,yt);i++) {
        res.emplace_back(xt, yt);
        int idx;
        if(grid[xt][yt]=='U') idx=0;
        else if(grid[xt][yt]=='D') idx=1;
        else if(grid[xt][yt]=='L') idx=2;
        else if(grid[xt][yt]=='R') idx=3;
        else if(grid[xt][yt]=='.') break;

        xt+=mvr[idx];
        yt+=mvc[idx];
    }
    return res;
}

void solve() {
    int q;
    cin>>n>>m>>xs>>ys>>q;
    xs++,ys++;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>grid[i][j];
    bfs();
    while(q--) {
        int xt,yt;
        cin>>xt>>yt;
        xt++,yt++;
        auto &&path=go(xt, yt);
        debug(path);
        int ans=INF;
        for(int i=0;i<path.size();i++) {
            auto [x,y]=path[i];
            if(dis[x][y]<=i) ans=min(ans,i);
        }
        auto [x,y]=path.back();
        debug(x,y,dis[x][y]);
        ans=min(ans,max(dis[x][y],int(path.size())));
        if(ans==INF) ans=-1;
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}