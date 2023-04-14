#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VI;
typedef long long LL;

const int N=1510;
const int INF=0x3f3f3f3f;
int n;
VI tree[N];
int cost[N];
LL dp[N][3];//#1选 #2不选但有子树选 #3不选且无子树选

void dfs(int node,int root){
    dp[node][0]+=cost[node];
    LL minn=INF;
    for(int i:tree[node]){
        if(i==root) continue;
        dfs(i,node);
        dp[node][0]+=min(dp[i][0],min(dp[i][1],dp[i][2]));
        minn=min(minn,dp[i][0]-min(dp[i][0],dp[i][1]));
        dp[node][1]+=min(dp[i][0],dp[i][1]);
        dp[node][2]+=dp[i][1];
    }
    dp[node][1]+=minn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int id,m,r;
        cin>>id>>cost[id]>>m;
        while(m--){
            cin>>r;
            tree[id].push_back(r);
            tree[r].push_back(id);
        }
    }
    dfs(1,-1);
    cout<<min(dp[1][0],dp[1][1]);
    return 0;
}