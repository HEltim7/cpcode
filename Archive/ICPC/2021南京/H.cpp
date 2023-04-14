#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
LL dp[N][3],v[N],t[N];
vector<int> adj[N];

void dfs(int x,int fa){
    for(auto s:adj[x]) if(s!=fa) dfs(s,x);
    LL maxi[2]={0},mini[2]={0};
    LL maxv[2]={0},minv[2]={0};
    LL maxx=0;
    for(auto s:adj[x]){
        if(s==fa) continue;
        dp[x][0]+=dp[s][2];
        dp[x][1]+=dp[s][2];
        for(int i=0;i<2;i++){
            LL val=dp[s][i]-dp[s][2];
            maxx=max(maxx,val);
            if(i==1&&t[s]<3) continue;
            if(val>=maxv[i]) minv[i]=maxv[i],maxv[i]=val,mini[i]=maxi[i],maxi[i]=s;
            else if(val>minv[i]) minv[i]=val,mini[i]=s;
        }
    }
    if(maxi[0]!=mini[1]) dp[x][1]+=max(maxx,maxv[0]+maxv[1]);
    else dp[x][1]+=max({maxx,maxv[0]+minv[1],maxv[1]+minv[0]});
    dp[x][0]+=v[x];
    dp[x][1]+=v[x];
    dp[x][2]=dp[x][1]-v[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<=n;i++) for(int j=0;j<3;j++) dp[i][j]=0;
        for(int i=1;i<=n;i++) cin>>v[i];
        for(int i=1;i<=n;i++) cin>>t[i];
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,-1);
        cout<<dp[1][1]<<endl;
    }
    return 0;
}