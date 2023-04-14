#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=2e5+10;
vector<PII> adj[N];
int deg[N];
bool mark[N],edge[N];

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    int lim=sqrt(m)+1;

    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=n;i++) {
        if(deg[i]>=lim) {
            sort(adj[i].begin(),adj[i].end(),[](PII &x,PII &y) {
                return deg[x.first]>deg[y.first];
            });
            while(adj[i].size()&&deg[adj[i].back().first]<lim) adj[i].pop_back();
        }
    }

    while(q--) {
        int k;
        cin>>k;
        vector<int> arr(k),res;
        for(int i=0;i<k;i++) cin>>arr[i],mark[arr[i]]=1;
        for(int u:arr) for(auto [v,id]:adj[u]) if(mark[v]&&!edge[id]) res.push_back(id),edge[id]=1;
        cout<<res.size()<<endl;
        for(int u:arr) mark[u]=0;
        for(int id:res) edge[id]=0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}