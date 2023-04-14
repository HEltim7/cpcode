#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef pair<int,int> pii;

const int N=3210;//全部是10的倍数，全部除10
const int M=70;
int dp[M][N];//从前i组物品选，总花费不超过j的最大价值

int primary[M];
int cnt;
vector<pii> group[M];//物品组
vector<pii> cmb[M];//物品组合组

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    n/=10;
    for(int i=1;i<=m;i++){
        int q;
        pii read;//体积/价值
        cin>>read.first>>read.second>>q;
        if(q==0) primary[i]=++cnt;

        read.second*=read.first;
        read.first/=10;
        group[primary[q]].push_back(read);
    }

    //打包物品
    int i=1;
    for(auto x:group[0]){
        if(group[i].size()==0) cmb[i].push_back(x);
        else if(group[i].size()==1){
            cmb[i].push_back(x);
            pii tmp=group[i].front();
            tmp.first+=x.first,tmp.second+=x.second;
            cmb[i].push_back(tmp);
        }
        else{
            cmb[i].push_back(x);
            pii tmp1=group[i][0];
            pii tmp2=group[i][1];
            cmb[i].push_back({tmp1.first+x.first,tmp1.second+x.second});
            cmb[i].push_back({tmp2.first+x.first,tmp2.second+x.second});
            cmb[i].push_back({tmp1.first+tmp2.first+x.first,tmp1.second+tmp2.second+x.second});
        }
        i++;
    }

    //分组背包dp
    int g=group[0].size();
    for(int i=1;i<=g;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            for(auto x:cmb[i])
                if(j>=x.first)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-x.first]+x.second);
        }
    }

    cout<<dp[g][n]<<endl;
    return 0;
}