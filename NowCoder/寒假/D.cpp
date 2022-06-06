#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e6+10,INF=0x3f3f3f3f;

int val[1<<7];
int dp[30];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int ts;
    cin>>ts;
    while(ts--){
        memset(dp,0,sizeof dp);
        memset(val,0,sizeof val);
        int n,m,cnt=0;
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        dp[0]=INF;
        for(int i=0;i<t.size();i++)
            val[t[i]]=++cnt;
        for(int i=0;i<s.size();i++){
            int v=val[s[i]];
            if(dp[v-1]>dp[v]) dp[v]++;
        }
        cout<<dp[cnt]<<endl;
    }
    return 0;
}