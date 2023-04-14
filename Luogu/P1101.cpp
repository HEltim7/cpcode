#include<iostream>
#include<cmath>
using namespace std;
string base="yizhong";
string rbase="gnohziy";
char matrix[110][110];
bool mark[110][110];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int now=0;
        for(int j=1;j<=n;j++){
            if(matrix[i][j]==base[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[i][j-k]=1;
                now=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int now=0;
        for(int j=1;j<=n;j++){
            if(matrix[i][j]==rbase[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[i][j-k]=1;
                now=0;
            }
        }
    }
    ////////////////////////////
    for(int i=1;i<=n;i++){
        int now=0;
        for(int j=1;j<=n;j++){
            if(matrix[j][i]==base[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[j-k][i]=1;
                now=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int now=0;
        for(int j=1;j<=n;j++){
            if(matrix[j][i]==rbase[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[j-k][i]=1;
                now=0;
            }
        }
    }
    ////////////////////////////
    for(int k=0;k<=n-1;k++){
        int now=0;
        for(int i=1,j=1+k;i<=n&&j<=n;i++,j++){
            if(matrix[i][j]==base[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[i-k][j-k]=1;
                now=0;
            }
        }
    }
    for(int k=1;k<=n-1;k++){
        int now=0;
        for(int i=1+k,j=1;i<=n&&j<=n;i++,j++){
            if(matrix[i][j]==base[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[i-k][j-k]=1;
                now=0;
            }
        }
    }
    for(int k=0;k<=n-1;k++){
        int now=0;
        for(int i=1,j=1+k;i<=n&&j<=n;i++,j++){
            if(matrix[i][j]==rbase[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[i-k][j-k]=1;
                now=0;
            }
        }
    }
    for(int k=1;k<=n-1;k++){
        int now=0;
        for(int i=1+k,j=1;i<=n&&j<=n;i++,j++){
            if(matrix[i][j]==rbase[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[i-k][j-k]=1;
                now=0;
            }
        }
    }
    ////////////////////////////
    for(int k=0;k<=n-1;k++){
        int now=0;
        for(int i=1+k,j=1;i<=n&&i>=1&&j<=n&&j>=1;i--,j++){
            if(matrix[i][j]==base[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[i+k][j-k]=1;
                now=0;
            }
        }
    }
    for(int k=0;k<=n-1;k++){
        int now=0;
        for(int i=n,j=1+k;i<=n&&i>=1&&j<=n&&j>=1;i--,j++){
            if(matrix[i][j]==base[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[i+k][j-k]=1;
                now=0;
            }
        }
    }
    for(int k=0;k<=n-1;k++){
        int now=0;
        for(int i=1+k,j=1;i<=n&&i>=1&&j<=n&&j>=1;i--,j++){
            if(matrix[i][j]==rbase[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[i+k][j-k]=1;
                now=0;
            }
        }
    }
    for(int k=0;k<=n-1;k++){
        int now=0;
        for(int i=n,j=1+k;i<=n&&i>=1&&j<=n&&j>=1;i--,j++){
            if(matrix[i][j]==rbase[now]) now++;
            else now=0;
            if(now==7){
                for(int k=6;k>=0;k--) mark[i+k][j-k]=1;
                now=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mark[i][j]) cout<<matrix[i][j];
            else cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}