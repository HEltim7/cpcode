#include<iostream>
using namespace std;
const int N=60;
char matrix[N][N];

bool isok(int r,int c){
    int a[5]={0,1,-1,0,0};
    int b[5]={0,0,0,1,-1};
    for(int i=1;i<=4;i++){
        if(matrix[r+a[i]][c+b[i]]=='W') return 0;
    }
    return 1;
}

int main(){
    int r,c;
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(matrix[i][j]=='P'){
                if(!isok(i,j)){
                    cout<<"No";
                    return 0;
                }
            } 
        }
    }
    cout<<"Yes";
    return 0;
}