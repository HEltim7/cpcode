#include <deque>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
vector<int> adj[N];
int n,m,k;
int dis[N],a[N],b[N];
bool mark[N];

bool bfs() {
    deque<int> q{1};
    memset(dis, 0x3f, sizeof dis);
    dis[1]=a[1]==b[1];
    mark[1]=1;
    while(q.size()) {
        int u=q.front();
        q.pop_front();
        for(int v:adj[u]) {
            if(!mark[v]) {
                mark[v]=1;
                if(a[v]==b[dis[u]+1]) 
                    q.push_back(v),dis[v]=dis[u]+1;
                else q.push_front(v),dis[v]=dis[u];
            }
        }
    }
    return dis[n]==k;
}

void solve() {
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++) cin>>b[i];
    cout<<(bfs()?"Yes":"No");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}