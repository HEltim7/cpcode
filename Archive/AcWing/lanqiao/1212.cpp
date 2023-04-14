//开int一定不要超过两个数相加！！debug数小时的惨痛教训

#include<iostream>
using namespace std;
const int N=55;
const int MOD=1000000007;
int matrix[N][N];
int way[N][N][14][14];
int none[N][N];
int ans;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>matrix[i][j];
    none[1][1]=1;
    way[1][1][1][matrix[1][1]]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1) continue;
            none[i][j]=(none[i-1][j]+none[i][j-1])%MOD;
            for(int x=1;x<=k;x++){
                for(int y=0;y<=12;y++){
                    way[i][j][x][y]=(way[i][j][x][y]+way[i-1][j][x][y])%MOD;
                    way[i][j][x][y]=(way[i][j][x][y]+way[i][j-1][x][y])%MOD;
                }
                if(x==1){
                    way[i][j][x][matrix[i][j]]=(way[i][j][x][matrix[i][j]]+none[i-1][j])%MOD;
                    way[i][j][x][matrix[i][j]]=(way[i][j][x][matrix[i][j]]+none[i][j-1])%MOD;
                }
                
                for(int y=0;y<matrix[i][j]&&x>=2;y++){
                    if(way[i-1][j][x-1][y]) way[i][j][x][matrix[i][j]]=(way[i][j][x][matrix[i][j]]+way[i-1][j][x-1][y])%MOD;
                    if(way[i][j-1][x-1][y]) way[i][j][x][matrix[i][j]]=(way[i][j][x][matrix[i][j]]+way[i][j-1][x-1][y])%MOD;
                }
            }
        }
    }
    for(int i=0;i<=12;i++){
        ans=(ans+way[n][m][k][i])%MOD;
    }
    cout<<ans;
    return 0;
}