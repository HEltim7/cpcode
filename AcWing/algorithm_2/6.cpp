#include<iostream>
using namespace std;

#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=1e3+10;
const int V=2e4+10;
int dp[N][V];
int que[V];
int v[N],w[N],s[N];
int n,vv;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>vv;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>s[i];

    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i];j++){//j枚举所有余数
            int h=1,t=0;//单调队列
            for(int k=j;k<=vv;k+=v[i]){
                //更新单调队列
                if(que[h]+s[i]*v[i]<k&&h<=t) h++;
                while(dp[i-1][k]>=dp[i-1][que[t]]+(k-que[t])/v[i]*w[i]&&h<=t) t--;
                que[++t]=k;
                dp[i][k]=dp[i-1][que[h]]+(k-que[h])/v[i]*w[i];
            }
        }
    }
    
    cout<<dp[n][vv];
    return 0;
}