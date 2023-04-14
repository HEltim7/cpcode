#include<iostream>
using namespace std;

#define endl '\n'

const int N=1e3+10;

int n,m;
string s[N];
string aim;
int step;

void getdp(){
    int ans=0;
    for(int k=1;k<=n;k++){
        int dp[11][11];
        int len1=s[k].size(),len2=aim.size();
        dp[0][0]=0;
        for(int j=1;j<=len1;j++) dp[j][0]=j;
        for(int j=1;j<=len2;j++) dp[0][j]=j;

        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
                dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+(s[k][i-1]!=aim[j-1]?1:0));

        if(dp[len1][len2]<=step) ans++;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=m;i++){
        cin>>aim>>step;
        getdp();
    }
    return 0;
}