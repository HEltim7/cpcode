#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N=22;
char matrix[N][N];
bool mark[N][N];
int w,h;
int sr,sc,sum;
int mr[5]={0,1,-1};
int mc[5]={0,0,0,1,-1};
queue <pair<int,int>> q;

bool check(int row,int col){
    if(row>=1&&row<=h&&col>=1&&col<=w&&!mark[row][col]&&matrix[row][col]!='#') return 1;
    return 0;
}

void bfs(){
    if(q.empty()) return;
    auto tmp=q.front();
    for(int i=1;i<=4;i++){
        tmp.first+=mr[i];
        tmp.second+=mc[i];
        if(check(tmp.first,tmp.second)) {
            q.push(tmp);
            mark[tmp.first][tmp.second]=1;
            sum++;
        }
        tmp=q.front();
    }
    q.pop();
    bfs();
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while(cin>>w>>h&&(w!=0||h!=0)){
        memset(mark,0,sizeof mark);
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                cin>>matrix[i][j];
                if(matrix[i][j]=='@'){
                    sr=i,sc=j;
                    matrix[i][j]='.';
                    q.emplace(i,j);
                    mark[i][j]=1;
                    sum=1;
                }
            }
        }
        bfs();
        cout<<sum<<'\n';
        sum=0;
    }
    return 0;
}