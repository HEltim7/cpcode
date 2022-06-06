#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_set>
#include<tuple>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e3+10;
int grid[N][N];
bool pass[N][N][4];
bool mark[N][N];
int n;

inline bool check(int r,int c,int i){
    return r>=1&&r<=n&&c>=1&&c<=n&&grid[r][c]&&!pass[r][c][i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int sr,sc,er,ec;
    cin>>n>>sr>>sc>>er>>ec;
    for(int i=1;i<=n;i++){
        string in;
        cin>>in;
        for(int j=0;j<in.size();j++)
            grid[i][j+1]=in[j]=='.';
    }

    queue<tuple<int,int,int>> q;
    q.push({sr,sc,0});
    mark[sr,sc];

    int mvr[]={1,1,-1,-1};
    int mvc[]={-1,1,-1,1};
    while(q.size()){
        auto [r,c,step]=q.front();
        q.pop();
        if(r==er&&c==ec){
            cout<<step;
            return 0;
        }

        for(int i=0;i<4;i++){
            for(int j=1;;j++){
                int row=r+mvr[i]*j;
                int col=c+mvc[i]*j;
                if(!check(row,col,i)) break;
                else if(!mark[row][col]){
                    q.push({row,col,step+1});
                }
                pass[row][col][i]=1;
                mark[row][col]=1;
            }
        }
    }
    cout<<-1;
    return 0;
}