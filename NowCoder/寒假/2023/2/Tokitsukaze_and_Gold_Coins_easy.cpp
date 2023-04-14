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
constexpr int N=5e5+10;
int grid[N][4];
bool mark[2][N][4];
int mvr[2],mvc[2];

void dfs(int n,int r,int c,int idx) {
    for(int i=0;i<2;i++) {
        int row=r+mvr[i];
        int col=c+mvc[i];
        if(row>=1&&row<=n&&col>=1&&col<=3&&!mark[idx][row][col]&&!grid[row][col]) {
            mark[idx][row][col]=1;
            dfs(n,row,col,idx);
        }
    }
}

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) grid[i][j]=0;
    for(int i=0;i<2;i++) for(int j=1;j<=n;j++) for(int k=1;k<=3;k++) mark[i][j][k]=0;
    for(int i=1;i<=k;i++) {
        int x,y;
        cin>>x>>y;
        if(!grid[x][y]) grid[x][y]=1;
        else grid[x][y]=0;
    }
    
    int ans=0;
    mvr[0]=1,mvr[1]=0;
    mvc[0]=0,mvc[1]=1;
    dfs(n,1,1,0);
    mvr[0]=-1,mvr[1]=0;
    mvc[0]=0,mvc[1]=-1;
    dfs(n,n,3,1);
    for(int j=1;j<=n;j++) for(int k=1;k<=3;k++) if(mark[0][j][k]&&mark[1][j][k]) ans++;
    if(ans) ans++;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}