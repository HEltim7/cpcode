#include<iostream>
using namespace std;
int n,m,t,sx,sy,fx,fy;
int sum;
bool matrix[10][10];

bool check(int row,int col){
    if(row<=n&&row>=1&&col<=n&&col>=1&&matrix[row][col]==0) return 1;
    return 0;
}

void dfs(int row,int col){
    if(row==fx&&col==fy){
        sum++;
        return;
    }
    if(check(row+1,col)){
        matrix[row+1][col]=1;
        dfs(row+1,col);
        matrix[row+1][col]=0;
    }
    if(check(row-1,col)){
        matrix[row-1][col]=1;
        dfs(row-1,col);
        matrix[row-1][col]=0;
    }
    if(check(row,col+1)){
        matrix[row][col+1]=1;
        dfs(row,col+1);
        matrix[row][col+1]=0;
    }
    if(check(row,col-1)){
        matrix[row][col-1]=1;
        dfs(row,col-1);
        matrix[row][col-1]=0;
    }
}

int main(){
    cin>>n>>m>>t>>sx>>sy>>fx>>fy;
    matrix[sx][sy]=1;
    int x,y;
    while(t--){
        cin>>x>>y;
        matrix[x][y]=1;
    }
    dfs(sx,sy);
    cout<<sum;
    return 0;
}