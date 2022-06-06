#include<iostream>
using namespace std;
int matrix[110][110];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int r,c;
        cin>>r>>c;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                scanf("%d",&matrix[i][j]);
        for(int i=2,j=2;i<=r||j<=c;i++,j++){
            int row,col;
            for(row=i,col=1;col<j&&row<=r;col++){
                matrix[row][col]+=max(matrix[row][col-1],matrix[row-1][col]);
            }
            for(col=j,row=1;row<i&&col<=c;row++){
                matrix[row][col]+=max(matrix[row][col-1],matrix[row-1][col]);
            }
            if(i<=r&&j<=c) matrix[i][j]+=max(matrix[i-1][j],matrix[i][j-1]);
        }
        cout<<matrix[r][c]<<endl;
    }
    return 0;
}