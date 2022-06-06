#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=30;
int dp[N][N][N];
int matrix[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    int row,col;
    cin>>n;
    while(cin>>row>>col&&row&&col) cin>>matrix[row][col];

    for(int step=2;step<=2*n;step++){
        for(int i=1;i<=min(n,step-1);i++){
            for(int j=1;j<=min(n,step-1);j++){
                int p=step-i,q=step-j;
                int add=matrix[i][p];
                if(i!=j) add+=matrix[j][q];
                int &d=dp[step][i][j];
                d=max(d,dp[step-1][i-1][j-1]+add);
                d=max(d,dp[step-1][i-1][j]+add);
                d=max(d,dp[step-1][i][j-1]+add);
                d=max(d,dp[step-1][i][j]+add);
            }
        }
    }
    cout<<dp[2*n][n][n];
    return 0;
}