#include<iostream>
using namespace std;
#define endl '\n'

const int N=33;
int dp[N][N];//[l-r]区间的最小值
int sol[N][N];//[l-r]区间的根节点
int tree[N];

void dfs(int l,int r){
    if(l>r) return;
    int root=sol[l][r];
    cout<<root<<' ';
    dfs(l,root-1);
    dfs(root+1,r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>tree[i];

    for(int i=1;i<=n;i++) dp[i][i]=tree[i],sol[i][i]=i;
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            for(int k=l;k<=r;k++){//枚举根节点
                int ltree=1,rtree=1;
                if(k!=l) ltree=dp[l][k-1];
                if(k!=r) rtree=dp[k+1][r];
                if(ltree*rtree+tree[k]>dp[l][r]){
                    dp[l][r]=ltree*rtree+tree[k];
                    sol[l][r]=k;
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    dfs(1,n);
    return 0;
}