#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e4+10;
vector<int> adj[N];
int color[N],p[N];
int ans=0;

void dfs(int u,int cur) {
    if(color[u]!=cur) ans++;
    cur=color[u];
    for(int v:adj[u]) dfs(v,cur);
}

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        cin>>p[i];
        adj[p[i]].push_back(i);
    }
    for(int i=1;i<=n;i++) cin>>color[i];
    dfs(1,0);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}