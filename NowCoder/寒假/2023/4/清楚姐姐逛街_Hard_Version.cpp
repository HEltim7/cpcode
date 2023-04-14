#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=810,INF=N*N,M=__lg(INF)+1;
int grid[N][N],mp[1<<7];
int mvr[]={0,-1,1,0,0,0};
int mvc[]={0,0,0,-1,1,0};
int dis[N][N],ans[N][N];
vector<pair<int,int>> src[M][N][N];
vector<pair<int,int>> rev[N][N];

void solve() {
    mp['#']=0,mp['U']=1,mp['D']=2,mp['L']=3,mp['R']=4,mp['.']=5;
    int n,m,xs,ys,q;
    cin>>n>>m>>xs>>ys>>q;
    xs++,ys++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            char in;
            cin>>in;
            grid[i][j]=mp[in];
        }

    auto chino=[&]() {
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dis[i][j]=INF;
        queue<pair<int,int>> q;
        q.emplace(xs,ys);
        dis[xs][ys]=0;
        while(q.size()) {
            auto [x,y]=q.front();
            q.pop();
            for(int i=1;i<=4;i++) {
                int r=x+mvr[i];
                int c=y+mvc[i];
                if(grid[r][c]) {
                    if(dis[r][c]>dis[x][y]+1) {
                        dis[r][c]=dis[x][y]+1;
                        q.emplace(r,c);
                    }
                }
            }
        }
    };

    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) {
            int s=grid[i][j];
            int t=grid[i+mvr[s]][j+mvc[s]];
            if(s) {
                if(t) src[0][i+mvr[s]][j+mvc[s]].emplace_back(i,j);
                else src[0][i][j].emplace_back(i,j);
            }
        }

    for(int k=1;k<M;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(auto [r,c]:src[k-1][i][j])
                    for(auto [x,y]:src[k-1][r][c])
                        src[k][i][j].emplace_back(x,y);

    chino();
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ans[i][j]=INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            int d=dis[i][j];
            if(d==INF) continue;
            vector<pair<int,int>> vec(1,{i,j}),bak;
            for(int k=M-1;d&&k>=0;k--) {
                if((1<<k)<=d) {
                    bak=vec;
                    vec.clear();
                    for(auto [r,c]:bak)
                        for(auto [x,y]:src[k][r][c])
                            vec.emplace_back(x,y);
                    d-=1<<k;
                }
            }
            for(auto [r,c]:vec) ans[r][c]=min(ans[r][c],dis[i][j]);
        }

    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) {
            int r=i+mvr[grid[i][j]];
            int c=j+mvc[grid[i][j]];
            ans[i][j]=min(ans[i][j],ans[r][c]+1);
        }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(ans[i][j]==INF) ans[i][j]=-1;
    
    while(q--) {
        int x,y;
        cin>>x>>y;
        x++,y++;
        cout<<ans[x][y]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}