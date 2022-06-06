#include<iostream>
using namespace std;
int s[5];
int cost[5][30];
int cost_sum[5];
int ans,i,now;

void dfs(int deep,int sum){
    if(deep>s[i]){
        now=min(now,max(cost_sum[i]-sum,sum));
        return;
    }
    dfs(deep+1,sum);
    dfs(deep+1,sum+cost[i][deep]);
}

int main(){
    for(int i=1;i<=4;i++) cin>>s[i];
    for(i=1;i<=4;i++){
        for(int j=1;j<=s[i];j++){
            cin>>cost[i][j];
            cost_sum[i]+=cost[i][j];
        }
        now=6000;
        dfs(1,0);
        ans+=now;
    }
    cout<<ans;
    return 0;
}