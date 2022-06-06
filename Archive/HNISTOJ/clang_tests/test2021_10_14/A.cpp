#include<iostream>
using namespace std;

#define check(x,y) (x>=1&&x<=n&&y>=1&&y<=m)

typedef long long LL;
int n,m,t;
int sx,sy,fx,fy;
const int N=10;
bool matrix[N][N];
LL ans;
int mc[5]={0,1,-1,0,0};
int mv[5]={0,0,0,1,-1};

void dfs(int row,int col){
    if(matrix[row][col]) return ;
    if(row==fx&&col==fy){
        ans++;
        return ;
    }
    matrix[row][col]=1;
    for(int i=1;i<=4;i++){
        int x=row+mc[i];
        int y=col+mv[i];
        if(check(x,y)) dfs(x,y);
    }
    matrix[row][col]=0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    while(t--){
        int x,y;
        cin>>x>>y;
        matrix[x][y]=1;
    }
    dfs(sx,sy);
    cout<<ans;
    return 0;
}