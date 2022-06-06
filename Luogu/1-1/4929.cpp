#include<iostream>
using namespace std;
const int N=510;
int matrix[N][N];
int transfer[N][N];

void rotate(){
    int x,y,r,z;
    cin>>x>>y>>r>>z;
    if(z==0){
        for(int i=x-r,col=y+r;i<=x+r;i++,col--)
            for(int j=y-r,row=x-r;j<=y+r;j++,row++)
                transfer[row][col]=matrix[i][j];
        for(int i=x-r;i<=x+r;i++)
            for(int j=y-r;j<=y+r;j++)
                matrix[i][j]=transfer[i][j];
    }
    else{
        for(int i=x-r,col=y-r;i<=x+r;i++,col++)
            for(int j=y-r,row=x+r;j<=y+r;j++,row--)
                transfer[row][col]=matrix[i][j];
        for(int i=x-r;i<=x+r;i++)
            for(int j=y-r;j<=y+r;j++)
                matrix[i][j]=transfer[i][j];
    }
}

int main(){
    int siz,m,tmp=0;
    cin>>siz>>m;
    for(int i=1;i<=siz;i++)
        for(int j=1;j<=siz;j++)
            matrix[i][j]=++tmp;
    while(m--) rotate();
    for(int i=1;i<=siz;i++){
        for(int j=1;j<=siz;j++)
            cout<<matrix[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}