#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int N=2e3+10,M=4e6+10;
VI zero={1,2,3,5,6,7,8,9,10};
VI dp[N][N];
PII cmd[N];
set<PII> st;
int n,m;
LL w[]={1e10,1e9,1e8,1e7,1e6,1e5,1e4,1e3,1e2,1e1,1};

LL compress(VI x){
    LL res=0;
    for(int i=0,j=0;i<10;i++){
        if(x[i]!=10) res+=x[i]*w[i+j];
        else res+=w[i]+w[i+1],j++;
    }
    return res;
}

//从后往前做
//dp[i][j]表示[i][j]的一段
void getdp(){
    for(int i=n;i>=1;i--){
        dp[i][i]=zero;
        swap(dp[i][i][cmd[i].first],dp[i][i][cmd[i].second]);
        for(int j=n-1;j>=1;j--){
            dp[i][j]=dp[i+1][j];
            
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>cmd[i].first>>cmd[i].second;
    getdp();
    for(int i=1;i<=m;i++){
        VI aim=VI(10,0);
        int k;
        cin>>k;
    }
}