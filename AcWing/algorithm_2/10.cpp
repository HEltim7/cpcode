#include<iostream>
using namespace std;

const int N=110;
int dp[N][N];//在i子树中选择，总体积不超过j的最大值
int n,v;
int vol[N],val[N];
bool matrix[N][N];

void dfsdp(int node){
    //分组背包
    for(int i=1;i<=n;i++){
        if(!matrix[node][i]) continue;
        int son=i;//子树
        dfsdp(son);
        for(int j=v-vol[node];j>0;j--){
            for(int k=1;k<=j;k++){
                dp[node][j]=max(dp[node][j],dp[node][j-k]+dp[son][k]);
            }
        }
    }

    for(int i=v;i>=vol[node];i--) dp[node][i]=dp[node][i-vol[node]]+val[node];//全部加上根节点
    for(int i=1;i<vol[node];i++) dp[node][i]=0;//砍掉没加上根节点的数
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>v;
    int root,fa;
    for(int i=1;i<=n;i++){
        cin>>vol[i]>>val[i]>>fa;
        if(fa==-1) root=i;
        else matrix[fa][i]=1;
    }
    dfsdp(root);

    cout<<dp[root][v];
    return 0;
}