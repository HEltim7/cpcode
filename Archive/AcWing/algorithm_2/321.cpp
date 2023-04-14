#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const int N=15,M=10;
const int INF=0x3f3f3f3f;
int m=8,n;
int matrix[M][M];
int dp[M][M][M][M][N];//在一个区块内切了k刀的方案集合
int prefix[M][M];//二维前缀和
double x_;//平均数

//求一个区块中数值的和的平方
int chunk_sum(int r1,int c1,int r2,int c2){
    int res=prefix[r2][c2]-prefix[r1-1][c2]-prefix[r2][c1-1]+prefix[r1-1][c1-1];
    return res*res;
}

//记忆化搜索一个区块切k刀的解
int dfs(int r1,int c1,int r2,int c2,int k){
    int &d=dp[r1][c1][r2][c2][k];
    if(d==0) d=INF;
    else return d;
    
    if(k==0) return d=chunk_sum(r1,c1,r2,c2);

    for(int i=r1+1;i<=r2;i++){
        //向下搜索
        d=min(d,dfs(i,c1,r2,c2,k-1)+chunk_sum(r1,c1,i-1,c2));
        //向上搜索
        d=min(d,dfs(r1,c1,i-1,c2,k-1)+chunk_sum(i,c1,r2,c2));
    }
    for(int i=c1+1;i<=c2;i++){
        //向右搜索
        d=min(d,dfs(r1,i,r2,c2,k-1)+chunk_sum(r1,c1,r2,i-1));
        //向左搜索
        d=min(d,dfs(r1,c1,r2,i-1,k-1)+chunk_sum(r1,i,r2,c2));
    }
    return d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=m;i++) for(int j=1;j<=m;j++){
        cin>>matrix[i][j];
        prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+matrix[i][j];
    }
    x_=prefix[m][m]*1./n;
    double ans=dfs(1,1,m,m,n-1);
    ans=sqrt(ans/n-pow(x_,2));
    cout<<fixed<<setprecision(3)<<ans;
    return 0;
}