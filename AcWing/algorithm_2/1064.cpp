#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

const int N=12;
ll dp[N][N*N][1<<10];//前i排已经选完，放了k个国王，且状态为s的方案数

vector<int> isok;//可行状态
vector<int> last[1<<10];//每个状态的上一层可行状态
int kings[1<<10];//每个状态king的数量

bool check(int x){
    return !(x&x>>1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    
    for(int i=0;i<=(1<<n)-1;i++){
        if(check(i)) isok.push_back(i);
        for(int j=0;j<n;j++) if(i>>j&1) kings[i]++;
    }
    for(int i:isok) for(int j:isok) if((i&j)==0&&check(i|j)) last[i].push_back(j);

    dp[0][0][0]=1;//入口
    for(int i=1;i<=n;i++)//枚举每一层
        for(int j=0;j<=k;j++)//枚举国王数量
            for(int s:isok)//枚举当前状态
                for(int t:last[s])//枚举上一层状态
                    if(j>=kings[s]+kings[t])
                        dp[i][j][s]+=dp[i-1][j-kings[s]][t];

    ll ans=0;
    for(int i:isok) ans+=dp[n][k][i];
    cout<<ans;
    return 0;
}