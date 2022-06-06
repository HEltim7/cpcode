#include<iostream>
using namespace std;
int boom[110][110];

int main(){
    int row,col;
    cin>>row>>col;
    string matrix[110];
    for(int i=1;i<=row;i++){
        cin>>matrix[i];
        matrix[i]=' '+matrix[i];
    }
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(matrix[i][j]=='*'){
                boom[i-1][j]++;
                boom[i+1][j]++;
                boom[i][j+1]++;
                boom[i][j-1]++;
                boom[i-1][j+1]++;
                boom[i+1][j+1]++;
                boom[i-1][j-1]++;
                boom[i+1][j-1]++;
            }
        }
    }
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(matrix[i][j]!='*') cout<<boom[i][j];
            else cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}