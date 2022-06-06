#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=4e4+10,M=15;
vector<int> adj[N];
int fa[N][20],dep[N];

void dfs(int x,int p){
    for(auto s:adj[x]){
        if(s==p) continue;
        dep[s]=dep[x]+1;
        fa[s][0]=x;
        for(int i=1;i<=M;i++)
            fa[s][i]=fa[fa[s][i-1]][i-1];
        dfs(s,x);
    }
}

int lca(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    for(int k=M;~k;k--)
        if(dep[fa[a][k]]>=dep[b])
            a=fa[a][k];
    if(a==b) return a;
    for(int k=M;~k;k--)
        if(fa[a][k]!=fa[b][k])
            a=fa[a][k],b=fa[b][k];
    return fa[a][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,root;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(b==-1){
            root=a;
            dep[root]=1;
            continue;
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(root,-1);
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        int p=lca(a,b);
        if(p==a) cout<<1<<endl;
        else if(p==b) cout<<2<<endl;
        else cout<<0<<endl;
    }
    return 0;
}