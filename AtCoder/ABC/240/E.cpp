#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10;
typedef pair<int,int> PII;
vector<int> adj[N];
PII ans[N];
int cnt[N];

int dfs1(int x,int fa){
    int res=0;
    bool flag=1;
    for(auto s:adj[x]){
        if(s==fa) continue;
        flag=0;
        res+=dfs1(s,x);
    }
    if(flag) return cnt[x]=1;
    return cnt[x]=res;
}

void dfs2(int x,int fa,int res){
    int tmp=res;
    ans[x]={res+1,res+cnt[x]};
    for(auto s:adj[x]){
        if(s==fa) continue;
        dfs2(s,x,tmp);
        tmp+=cnt[s];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    for(int i=1;i<=n;i++) cout<<ans[i].first<<' '<<ans[i].second<<endl;
    return 0;
}