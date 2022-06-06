#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;

int n,m,num[N];
int dp[N][11],cost[N][N];
int v[N],dist[N],l[N],r[N];
struct SEG
{
    int root;
    int tot_sum,tot_size;
    int tree_sum,tree_size;
    inline int cal(){
        int mid=v[root];
        return mid*tree_size-tree_sum+tot_sum-tree_sum-(tot_size-tree_size)*mid;
    }
};

int merge(int x,int y){
    if(!x||!y) return x+y;
    if(v[x]<v[y]) swap(x,y);
    r[x]=merge(r[x],y);
    if(dist[l[x]]<dist[r[x]]) swap(l[x],r[x]);
    dist[x]=dist[r[x]]+1;
    return x;
}

void get_cost(int x){
    vector<SEG> stk;
    int res=0;
    for(int i=x;i<=n;i++){
        SEG cur={i,v[i],1,v[i],1};
        l[i]=r[i]=0,dist[i]=1;
        while(stk.size()&&v[stk.back().root]>v[cur.root]){
            auto &pre=stk.back();
            res-=pre.cal();
            cur.root=merge(cur.root,pre.root);
            bool pop=cur.tot_size%2&&pre.tot_size%2;
            cur.tot_size+=pre.tot_size;
            cur.tot_sum+=pre.tot_sum;
            cur.tree_size+=pre.tree_size;
            cur.tree_sum+=pre.tree_sum;
            if(pop){
                cur.tree_size--;
                cur.tree_sum-=v[cur.root];
                cur.root=merge(l[cur.root],r[cur.root]);
            }
            stk.pop_back();
        }
        stk.push_back(cur);
        res+=cur.cal();
        cost[x][i]=min(cost[x][i],res);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(cost,0x3f,sizeof cost);
    memset(dp,0x3f,sizeof dp);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++) v[i]=num[i]-i;
    for(int i=1;i<=n;i++) get_cost(i);
    for(int i=1;i<=n;i++) v[i]=-num[i]-i;
    for(int i=1;i<=n;i++) get_cost(i);

    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=i;k++)
                dp[i][j]=min(dp[i][j],dp[i-k][j-1]+cost[i-k+1][i]);
    cout<<dp[n][m];
    return 0;
}