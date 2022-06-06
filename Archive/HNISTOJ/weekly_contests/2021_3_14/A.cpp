#include<iostream>
using namespace std;
const int N=210;
int m,n;
int matrix[N][N];

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0,j=0;j<=n+1;j++) matrix[i][j]=-1;
    for(int i=m+1,j=0;j<=n+1;j++) matrix[i][j]=-1;
    for(int i=0,j=0;i<=m+1;i++) matrix[i][j]=-1;
    for(int i=0,j=n+1;i<=m+1;i++) matrix[i][j]=-1;
    
    int row=1,col=1;
    if(matrix[row][col]!=-1){
        cout<<matrix[row][col];
        matrix[row][col]=-1;
    }
    if (matrix[2][1]==-1) col=2;
    else row=2;
    
    while(matrix[row][col]!=-1){
        while(matrix[row][col]!=-1){
            cout<<' '<<matrix[row][col];
            matrix[row][col]=-1;
            row++;
        }
        row--,col++;
        while(matrix[row][col]!=-1){
            cout<<' '<<matrix[row][col];
            matrix[row][col]=-1;
            col++;
        }
        col--,row--;
        while(matrix[row][col]!=-1){
            cout<<' '<<matrix[row][col];
            matrix[row][col]=-1;
            row--;
        }
        row++,col--;
        while(matrix[row][col]!=-1){
            cout<<' '<<matrix[row][col];
            matrix[row][col]=-1;
            col--;
        }
        col++,row++;
    }
    return 0;
}