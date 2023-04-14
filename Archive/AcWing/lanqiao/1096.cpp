#include<iostream>
#include<queue>
using namespace std;
const int N=102;
char dungeon[N][N][N];
int r,c,h;
int mh[7]={0,1,-1};
int mr[7]={0,0,0,1,-1};
int mc[7]={0,0,0,0,0,1,-1};
struct qnode{
    int high;
    int row;
    int col;
    int step;
} tmp;
queue <qnode> q;
bool esc;

bool check(int high,int row,int col){
    if(high>=1&&high<=h&&row>=1&&row<=r&&col>=1&&col<=c&&dungeon[high][row][col]!='#') return 1;
    return 0;
}

void bfs(){
    if(q.empty()||esc) return;
    tmp=q.front();
    for(int i=1;i<=6;i++){
        tmp.high+=mh[i];
        tmp.row+=mr[i];
        tmp.col+=mc[i];
        if(check(tmp.high,tmp.row,tmp.col)){
            tmp.step++;
            if(dungeon[tmp.high][tmp.row][tmp.col]=='E'){
                cout<<"Escaped in "<<tmp.step<<" minute(s)."<<'\n';
                esc=1;
                while (!q.empty()) q.pop();
                return;
            }
            q.push(tmp);
            dungeon[tmp.high][tmp.row][tmp.col]='#';
        }
        tmp=q.front();
    }
    q.pop();
    bfs();
    return;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while(cin>>h>>r>>c&&(r||c||h)){
        esc=0;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=r;j++){
                for(int k=1;k<=c;k++){
                    cin>>dungeon[i][j][k];
                    if(dungeon[i][j][k]=='S'){
                        tmp.high=i,tmp.row=j,tmp.col=k,tmp.step=0;
                        q.push(tmp);
                        dungeon[i][j][k]='#';
                    }
                }
            }
        }
        bfs();
        if(!esc) cout<<"Trapped!"<<'\n';
    }
    return 0;
}