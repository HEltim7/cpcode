#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10;
const LL INF=N*1e9;

vector<int> adj[N];
LL dp[N][2],mx[N],val[N];

void dfs(int x,int fa){
    //maxx子树权值最大值,minx子树权值次大值,maxch最大子树标号
    //upp,子树权值>=根的数量,cnt最大值的数量,minsum最小子树权值和,ch子树数量
    LL maxx=0,minx=0,maxch=0,upp=0,cnt=0,minsum=0,ch=0;
    for(int s:adj[x]) if(s!=fa) {
        dfs(s,x);
        ch++;
        mx[x]=max(mx[x],mx[s]);
        minsum+=dp[s][1];
        if(mx[s]>=val[x]) upp++;
        if(mx[s]>maxx) cnt=1,minx=maxx,maxx=mx[s],maxch=s;
        else if(mx[s]==maxx) cnt++,minx=maxx;
        else if(mx[s]>minx) minx=mx[s];
    }
    for(int s:adj[x]){
        if(s==fa) continue;
        //仅解决一半的情况
        if(fa!=-1){
            if(upp==0) dp[x][1]=minsum+val[x]-maxx;
            else dp[x][1]=minsum;
        }
        //自行解决的情况
        if(ch<2) continue;
        if(upp==0) dp[x][0]=minsum+val[x]*2-maxx-minx;
        else if(upp==1) dp[x][0]=minsum+
            min(dp[maxch][0]-dp[maxch][1]+val[x]-minx,maxx-minx);
        else if(cnt>=2) dp[x][0]=minsum;
        else dp[x][0]=minsum+min(maxx-minx,dp[maxch][0]-dp[maxch][1]);
    }
    if(ch==0) dp[x][1]=val[x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,root=0;
    cin>>n;
    for(int i=1;i<=n;i++) dp[i][0]=dp[i][1]=INF;
    for(int i=1;i<=n;i++) cin>>val[i],mx[i]=val[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if(adj[a].size()>=2) root=a;
        else if(adj[b].size()>=2) root=b;
    }
    if(n<=2){
        cout<<max(val[1],val[2])*2;
        return 0;
    }
    dfs(root,-1);
    cout<<dp[root][0];
    return 0;
}