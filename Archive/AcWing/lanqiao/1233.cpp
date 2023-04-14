#include<iostream>
using namespace std;
const int N=1e3+10;
char matrix[N][N];
bool mark[N][N];
int n,ans,sum;
int mr[5]={0,1,-1,0,0};
int mc[5]={0,0,0,1,-1};
bool flag;

bool check(int row,int col){
    for(int i=1;i<=4;i++){
        if(matrix[row+mr[i]][col+mc[i]]=='.') return 1;
    }
    flag=1;
    return 0;
}

bool able(int row,int col){
    if(matrix[row][col]=='#'&&!mark[row][col]&&row>=1&&row<=n&&col>=1&&col<=n) return 1;
    return 0;
}

void dfs(int row,int col){
    check(row,col);
    mark[row][col]=1;
    for(int i=1;i<=4;i++){
        int r=row+mr[i],c=col+mc[i];
        if(able(r,c)) dfs(r,c);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(matrix[i][j]=='#'&&!mark[i][j]){
                flag=0;
                dfs(i,j);
                sum++;
                if(flag) ans++;
            }
            else mark[i][j]=1;
        }
    }
    cout<<sum-ans;
    return 0;
}