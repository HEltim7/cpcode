#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1010;
int dp[N][N];
int v[N],w[N];//体积&价值
int ans[N];//储存方案
int id[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,vv;
    cin>>n>>vv;
    //逆序输入，使字典序最小
    for(int i=n;i>=1;i--) cin>>v[i]>>w[i],id[i]=n-i+1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=vv;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=v[i]) dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
        }
    }

    int idx=0;
    int volume=vv;//容积
    for(int i=n;i>=1;i--){//从最后向前推
        if(volume>=v[i]&&dp[i][volume]==dp[i-1][volume-v[i]]+w[i]){
            ans[++idx]=id[i];
            volume-=v[i];
        }
    }

    for(int i=1;i<=idx;i++) cout<<ans[i]<<' ';
    return 0;
}