#include<iostream>
#include<vector>
using namespace std;

const int mod=1e8;
const int N=14;

int dp[N][1<<13];//选到i排，状态为j的方案数
int g[N];//标记土地是否肥沃
vector<int> isok;//可行状态
vector<int> last[1<<12];//每个状态的上一层可行状态
int n,m;

//上下两行分别不能有相邻的1
bool check(int x){
    return !(x&x>>1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int in;
    for(int i=1;i<=n;i++) for(int j=m-1;j>=0;j--) cin>>in,g[i]+=!in<<j;

    for(int i=0;i<1<<m;i++) if(check(i)) isok.push_back(i);
    for(int i:isok) for(int j:isok) if((i&j)==0) last[i].push_back(j);

    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int s:isok){
            if(s&g[i]) continue;
            for(int t:last[s]){
                if(t&g[i-1]) continue;
                dp[i][s]=(dp[i][s]+dp[i-1][t])%mod;
            }
        }
    int ans=0;
    for(int i:isok) ans=(ans+dp[n][i])%mod;
    cout<<ans;
    return 0;
}