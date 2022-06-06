#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int,int> PII;

const int N=110,M=12;
int dp[2][1<<10][1<<10];//状态为j，上一层状态为k的状态数
vector<int> isok;//可行状态
vector<PII> last[1<<10];//上两层可行状态
int g[N];
int cnt[1<<10];

bool check(int x){
    if(x&x>>1) return false;
    if(x&x>>2) return false;
    return  true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    char in;
    for(int i=1;i<=n;i++) for(int j=m-1;j>=0;j--) if(cin>>in&&in=='H') g[i]+=1<<j;
    for(int i=0;i<1<<m;i++){
        if(check(i)) isok.push_back(i);//预处理可行状态
        for(int j=0;j<=9;j++) if(i>>j&1) cnt[i]++;
    }
    for(int i:isok) for(int j:isok) for(int k:isok)
        if((i&j)==0&&(i&k)==0&&(j&k)==0)
            last[i].push_back({j,k});
    
    for(int i=1;i<=n;i++){
        for(int j:isok){
            if(j&g[i]) continue;
            for(PII k:last[j]){
                if(k.first&g[i-1]||k.second&g[i-2]&&i>1) continue;
                    dp[i%2][j][k.first]=max(dp[i%2][j][k.first],dp[(i+1)%2][k.first][k.second]+cnt[j]);
            }
        }
    }
    int ans=0;
    for(int i:isok) for(PII j:last[i]) ans=max(ans,dp[n%2][i][j.first]);
    cout<<ans;
    return 0;
}