#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
const int N=410;
int n,m,r,c;
int step[N][N];
int qhead,qtail=-1;
struct q_node
{
    int row;
    int col;
    int nowstep;
} q[N*N];

bool qempty(){
    if(qhead>qtail) return 1;
    return 0;
}

void q_push(int row,int col,int nowstep){
    qtail++;
    q[qtail].row=row;
    q[qtail].col=col;
    q[qtail].nowstep=nowstep;
    step[row][col]=nowstep;
}

void bfs(){
    if(qempty()) return;
    for(int i=2;i>=-2;i-=4){
        for(int j=1;j>=-1;j-=2){
            if(step[q[qhead].row+i][q[qhead].col+j]<0&&q[qhead].row+i>=1&&q[qhead].row+i<=n&&q[qhead].col+j>=1&&q[qhead].col+j<=m){
                step[q[qhead].row+i][q[qhead].col+j]=q[qhead].nowstep;
                q_push(q[qhead].row+i,q[qhead].col+j,q[qhead].nowstep+1);
            }
        }
    }
    for(int i=2;i>=-2;i-=4){
        for(int j=1;j>=-1;j-=2){
            if(step[q[qhead].row+j][q[qhead].col+i]<0&&q[qhead].row+j>=1&&q[qhead].row+j<=n&&q[qhead].col+i>=1&&q[qhead].col+i<=m){
                step[q[qhead].row+j][q[qhead].col+i]=q[qhead].nowstep;
                q_push(q[qhead].row+j,q[qhead].col+i,q[qhead].nowstep+1);
            }
        }
    }
    qhead++;
    bfs();
}

int main(){
    memset(step,-1,sizeof(step));
    cin>>n>>m>>r>>c;
    qtail++;
    q[qtail].row=r;
    q[qtail].col=c;
    q[qtail].nowstep=0;
    step[r][c]=0;
    bfs();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<setiosflags(ios::left)<<setw(5)<<step[i][j];
        cout<<endl;
    }
    return 0;
}