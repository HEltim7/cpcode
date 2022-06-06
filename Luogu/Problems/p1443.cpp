#include<bits/stdc++.h>
using namespace std;
#define isok(i) gonext[i].column<=n&&gonext[i].column>=1&&gonext[i].row<=m&&gonext[i].row>=1&&!ispassed[gonext[i].row][gonext[i].column]
int m,n,x,y,a,b,matrix[500][500],ispassed[500][500];

struct QElement{//队列元素
    int y;
    int x;
    int step;
}tmp;
queue<QElement> q;

struct move{//马下一步
    int row;
    int column;
}gonext[9];

void gonextstep(QElement tmp){
    gonext[1].column=tmp.x-1;gonext[1].row=tmp.y-2;
    gonext[2].column=tmp.x-2;gonext[2].row=tmp.y-1;
    gonext[3].column=tmp.x-2;gonext[3].row=tmp.y+1;
    gonext[4].column=tmp.x-1;gonext[4].row=tmp.y+2;
    gonext[5].column=tmp.x+1;gonext[5].row=tmp.y+2;
    gonext[6].column=tmp.x+2;gonext[6].row=tmp.y+1;
    gonext[7].column=tmp.x+2;gonext[7].row=tmp.y-1;
    gonext[8].column=tmp.x+1;gonext[8].row=tmp.y-2;
}

void output(){//输出
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrix[i][j]==0&&!ispassed[i][j]) printf("%-5s","-1");
            else printf("%-5d",matrix[i][j]);
        }
        cout<<endl;
    }
}

void bfs(){
    if(q.empty()) {output();return;}//结束
    tmp=q.front();
    gonextstep(tmp);//顺时针计算下一步
    for(int i=1;i<=8;i++){//遍历每个点
        tmp.x=gonext[i].column;
        tmp.y=gonext[i].row;
        tmp.step++;
        if(isok(i)){//越界&重复判定
            q.push(tmp);//入列
            ispassed[gonext[i].row][gonext[i].column]=1;
            matrix[gonext[i].row][gonext[i].column]=tmp.step;
        }
        tmp=q.front();//重置，循环继续
    }
    q.pop();
    bfs();
}

int main(){
    cin>>n>>m>>a>>b;
    tmp.y=a;
    tmp.x=b;
    tmp.step=0;
    ispassed[a][b]=1;
    q.push(tmp);//加入第一个元素
    bfs();
    return 0;
}