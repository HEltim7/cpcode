#include<iostream>
#include<cstring>
using namespace std;
const int N=210;
char matrix[N][N];
bool mark[N][N];
int n,r,c;
int sr,sc;
int qh,qt=-1;
int mr[5]={0,1,-1,0,0};
int mc[5]={0,0,0,1,-1};
struct qnode{
    int row;
    int col;
    int step;
} que[N*N],tmp;
bool isok;

bool empty(){
    return qh>qt;
}

void push(qnode in){
    que[++qt]=in;
}

bool check(int row,int col){
    return matrix[row][col]!='#'&&!mark[row][col]&&row<=r&&row>=1&&col<=c&&col>=1;
}

void bfs(){
    if(empty()) return;
    tmp=que[qh];
    if(matrix[tmp.row][tmp.col]=='E'){
        cout<<tmp.step<<endl;
        qh=0,qt=-1;
        isok=1;
        return;
    }
    for(int i=1;i<=5;i++){
        tmp.row+=mr[i];
        tmp.col+=mc[i];
        tmp.step++;
        if(check(tmp.row,tmp.col)){
            push(tmp);
            mark[tmp.row][tmp.col]=1;
        }
        tmp=que[qh];
    }
    qh++;
    bfs();
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    while(n--){
        cin>>r>>c;
        memset(mark,0,sizeof mark);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin>>matrix[i][j];
                if(matrix[i][j]=='S'){
                    sr=i,sc=j;
                    tmp.row=i,tmp.col=j,tmp.step=0;
                    push(tmp);
                    matrix[i][j]='.';
                }
            }
        }
        bfs();
        if(!isok) cout<<"oop!"<<endl;
        isok=0;
    }
    return 0;
}