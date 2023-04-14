#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;

const int N=1e3+10,INF=0x3f3f3f3f;
bool mirror[N][N];
bool mark[N][N];
int n,m;

struct NODE{
    int row,col,dir;
};

inline bool check(int row,int col){
    return row>=1&&row<=n&&col>=1&&col<=m;
}

int bfs(queue<NODE> &q){
    // 1,2,3,4=上下左右
    int mvr[]={0,1,-1,0,0};
    int mvc[]={0,0,0,1,-1};
    int dir[2][5]={{0,4,3,2,1},{0,3,4,1,2}};
    int res=0;
    while(q.size()){
        auto [r,c,d]=q.front();
        q.pop();
        res++;
        int type=mirror[r][c];
        int z=dir[type][d];
        int x=r+mvr[z];
        int y=c+mvc[z];
        if(check(x,y)) q.push({x,y,z});
        else mark[x][y]=1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    char in;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>in;
            if(in=='/') mirror[i][j]=0;
            else mirror[i][j]=1;
        }
    int ans=0;
    queue<NODE> q;
    //从上边入射
    for(int i=1;i<=m;i++) 
        if(!mark[0][i])
            q.push({1,i,1}),mark[0][i]=1,ans=max(ans,bfs(q));
    //从下边入射
    for(int i=1;i<=m;i++) 
        if(!mark[n+1][i])
            q.push({n,i,2}),mark[n+1][i]=1,ans=max(ans,bfs(q));
    //从左边入射
    for(int i=1;i<=n;i++) 
        if(!mark[i][0])
            q.push({i,1,3}),mark[i][0]=1,ans=max(ans,bfs(q));
    //从右边入射
    for(int i=1;i<=n;i++) 
        if(!mark[i][m+1])
            q.push({i,m,4}),mark[i][m+1]=1,ans=max(ans,bfs(q));
    cout<<ans;
    return 0;
}