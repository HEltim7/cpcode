#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=1e2+10,INF=0x3f3f3f3f;
int dp[N][4][4][4];//最后一个为i,状态为i-2,i-1,i,插入空格的最小值

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    memset(dp,0x3f,sizeof dp);
    dp[0][0][0][0]=0;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        for(int x=0;x<=3;x++){
            for(int y=0;y<=3;y++){
                for(int z=0;z<=3;z++){
                    for(int k=0;k<=3;k++){
                        int d=INF;
                        if(c) d=min(d,k+2+y+z);
                        if(b) d=min(d,k+1+z);
                        if(a) d=min(d,k);
                        if(d>=3) dp[i][y][z][k]=
                            min(dp[i][y][z][k],dp[i-1][x][y][z]+k);
                    }
                }
            }
        }
    }
    int ans=INF;
    for(int x=0;x<=3;x++){
        for(int y=0;y<=3;y++){
            for(int z=0;z<=3;z++){
                ans=min(ans,dp[n][x][y][z]);
            }
        }
    }
    cout<<ans;
    return 0;
}