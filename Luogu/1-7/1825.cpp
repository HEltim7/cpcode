#include<iostream>
using namespace std;
const int N=310;
int n,m;
struct m_data{
    char aera;
    bool passed;
} matrix[N][N];
struct t_data{
    int r1;
    int c1;
    int r2;
    int c2;
} trans[30];
struct node{
    int row;
    int col;
    int step;
} q[N*N];
int h,t=-1;

bool empty(){
    if(h>t) return 1;
    return 0;
}

bool check(int row,int col){
    if(row>=1&&row<=n&&col>=1&&col<=m&&matrix[row][col].aera!='#'&&!matrix[row][col].passed) return 1;
    return 0;
}

bool istrans(int i,int j){
    if(matrix[i][j].aera>='A'&&matrix[i][j].aera<='Z') return 1;
    return 0;
}

void push(node in){
    q[++t]=in;
    matrix[in.row][in.col].passed=1;    
}

void pop() {h++;}

void next(node in){
    node tmp=in;
    if(istrans(tmp.row,tmp.col)){
        int alpha=matrix[tmp.row][tmp.col].aera-'A'+1;
        if(trans[alpha].r1==tmp.row&&trans[alpha].c1==tmp.col){
            tmp.row=trans[alpha].r2;
            tmp.col=trans[alpha].c2;
        }
        else{
            tmp.row=trans[alpha].r1;
            tmp.col=trans[alpha].c1;
        }
    }
    if(check(tmp.row,tmp.col)){
        tmp.step++;
        push(tmp);
    }
}

void bfs(){
    if(empty()) return;
    node tmp=q[h];
    if(matrix[tmp.row][tmp.col].aera=='='){
        h=t+1;
        cout<<tmp.step;
        return;
    }
    tmp.row++;
    next(tmp);
    tmp=q[h];

    tmp.row--;
    next(tmp);
    tmp=q[h];
    
    tmp.col++;
    next(tmp);
    tmp=q[h];
    
    tmp.col--;
    next(tmp);
    
    pop();
    bfs();
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j].aera;
            if(matrix[i][j].aera=='@'){
                matrix[i][j].aera='.';
                node cow;
                cow.row=i;
                cow.col=j;
                cow.step=0;
                push(cow);
            }
            if(istrans(i,j)){
                int alpha=matrix[i][j].aera-'A'+1;
                if(trans[alpha].r1){
                    trans[alpha].r2=i;
                    trans[alpha].c2=j;
                }
                else{
                    trans[alpha].r1=i;
                    trans[alpha].c1=j;
                }
            }
        }
    }
    bfs();
    return 0;
}