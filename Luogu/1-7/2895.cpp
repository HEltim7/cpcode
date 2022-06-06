#include<iostream>
#include<cstring>
using namespace std;
const int N=310;
const int M=5e4+10;
int safe[N][N];
int minstep[N][N];
struct q_node{
    int row;
    int col;
    int t;
} q[N*N];
int qhead,qtail=-1;
bool flag;

bool check(int row,int col,int t){
    if(row>=1&&row<=300&&col>=1&&col<=300&&minstep[row][col]==-1&&(safe[row][col]>t||safe[row][col]==-1)) return 1;
    return 0;
}

void push(int row,int col,int t){
    qtail++;
    q[qtail].row=row;
    q[qtail].col=col;
    q[qtail].t=t;
}

void bfs(){
    if(qhead>qtail) return;
    q_node head=q[qhead];
    if(safe[head.row][head.col]==-1){
        cout<<head.t;
        flag=1;
        qhead=qtail+1;
        return;
    }
    if(check(head.row+1,head.col,head.t+1)){
        push(head.row+1,head.col,head.t+1);
        minstep[head.row+1][head.col]=head.t+1;
    }
    if(check(head.row,head.col+1,head.t+1)){
        push(head.row,head.col+1,head.t+1);
        minstep[head.row][head.col+1]=head.t+1;
    }
    if(check(head.row-1,head.col,head.t+1)){
        push(head.row-1,head.col,head.t+1);
        minstep[head.row-1][head.col]=head.t+1;
    }
    if(check(head.row,head.col-1,head.t+1)){
        push(head.row,head.col-1,head.t+1);
        minstep[head.row][head.col-1]=head.t+1;
    }
    qhead++;
    bfs();
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(minstep,-1,sizeof(minstep));
    for(int i=1;i<=300;i++) for(int j=1;j<=300;j++) safe[i][j]=-1;
    minstep[1][1]=0;
    int m,r,c,t;
    cin>>m;
    while(m--){
        cin>>r>>c>>t;
        c++,r++;
        if(safe[r][c]==-1) safe[r][c]=t;
        else safe[r][c]=min(safe[r][c],t);
        if(safe[r+1][c]==-1) safe[r+1][c]=t;
        else safe[r+1][c]=min(safe[r+1][c],t);
        if(safe[r-1][c]==-1) safe[r-1][c]=t;
        else safe[r-1][c]=min(safe[r-1][c],t);
        if(safe[r][c+1]==-1) safe[r][c+1]=t;
        else safe[r][c+1]=min(safe[r][c+1],t);
        if(safe[r][c-1]==-1) safe[r][c-1]=t;
        else safe[r][c-1]=min(safe[r][c-1],t);
    }
    push(1,1,0);
    bfs();
    if(flag==0) cout<<-1;
    return 0;
}