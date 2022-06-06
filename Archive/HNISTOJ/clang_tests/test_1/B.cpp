#include<bits/stdc++.h>
using namespace std;

int main(){
    int row,column;
    cin>>row>>column;
    int matrix[row][column];
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]!=0){
                cout<<i<<' '<<j<<' '<<matrix[i][j]<<endl;
            }
        }
    }
    return 0;
}