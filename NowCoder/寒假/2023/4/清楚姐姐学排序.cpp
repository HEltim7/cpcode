#include <queue>
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10;
vector<int> adj[N],radj[N];
bitset<N> mark[N];
int ind[N],ge[N],le[N],ans[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    auto bfs=[&](vector<int> adj[]) {
        queue<int> q;
        for(int i=1;i<=n;i++) ind[i]=0,mark[i].reset();
        for(int i=1;i<=n;i++) for(int v:adj[i]) ind[v]++;
        for(int i=1;i<=n;i++) if(!ind[i]) q.push(i);
        int cnt=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            cnt++;
            for(int v:adj[u]) {
                mark[v]|=mark[u];
                mark[v].set(u);
                if(!--ind[v]) q.push(v);
            }
        }
        return cnt!=n;
    };

    bool invalid=0;
    invalid|=bfs(adj);
    for(int i=1;i<=n;i++) ge[i]=mark[i].count();

    invalid|=bfs(radj);
    for(int i=1;i<=n;i++) le[i]=mark[i].count();

    for(int i=1;i<=n;i++) ans[i]=-1;
    if(!invalid) for(int i=1;i<=n;i++) if(le[i]+ge[i]+1==n) ans[1+ge[i]]=i;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}