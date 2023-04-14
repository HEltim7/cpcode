#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=1e5+10,M=315;
int p[N],dep[N],a[N],cnt[N],id[N];
LL ans[N][M];
vector<int> adj[N];

void init(int u,int d) {
    dep[u]=d;
    id[u]=++cnt[dep[u]];
    for(int v:adj[u]) init(v,d+1);
}

LL climb(int x,int y) {
    if(!x||!y) return 0;
    if(x>y) swap(x,y);
    if(id[y]<M&&ans[x][id[y]]) return ans[x][id[y]];
    LL res=1LL*a[x]*a[y];
    res+=climb(p[x], p[y]);
    if(id[y]<M) ans[x][id[y]]=res;
    return res;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<PII> q(m);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) cin>>p[i],adj[p[i]].push_back(i);
    init(1,1);
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        cout<<climb(u, v)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}