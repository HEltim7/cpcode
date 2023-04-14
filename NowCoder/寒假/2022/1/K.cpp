#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=1e5+10;
int dp[N][3][3];//0绿1红2黑

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        char island;
        cin>>island;
        for(int x=0;x<=2;x++)
            for(int y=0;y<=2;y++){
                if(dp[i-1][x][y]==-1) continue;
                int color[]={0,0,0};
                if(i>=3) color[x]++;
                if(i>=2) color[y]++;
                for(int z=0;z<=2;z++){
                    color[z]++;
                    bool flag=0;
                    if(island=='G'&&color[0]>color[1]||
                        island=='R'&&color[0]<color[1]||
                        island=='B'&&color[0]==color[1])
                        flag=1;
                    else if(island=='X'){
                        dp[i][y][0]=max(dp[i][y][0],dp[i-1][x][y]+1);
                        dp[i][y][1]=max(dp[i][y][1],dp[i-1][x][y]);
                        dp[i][y][2]=max(dp[i][y][2],dp[i-1][x][y]);
                    }
                    if(flag&&z==0) 
                        dp[i][y][z]=max(dp[i][y][z],dp[i-1][x][y]+1);
                    else if(flag) dp[i][y][z]=max(dp[i][y][z],dp[i-1][x][y]);
                    color[z]--;
                }
            }
    }
    int ans=-1;
    for(int i=0;i<=2;i++)
        for(int j=0;j<=2;j++)
            ans=max(ans,dp[n][i][j]);
    cout<<ans;
    return 0;
}