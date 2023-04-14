#include<iostream>
#include<vector>
using namespace std;

const int N=110;

typedef pair<int,int> PII;
typedef vector<int> VI;
VI tree[N];
VI val[N];
int n,v;
int dp[N][N];//在i子树中选，体积不超过j的最大值

void dfs(int id,int root){
    int son,w;
    for(int i=0;i<tree[id].size();i++){//遍历所有物品组
        son=tree[id][i],w=val[id][i];
        if(son==root) continue;
        dfs(son,id);
        for(int j=v;j>=1;j--){//遍历所有体积
            for(int k=0;k<j;k++){//遍历所有子树体积
                dp[id][j]=max(dp[id][j],dp[id][j-k-1]+dp[son][k]+w);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>v;
    for(int i=1;i<n;i++){
        int n1,n2,s;
        cin>>n1>>n2>>s;
        tree[n1].push_back(n2),tree[n2].push_back(n1);
        val[n1].push_back(s),val[n2].push_back(s);
    }
    dfs(1,-1);
    cout<<dp[1][v];
    return 0;
}