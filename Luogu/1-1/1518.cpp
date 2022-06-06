#include<iostream>
using namespace std;
char forest[20][20];
int passed[11][11][5][11][11][5];
int rowc,colc,rowf,colf;
int dirc=1,dirf=1;
int step;

void move(){
    if(dirc==1){
        if(forest[rowc-1][colc]=='.') rowc--;
        else dirc=2;
    }
    else if(dirc==2){
        if(forest[rowc][colc+1]=='.') colc++;
        else dirc=3;
    }
    else if(dirc==3){
        if(forest[rowc+1][colc]=='.') rowc++;
        else dirc=4;
    }
    else{
        if(forest[rowc][colc-1]=='.') colc--;
        else dirc=1;
    }

    if(dirf==1){
        if(forest[rowf-1][colf]=='.') rowf--;
        else dirf=2;
    }
    else if(dirf==2){
        if(forest[rowf][colf+1]=='.') colf++;
        else dirf=3;
    }
    else if(dirf==3){
        if(forest[rowf+1][colf]=='.') rowf++;
        else dirf=4;
    }
    else{
        if(forest[rowf][colf-1]=='.') colf--;
        else dirf=1;
    }
}

int main(){
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++){
            cin>>forest[i][j];
            if(forest[i][j]=='C') rowc=i,colc=j,forest[i][j]='.';
            if(forest[i][j]=='F') rowf=i,colf=j,forest[i][j]='.';
        }
    while(rowc!=rowf||colc!=colf){
        if(passed[rowc][colc][dirc][rowf][colf][dirf]==1){
            cout<<'0';
            return 0;
        }
        passed[rowc][colc][dirc][rowf][colf][dirf]=1;
        step++;
        move();
    }
    cout<<step;
    return 0;
}