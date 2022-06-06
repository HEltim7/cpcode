#include<iostream>
#include<queue>
using namespace std;
const int N=210;
char matrix[N][N];
int n,r,c;
int sr,sc;
int mr[5]={0,1,-1,0,0};
int mc[5]={0,0,0,1,-1};
struct qnode{
    int row;
    int col;
    int step;
} tmp;
queue <qnode> que;
bool isok;

void bfs(){
    if(que.empty()) return;
    tmp=que.front();
    if(matrix[tmp.row][tmp.col]=='E'){
        cout<<tmp.step<<endl;
        // make queue empty
        isok=1;
        return;
    }
    for(int i=1;i<=5;i++){
        tmp.row+=mr[i];
        tmp.col+=mc[i];
        tmp.step++;
        if(matrix[tmp.row][tmp.col]!='#') que.push(tmp);
        tmp=que.front();
    }
    que.pop();
    bfs();
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    while(n--){
        cin>>r>>c;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin>>matrix[i][j];
                if(matrix[i][j]=='S'){
                    sr=i,sc=j;
                    tmp.row=i,tmp.col=j,tmp.step=0;
                    que.push(tmp);
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