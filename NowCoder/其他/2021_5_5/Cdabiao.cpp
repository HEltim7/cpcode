#include<iostream>
using namespace std;


const int N=501000;
int way[2][N+1];

void fn(int x1,int x2){
    int res=x1*(x1+1)+x2*(x2+1);
    if(res>0) way[1][res]++;
    else way[0][-res]++;
}

int main(){
    for(int i=-500;i<=500;i++){
        for(int j=-500;j<=500;j++){
            fn(i,j);
        }
    }
    for(int i=0;i<=N;i++){
        if(way[0][i]) cout<<i<<' '<<way[0][i]<<endl;
    }
    for(int i=0;i<=N;i++){
        if(way[1][i]) cout<<i<<' '<<way[1][i]<<endl;
    }
    return 0;
}