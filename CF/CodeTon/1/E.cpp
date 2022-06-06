#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
int deg[N];
vector<int> adj[N];

void dfs(int x,int fa,int color){
    deg[x]*=color;
    for(auto s:adj[x])
        if(s!=fa) dfs(s,x,-color);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) adj[i].clear();
        memset(deg,0,sizeof (int)*(n+1));
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        dfs(1,-1,1);
        for(int i=1;i<=n;i++) cout<<deg[i]<<" \n"[i==n];
    }
    return 0;
}