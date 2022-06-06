#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
vector<int> adj[N];
int mark[N];
bool ans;
int pre[N];
int n,m,s;
vector<int> p[2];

void get_path(int end,int id){
    while(end){
        p[id].push_back(end);
        end=pre[end];
    }
}

void dfs(int u,int fa,int color){
    if(mark[u]&&mark[u]!=color){
        ans=1;
        p[0].push_back(u);
        get_path(fa,0);
        get_path(u,1);
    }
    if(ans||mark[u]) return;
    mark[u]=color;
    pre[u]=fa;
    for(auto v:adj[u]){
        if(!ans&&v!=s) dfs(v,u,color);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    int cnt=0;
    for(auto u:adj[s]) if(!ans) dfs(u,s,++cnt);
    
    if(ans){
        cout<<"Possible"<<endl;
        reverse(p[0].begin(),p[0].end());
        reverse(p[1].begin(),p[1].end());
        cout<<p[0].size()<<endl;
        for(auto x:p[0]) cout<<x<<' ';
        cout<<endl;
        cout<<p[1].size()<<endl;
        for(auto x:p[1]) cout<<x<<' ';
    }
    else cout<<"Impossible"<<endl;
    return 0;
}