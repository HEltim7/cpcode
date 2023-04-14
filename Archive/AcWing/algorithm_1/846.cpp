#include<iostream>
using namespace std;
const int N=1e5+10,M=N*2;
int head[N],elem[M],nexe[M],idx;
bool mark[N];
int ans=N,n;

void add(int a,int b){
    elem[idx]=b;
    nexe[idx]=head[a];
    head[a]=idx++;
}
 
/*
	head存储所有的头节点，elem储存下标idx对应的值，nexe储存下一个节点的下标
	mark记录当前节点有没有被搜索过
	ans储存答案
*/

int dfs(int now){ //dfs搜索now节点下总共的节点数量（包括自身
    mark[now]=1;
    int sum=1,res=0; //sum记录节点数，res记录当now被挖掉时的最大连通块
    for(int i=head[now];i!=-1;i=nexe[i]){ //尝试遍历该节点下的每一个子节点
        int j=elem[i];
        if(!mark[j]){
            int nextres=dfs(j); //记录下一个节点的节点数
            res=max(res,nextres); //求最大连同块（因为父节点now被挖掉了所以不是相加
            sum+=nextres; //加上这个节点
        }
    }
    res=max(res,n-sum); //全树挖掉now之后的最大连通块=max(重心下的max，重心上的节点数)
    ans=min(ans,res); //最大值的最小值
    return sum;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    fill(head,head+N,-1);
    int a,b;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<<ans;
    return 0;
}