#include<iostream>
using namespace std;

const int N=5010;
int pfx[N];
int dp[N][N];
int res[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pfx[i],pfx[i]+=pfx[i-1];
    for(int i=1;i<=n;i++) res[i][i]=i;

    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            for(int k=res[l][r-1];k<=res[l+1][r];k++){
                if(!dp[l][r]||dp[l][r]>dp[l][k]+dp[k+1][r]+pfx[r]-pfx[l-1])
                    dp[l][r]=dp[l][k]+dp[k+1][r]+pfx[r]-pfx[l-1],
                    res[l][r]=k;
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}

/*
10
1 4 5 6 7 8 3 5 6 2
154
0 1 2 3 3 4 4 5 5 5 
0 0 2 3 3 4 4 5 5 5 
0 0 0 3 4 4 4 5 5 6 
0 0 0 0 4 5 5 5 6 6 
0 0 0 0 0 5 5 6 6 6 
0 0 0 0 0 0 6 6 6 6 
0 0 0 0 0 0 0 7 8 8 
0 0 0 0 0 0 0 0 8 8 
0 0 0 0 0 0 0 0 0 9 
0 0 0 0 0 0 0 0 0 0
row:l,col:r
*/