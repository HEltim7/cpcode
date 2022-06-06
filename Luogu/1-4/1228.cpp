#include<iostream>
using namespace std;
char matrix[10][10];

void output(){
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"--------"<<endl;
}

int main(){
    for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) matrix[i][j]='0';
    matrix[3][3]='*';
    output();
    int row,col,c;
    while(cin>>row>>col>>c){
        matrix[row][col]='+';
        if(c==1){
            matrix[row-1][col]='+';
            matrix[row][col-1]='+';
        }
        else if(c==2){
            matrix[row-1][col]='+';
            matrix[row][col+1]='+';
        }
        else if(c==3){
            matrix[row][col-1]='+';
            matrix[row+1][col]='+';
        }
        else{
            matrix[row+1][col]='+';
            matrix[row][col+1]='+';
        }
        output();
    }
}