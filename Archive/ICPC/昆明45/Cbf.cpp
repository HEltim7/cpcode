#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=500,INF=0x3f3f3f3f;
int dp[N][N][N],pre[N][N],arr[N];//dp[i][j][k]=i长度，j开始，k颜色

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++)
        for(int j=1;i+j-1<=n;j++)
            for(int k=1;k<=n;k++)
                ;
        
}