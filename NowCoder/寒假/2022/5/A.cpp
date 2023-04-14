#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=1e6+10;
const LL INF=1e18;
LL dp[4][N],pre[N];
LL n,k,w,q;

inline LL cal(LL a,LL b){
    assert(a<b);
    return w-abs(k+a-b)*q;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    vector<int> day;
    for(int i=1;i<=n;i++){
        char in;
        cin>>in;
        if(in=='1') dp[1][i]=-INF;
        else dp[1][i]=0,day.push_back(i);
    }

    cin>>k>>w>>q;
    if(day.empty()){
        cout<<0;
        return 0;
    }
    for(int i=0,j=1;i<day.size()&&j<=n;j++){
        dp[2][j]=dp[1][j];
        if(dp[2][j]==-INF) continue;
        if(day[i]>=j) continue;
        dp[2][j]=max(dp[2][j],dp[1][day[i]]+cal(day[i],j));
        while(i+1<day.size()&&day[i+1]<j&&
            dp[1][day[i]]+cal(day[i],j)<=dp[1][day[i+1]]+cal(day[i+1],j))
            dp[2][j]=max(dp[2][j],dp[1][day[i+1]]+cal(day[i+1],j)),i++;
    }
    day.clear();
    for(int i=1;i<=n;i++) if(dp[2][i]!=-INF) day.push_back(i);

    for(int i=0,j=1;i<day.size()&&j<=n;j++){
        dp[3][j]=dp[2][j];
        if(dp[3][j]==-INF) continue;
        if(day[i]>=j) continue;
        dp[3][j]=max(dp[3][j],dp[2][day[i]]+cal(day[i],j));
        while(i+1<day.size()&&day[i+1]<j&&
            dp[2][day[i]]+cal(day[i],j)<=dp[2][day[i+1]]+cal(day[i+1],j))
            dp[3][j]=max(dp[3][j],dp[2][day[i+1]]+cal(day[i+1],j)),i++;
    }
    LL ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[3][i]);
    cout<<ans;
    return 0;
}