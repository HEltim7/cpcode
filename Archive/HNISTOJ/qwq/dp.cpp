#include<iostream>
using namespace std;

typedef long long LL;
const LL mod=555555555;
const int N=1510;
int n,m,p,q,t;
int dp[N][N];//对i行进行操作，j列进行操作，且没有冗余操作的t的值。
LL ans;
LL cmb[N][N];//i中选j个的组合数

void getcmb(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(j==0) cmb[i][j]=1;
            else cmb[i][j]=(cmb[i-1][j]+cmb[i-1][j-1])%mod;
        }
    }
}

inline void add(int i,int j){
    //操作两次=没有操作
    //将冗余的操作两两一组放置
    LL row=0,col=0;//行和列的方案数
    for(int k=1;k<=n;k++) if(p-i>=2) row=(row+cmb[n][k]*cmb[(p-i)/2-1][k-1]%mod)%mod;
    for(int k=1;k<=m;k++) if(q-j>=2) col=(col+cmb[m][k]*cmb[(q-j)/2-1][k-1]%mod)%mod;
    if(row==0) row=1;
    if(col==0) col=1;
    row=row*cmb[n][i]%mod;
    col=col*cmb[m][j]%mod;
    ans=(ans+row*col%mod)%mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    getcmb();
    cin>>n>>m>>p>>q>>t;
    for(int i=0;i<=p;i++)
        for(int j=0;j<=q;j++){
            if(i==0&&j==0) continue;
            if(j==0) dp[i][j]=m*i;
            else dp[i][j]=dp[i][j-1]+n-2*i;
        }

    for(int i=0;i<=p;i++)
        for(int j=0;j<=q;j++)
            if((p-i)%2==0&&(q-j)%2==0&&dp[i][j]==t)
                add(i,j);

    cout<<ans;
    return 0;
}
/*
2 2 1 1 2

5 5 2 2 0

1000 1000 1000 1 999000
*/