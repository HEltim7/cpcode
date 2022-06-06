#include<iostream>
#include<queue>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;
int grid[N][N];
int mv[]={-1,0,1};
pair<int,int> q[N*N];
bool mark[N][N];
int n;

inline bool check(int row,int col){
    return (row>=1&&row<=n&&col>=1&&col<=n);
}

//检查一个块周围的块数
bool bfs(int row,int col){
    int hh=0,tt=1;
    q[0]={row,col};
    set<pair<int,int>> st;
    queue<pair<int,int>> que;
    while(hh<tt){
        auto [x,y]=q[hh++];
        mark[x][y]=1;
        st.insert({x,y});
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                int r=row+mv[i];
                int c=col+mv[j];
                if(check(r,c)&&!mark[r][c]&&grid[r][c]) q[tt++]={r,c};
                if(check(r,c)&&!grid[r][c]) que.push({r,c});
            }
        if(tt>=4) return 1;
    }
    if(tt<=1) return 0;
    int cnt=0;
    while(que.size()){
        auto [x,y]=que.front();
        que.pop();
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                int r=x+mv[i];
                int c=y+mv[j];
                if(st.find({r,c})!=st.end()||!check(r,c)) continue;
                if(grid[r][c]) cnt++;
                
            }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    string in;
    for(int i=1;i<=n;i++){
        cin>>in;
        for(int j=0;j<n;j++)
            if(in[j]=='#') grid[i][j+1]=1;
    }


}