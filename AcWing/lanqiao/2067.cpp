#include<iostream>
using namespace std;
int r,c,row,col;
typedef unsigned long  long  ull;
ull step[20][20];

int main(){
    cin>>r>>c;
    row=(r+1)/2,col=(c+1)/2;
    if(r%2==0&&c%2==0){
        cout<<0;
        return 0;
    }
    step[1][0]=1;
    for(int i=1;i<=16;i++){
        for(int j=1;j<=16;j++){
            step[i][j]=step[i-1][j]+step[i][j-1];
        }
    }
    cout<<step[row][col];
    return 0;
}