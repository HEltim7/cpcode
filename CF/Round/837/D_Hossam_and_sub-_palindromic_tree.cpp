#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;
vector<int> adj[N];
pair<int,int> p[N][N];
int res[N][N];
bool mark[N][N];

void solve() {
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) {
        adj[i].clear();
        for(int j=1;j<=n;j++) {
            mark[i][j]=0;
            res[i][j]=0;
            p[i][j]={-1,-1};
        }
    }
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++) {
        res[i][i]=1;
        q.emplace(i,i);
    }
    for(int u=1;u<=n;u++) {
        for(int v:adj[u]) {
            if(v>u&&s[u]==s[v]) {
                res[u][v]=2;
                q.emplace(u,v);
                p[u][v]={v,u};
            }
        }
    }

    int ans=0;
    while(q.size()) {
        auto [u,v]=q.front();
        q.pop();
        if(mark[u][v]||mark[v][u]) continue;
        mark[u][v]=mark[v][u]=1;
        ans=max(ans,res[u][v]);

        for(int x:adj[u]) if(x!=p[u][v].first) {
            res[x][v]=max(res[x][v],res[u][v]);
            q.emplace(x,v);
            if(p[x][v].first==-1) p[x][v]={u,p[u][v].second};
        }
        for(int y:adj[v]) if(y!=p[u][v].second) {
            res[u][y]=max(res[u][y],res[u][v]);
            q.emplace(u,y);
            if(p[u][y].first==-1) p[u][y]={p[u][v].first,v};
        }

        for(int x:adj[u]) if(x!=p[u][v].first)
            for(int y:adj[v]) if(y!=p[u][v].second&&x!=y&&s[x]==s[y]) {
                    res[x][y]=max(res[x][y],res[u][v]+2);
                    q.emplace(x,y);
                    if(p[x][y].first==-1) p[x][y]={u,v};
                }
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}