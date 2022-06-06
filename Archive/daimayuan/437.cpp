#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
typedef pair<int,int> PII;
const int N=1e2+10,INF=0x3f3f3f3f;

int dp[N][N][N][2];//dp[i][j][k][x]=经过了i个点，但前为j,if x=0 k,if x=1
vector<PII> adj[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,K,m;
    cin>>n>>K>>m;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++) dp[1][i][i][1]=dp[1][i][i][0]=0;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[b].emplace_back(a,c);       
    }

    //枚举步数
    for(int i=1;i<K;i++){
        //枚举左右端点，逆向走
        for(int j=1;j<=n;j++){
            for(int k=j;k<=n;k++){
                //左侧
                for(auto [a,b]:adj[j]){
                    if(a>k) dp[i+1][j][a][1]=min(dp[i+1][j][a][1],dp[i][j][k][0]+b);
                    if(a<j) dp[i+1][a][k][0]=min(dp[i+1][a][k][0],dp[i][j][k][0]+b);
                }
                //右侧
                for(auto [a,b]:adj[k]){
                    if(a>k) dp[i+1][j][a][1]=min(dp[i+1][j][a][1],dp[i][j][k][1]+b);
                    if(a<j) dp[i+1][a][k][0]=min(dp[i+1][a][k][0],dp[i][j][k][1]+b);
                }
            }
        }
    }
    int ans=INF;
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) ans=min({ans,dp[K][i][j][0],dp[K][i][j][1]});
    cout<<(ans==INF?-1:ans);
    return 0;
}