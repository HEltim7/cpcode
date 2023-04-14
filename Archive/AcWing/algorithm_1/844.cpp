#include<iostream>
#include<queue>
using namespace std;

const int N=110;
bool matrix[N][N];
int n,m;
int mover[5]={0,1,-1,0,0};
int movec[5]={0,0,0,1,-1};

struct node{
    int row;
    int col;
    int step;
} qnode;

queue<node> q;

bool check(int row,int col){
    if(row>n||row<1||col>m||col<1||matrix[row][col]) return 0;
    return 1;
}

void bfs(){
    if(q.empty()) return;
    qnode=q.front();
    if(qnode.row==n&&qnode.col==m){
        cout<<qnode.step;
        while(!q.empty()) q.pop();
        return;
    }
    for(int i=1;i<=4;i++){
        qnode=q.front();
        qnode.row+=mover[i];
        qnode.col+=movec[i];
        qnode.step++;
        if(check(qnode.row,qnode.col)){
            q.push(qnode);
            matrix[qnode.row][qnode.col]=1;
        }
    }
    q.pop();
    bfs();
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>matrix[i][j];
    qnode.row=1,qnode.col=1,qnode.step=0;
    q.push(qnode);
    bfs();
    return 0;
}