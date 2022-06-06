#include<iostream>
using namespace std;
int m,n,c,x[110],item[110][110];
//每层算出值,均值,贪心

typedef struct{
    int value;
    double AvgValue;
    int step;
} tab;

tab data[110][110]; 

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        item[i][0]=0;
        for(int j=1;j<=x[i];j++){
            cin>>data[i][j].value;
        }
        for(int k=1;k<m;k++){
            for(int l=0;l<=m;l++){
                int tmp;
                tmp+=data[i][k].value;
            }
            
        }
    }
    
    return 0;
}