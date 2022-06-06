#include<iostream>
using namespace std;

const int N=1e3+10,M=510,K=110;
int n,m,k;
int dp[N][M];//从前i个物品选，消耗精灵球数量小于等于j,消耗皮卡丘血量小于等于l的精灵数

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int v1,v2;
        cin>>v1>>v2;
        for(int j=n;j>=v1;j--){
            for(int l=m;l>=v2;l--){
                dp[j][l]=max(dp[j][l],dp[j-v1][l-v2]+1);
            }
        }
    }
    int r=0,c=0;
    for(int i=m-1;i>=0;i--) if(dp[n][i]>=r) r=dp[n][i],c=i;
    cout<<r<<' '<<m-c;
    return 0;
}