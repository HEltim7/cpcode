#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=4e5+10;
vector<int> adj[N];
bool mark[N];

bool dfs(int u,int fa) {
    mark[u]=1;
    bool res=0;
    for(int v:adj[u]) {
        if(v!=fa) {
            if(mark[v]) res|=1;
            else res|=dfs(v,u);
        }
    }
    return res;
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) adj[i].push_back(i+n),adj[i+n].push_back(i);
    for(int i=1;i<=m;i++) {
        int u,v;
        char x,y;
        cin>>u>>x>>v>>y;
        if(x=='R') u+=n;
        if(y=='R') v+=n;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++) if(!mark[i]) {
        if(dfs(i,0)) ans2++;
        else ans1++;
    }
    cout<<ans2<<' '<<ans1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}