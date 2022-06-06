#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'

const int N=10010;
int dp[N];//从前i个物品选，总时间恰好为j的最大值

struct GEM{
    int e,s,l;
    double sl;
} gem[N];

bool cmp(GEM a,GEM b){
    return a.sl<b.sl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    for(int c=1;c<=t;c++){
        int time=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>gem[i].s>>gem[i].e>>gem[i].l;
            if(gem[i].l==0) gem[i].sl=1e9;
            else gem[i].sl=gem[i].s*1./gem[i].l;
            time+=gem[i].s;
        }
        sort(gem+1,gem+1+n,cmp);
        memset(dp,-0x3f,sizeof(int)*(time+1));
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=time;j>=gem[i].s;j--){
                dp[j]=max(dp[j],dp[j-gem[i].s]+max(0,gem[i].e-gem[i].l*(j-gem[i].s)));
            }
        }

        int ans=0;
        for(int i=1;i<=time;i++) ans=max(ans,dp[i]);
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}