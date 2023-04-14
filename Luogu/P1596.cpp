#include<iostream>
using namespace std;
const int N=110;
char matrix[N][N];
int sum;
int n,m;
struct q_data{
    int row;
    int col;
}q[N*N];
int h,t=-1;

void push(q_data in){
    q[++t]=in;
}

bool q_empty(){
    if(h>t) return 1;
    return 0;
}

bool check(int row,int col){
    if(row>=1&&row<=n&&col>=1&&col<=m&&matrix[row][col]=='W'){
        matrix[row][col]='.';
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
    if(check(tmp.row+1,tmp.col+1)){
        tmp.row++;
        tmp.col++;
        push(tmp);
        tmp=q[h];
    }
    if(check(tmp.row-1,tmp.col-1)){
        tmp.row--;
        tmp.col--;
        push(tmp);
        tmp=q[h];
    }
    if(check(tmp.row-1,tmp.col+1)){
        tmp.row--;
        tmp.col++;
        push(tmp);
        tmp=q[h];
    }
    if(check(tmp.row+1,tmp.col-1)){
        tmp.row++;
        tmp.col--;
        push(tmp);
        tmp=q[h];
    }
    h++;
    bfs();
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>matrix[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrix[i][j]=='W'){
                q_data tmp;
                tmp.row=i;
                tmp.col=j;
                push(tmp);
                bfs();
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}