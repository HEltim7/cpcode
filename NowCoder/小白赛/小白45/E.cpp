#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10,INF=0xcfcfcfcf;
vector<pair<int,LL>> adj[N];
LL ans=INF,val[N];

LL dfs(int x,int fa){
    LL res=val[x];
    for(auto [s,v]:adj[x]) if(s!=fa) res+=max(0LL,dfs(s,x)+v);
    ans=max(ans,res);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<n;i++){
        LL a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,-1);
    cout<<ans;
    return 0;
}