#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=65;
LL dp[N][N][N][N];
int coin[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>coin[i];
    for(int i=1;i<=n;i++){
        //每个硬币只有两种决策：拿正和拿负(0)
        //多重背包
        //dp[i][j] i硬币，总和为j的最小代价
        //关键在于缩小j的范围
        //一个硬币的贡献不会超过后一个的单个面额
        //coin[i]=k*coin[i-1] k>1 ...
        //因为k严格大于1,所以每次至少倍增,因为最大值为1e9,所以N实际上只有30?
        //a[1]=1,a[2]=1e9 ?
    }
}