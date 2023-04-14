#include <set>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
vector<int> adj[N];
int up[N],dn[N];
multiset<int> upst[N],dnst[N];

pair<int,int> get(int u) {
    int up_cur=1,dn_cur=N;
    if(upst[u].size()) {
        up_cur=*upst[u].begin()+1;
        dn_cur=*dnst[u].begin();
        if(upst[u].size()>=2) dn_cur=min(dn_cur,*++upst[u].begin());
    }
    return {up_cur,dn_cur};
}

void dfs1(int u,int fa) {
    upst[u].clear();
    dnst[u].clear();
    for(int v:adj[u]) {
        if(v!=fa) {
            dfs1(v,u);
            upst[u].insert(up[v]);
            dnst[u].insert(dn[v]);
        }
    }
    tie(up[u],dn[u])=get(u);
}

void dfs2(int u,int fa) {
    tie(up[u],dn[u])=get(u);
    auto &ups=upst[u],&dns=dnst[u];
    for(int v:adj[u]) {
        if(v!=fa) {
            ups.erase(ups.find(up[v]));
            dns.erase(dns.find(dn[v]));
            auto [x,y]=get(u);
            ups.insert(up[v]);
            dns.insert(dn[v]);
            upst[v].insert(x);
            dnst[v].insert(y);
            dfs2(v,u);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,min(up[i],dn[i]));
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