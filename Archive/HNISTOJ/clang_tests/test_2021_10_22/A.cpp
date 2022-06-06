#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N=1e5+10;
typedef vector<int> VI;

int score[N];
int ind[N];
int n,m;//n个点m条边
VI adj[N];
int dp[N];

int toposort(){
    queue<int> q;
    for(int i=1;i<=n;i++) if(ind[i]==0) q.push(i),dp[i]=score[i];
    while(q.size()){
        int h=q.front();
        q.pop();
        for(auto x:adj[h]){
            if(--ind[x]==0) q.push(x);
            dp[x]=max(dp[x],score[x]+dp[h]);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dp[i]);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>score[i];
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        ind[b]++;
    }
    cout<<toposort();
    return 0;
}