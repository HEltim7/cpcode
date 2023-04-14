#include <queue>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=55;
bool grid[N][N],mark[N][N];
bool le[N][N],ri[N][N],up[N][N],dn[N][N];
int mvr[]={0,0,1,-1};
int mvc[]={1,-1,0,0};

pair<PII,PII> bfs(int x,int y) {
    queue<PII> q;
    q.emplace(x,y);

    int U=N,D=0,L=N,R=0;
    while(q.size()) {
        auto [r,c]=q.front();
        q.pop();
        if(mark[r][c]) continue;
        mark[r][c]=1;

        U=min(U,r);
        D=max(D,r);
        L=min(L,c);
        R=max(R,c);

        for(int i=0;i<4;i++) {
            int x=r+mvr[i];
            int y=c+mvc[i];
            if(grid[x][y]) q.emplace(x,y);
        }
    }
    return {{U,D},{L,R}};
}

void solve() {
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)
            grid[i][j]=mark[i][j]=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            char in;
            cin>>in;
            grid[i][j]=in=='#';
        }
    
    int U[2],D[2],L[2],R[2];
    for(int i=1,idx=0;i<=n;i++)
        for(int j=1;j<=m;j++) {
            if(!mark[i][j]&&grid[i][j]) {
                auto [x,y]=bfs(i,j);
                tie(U[idx],D[idx])=x;
                tie(L[idx],R[idx])=y;
                idx^=1;
            }
        }

    if((max(U[0],U[1])>min(D[0],D[1]))&&(max(L[0],L[1])>min(R[0],R[1]))) {
        bool idx_up=D[1]<U[0],idx_le=R[1]<L[0];
        int r1=D[idx_up],r2=U[idx_up^1];

        int c1=idx_le==idx_up?R[idx_up]:L[idx_up];
        int c2=idx_le==idx_up?L[idx_up^1]:R[idx_up^1];
        for(int i=r1;i>=1&&!grid[i][c1];i--) grid[i][c1]=1;
        for(int i=r2;i<=n&&!grid[i][c2];i++) grid[i][c2]=1;

        if(idx_le==idx_up) {
            for(int j=c1;j>=1&&!grid[r1][j];j--) grid[r1][j]=1;
            for(int j=c2;j<=m&&!grid[r2][j];j++) grid[r2][j]=1;
        }
        else {
            for(int j=c1;j<=m&&!grid[r1][j];j++) grid[r1][j]=1;
            for(int j=c2;j>=1&&!grid[r2][j];j--) grid[r2][j]=1;
        }
        grid[r1][c2]=1;
    }

    auto fill=[&]() {
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=m+1;j++)
                le[i][j]=ri[i][j]=up[i][j]=dn[i][j]=0;

        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) le[i][j]=le[i][j-1]|grid[i][j];
        for(int i=1;i<=n;i++) for(int j=m;j>=1;j--) ri[i][j]=ri[i][j+1]|grid[i][j];
        for(int j=1;j<=m;j++) for(int i=1;i<=n;i++) up[i][j]=up[i-1][j]|grid[i][j];
        for(int j=1;j<=m;j++) for(int i=n;i>=1;i--) dn[i][j]=dn[i+1][j]|grid[i][j];

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                grid[i][j]|=le[i][j-1]&&ri[i][j+1]||up[i-1][j]&&dn[i+1][j];
    };

    fill();
    fill();

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)
            cout<<(grid[i][j]?'#':'.');
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}