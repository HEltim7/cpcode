#include<iostream>
using namespace std;
const int N=40;
int n;
int matrix[N][N];
bool mark[N][N];
struct q_data{
    int row;
    int col;
}q[N*N];
int h,t=-1;

bool q_empty(){
    if(h>t) return 1;
    return 0;
}

void push(q_data in){
    q[++t]=in;
}

bool check(int row,int col){
    if(row<=n&&row>=1&&col<=n&&col>=1&&matrix[row][col]==0&&mark[row][col]==0){
        mark[row][col]=1;
        return 1;
    }
    return 0;
}

void bfs(){
    if(q_empty()) return;
    q_data tmp=q[h];
    if(check(tmp.row+1,tmp.col)){
        tmp.row++;
        push(tmp);
        tmp=q[h];
    }
    if(check(tmp.row-1,tmp.col)){
        tmp.row--;
        push(tmp);
        tmp=q[h];
    }
    if(check(tmp.row,tmp.col+1)){
        tmp.col++;
        push(tmp);
        tmp=q[h];
    }
    if(check(tmp.row,tmp.col-1)){
        tmp.col--;
        push(tmp);
        tmp=q[h];
    }
    h++;
    bfs();
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>matrix[i][j];
    for(int i=1;i<=n;i++){
        if(matrix[i][1]==0&&!mark[i][1]){
            mark[i][1]=1;
            q_data tmp;
            tmp.row=i;
            tmp.col=1;
            push(tmp);
            bfs();
        }
    }
    for(int i=1;i<=n;i++){
        if(matrix[1][i]==0&&!mark[1][i]){
            mark[1][i]=1;
            q_data tmp;
            tmp.row=1;
            tmp.col=i;
            push(tmp);
            bfs();
        }
    }
    for(int i=1;i<=n;i++){
        if(matrix[i][n]==0&&!mark[i][n]){
            mark[i][n]=1;
            q_data tmp;
            tmp.row=i;
            tmp.col=n;
            push(tmp);
            bfs();
        }
    }
    for(int i=1;i<=n;i++){
        if(matrix[n][i]==0&&!mark[n][i]){
            mark[n][i]=1;
            q_data tmp;
            tmp.row=n;
            tmp.col=i;
            push(tmp);
            bfs();
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mark[i][j]&&matrix[i][j]==0) cout<<0<<' ';
            else if(matrix[i][j]==1) cout<<1<<' ';
            else cout<<2<<' ';
        }
        cout<<endl;
    }
    return 0;
}