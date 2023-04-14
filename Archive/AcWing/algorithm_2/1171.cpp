#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=1e4+10,M=15;
vector<PII> adj[N];
int fa[N][M+1],dis[N][M+1],dep[N];

void dfs(int x,int p){
    for(auto [s,d]:adj[x]){
        if(s==p) continue;
        dep[s]=dep[x]+1;
        fa[s][0]=x;
        dis[s][0]=d;
        for(int i=1;i<=M;i++)
            fa[s][i]=fa[fa[s][i-1]][i-1];
        for(int i=1;i<=M;i++)
            dis[s][i]=dis[fa[s][i-1]][i-1]+dis[s][i-1];
        dfs(s,x);
    }
}

int lca(int a,int b){
    int res=0;
    if(dep[a]<dep[b]) swap(a,b);
    for(int k=M;~k;k--)
        if(dep[fa[a][k]]>=dep[b])
            res+=dis[a][k],a=fa[a][k];
    if(a==b) return res;
    for(int k=M;~k;k--)
        if(fa[a][k]!=fa[b][k])
            res+=dis[a][k]+dis[b][k],a=fa[a][k],b=fa[b][k];
    return res+dis[a][0]+dis[b][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int a,b,k;
        cin>>a>>b>>k;
        adj[a].emplace_back(b,k);
        adj[b].emplace_back(a,k);
    }
    dep[1]=1;
    dfs(1,-1);
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}