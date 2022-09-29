#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=5e5+10;
vector<int> adj[N];
vector<pair<int,int>> q[N];
int sz[N],hch[N],id[N],ed[N],idx;
int cnt[27][N],tot[N],odd[N],dep[N]={0,1};
char _s[N],s[N];
bool ans[N];

void init(int u) {
    id[u]=++idx;
    s[idx]=_s[u];
    sz[u]=1;
    for(int v:adj[u]) {
        dep[idx+1]=dep[id[u]]+1;
        init(v);
        if(sz[v]>sz[hch[u]]) hch[u]=v;
        sz[u]+=sz[v];
    }
    ed[u]=idx;
}

void solve(int u,bool keep) {
    auto add=[](int x) {
        if((++cnt[s[x]-'a'+1][dep[x]])&1) odd[dep[x]]++;
        else odd[dep[x]]--;
        tot[dep[x]]++;
    };
    auto del=[](int x) {
        if((--cnt[s[x]-'a'+1][dep[x]])&1) odd[dep[x]]++;
        else odd[dep[x]]--;
        tot[dep[x]]--;
    };
    
    for(int v:adj[u]) if(v!=hch[u]) solve(v, 0);
    if(hch[u]) solve(hch[u], 1);
    for(int v:adj[u])
        if(v!=hch[u])
            for(int i=id[v];i<=ed[v];i++) add(i);
    add(id[u]);
    
    for(auto [d,i]:q[u]) {
        if(tot[d]&1) ans[i]=odd[d]==1;
        else ans[i]=odd[d]==0;
    }
    
    if(!keep) for(int i=id[u];i<=ed[u];i++) del(i);
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=2,p;i<=n;i++) cin>>p,adj[p].push_back(i);
    for(int i=1;i<=n;i++) cin>>_s[i];
    
    init(1);
    for(int i=1,u,d;i<=m;i++) {
        cin>>u>>d;
        q[u].emplace_back(d,i);
    }
    solve(1,1);
    for(int i=1;i<=m;i++) cout<<(ans[i]?"Yes":"No")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}