#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=2000+10;
int dp[N][2],idx[N][2],num[N];
int pos[N];
vector<int> mul[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        pos[in]=i;
    }
    for(int i=1;i<=n;i++){
        int tmp=0;
        while(tmp+num[i]<=n) 
            tmp+=num[i],mul[i].push_back(pos[tmp]);
        sort(mul[i].begin(),mul[i].end());
    }

    for(int i=1;i<=n;i++){
        dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
        if(dp[i-1][1]>dp[i-1][0]) idx[i][0]=idx[i-1][1];
        else if(dp[i-1][1]<dp[i-1][0]) idx[i][0]=idx[i-1][0];
        else idx[i][0]=min(idx[i-1][1],idx[i-1][0]);

        idx[i][1]=N;
        for(int j=0;j<=1;j++){
            int loc=idx[i-1][j];
            loc=upper_bound(mul[i].begin(),mul[i].end(),loc)-mul[i].begin();
            if(loc<mul[i].size()){
                if(dp[i][1]<dp[i-1][j]+1) dp[i][1]=dp[i-1][j]+1,idx[i][1]=loc;
                else if(dp[i][1]==dp[i-1][j]+1) idx[i][1]=min(idx[i][1],loc);
            }
        }
    }
    cout<<max(dp[n][0],dp[n][1]);
    return 0;
}
/////////////////////