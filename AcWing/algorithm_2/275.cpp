#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=110;
int matrix[N][N];
int dp[N][N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int row,col;
    cin>>row>>col;
    for(int i=1;i<=row;i++) for(int j=1;j<=col;j++) cin>>matrix[i][j];

    for(int step=2;step<=row+col;step++){
        for(int i=1;i<=min(row,step-1);i++){
            for(int j=1;j<=min(row,step-1);j++){
                if(i==j) continue;
                int p=step-i,q=step-j;
                int add=matrix[i][p]+matrix[j][q];
                int &d=dp[step][i][j];
                d=max(d,dp[step-1][i][j]+add);
                d=max(d,dp[step-1][i-1][j]+add);
                d=max(d,dp[step-1][i-1][j-1]+add);
                d=max(d,dp[step-1][i][j-1]+add);
            }
        }
    }
    
    cout<<max(dp[row+col-1][row-1][row],dp[row+col-1][row][row-1]);
    return 0;
}