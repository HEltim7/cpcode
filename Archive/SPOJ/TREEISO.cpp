#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
vector<int> adj[N];

int sz[N],centroid[2];
void get_centroid(int u,int fa,int tot) {
    int maxx=0;
    sz[u]=1;
    for(int v:adj[u]) {
        if(v!=fa) {
            get_centroid(v,u,tot);
            sz[u]+=sz[v];
            maxx=max(maxx,sz[v]);
        }
    }
    maxx=max(maxx,tot-sz[u]);
    if(maxx<=tot/2) centroid[centroid[0]!=0]=u;
}

LL f(LL x) {
    auto h=[](LL x) {
        return x * x * x * 1237123 + 19260817;
    };
    LL res = h(x & ((1LL << 31) - 1)) + h(x >> 31);
    return res;
}

LL dfs(int u,int fa) {
    LL res=1;
    for(int v:adj[u]) if(v!=fa) res+=f(dfs(v,u));
    return res;
}

void solve() {
    int n;
    cin>>n;

    auto work=[&]() {
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<n;i++) {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        centroid[0]=centroid[1]=0;
        get_centroid(1, 0, n);
        vector<LL> hsh;
        hsh.emplace_back(dfs(centroid[0],0));
        if(centroid[1]) hsh.emplace_back(dfs(centroid[1],0));
        sort(hsh.begin(),hsh.end());
        return hsh;
    };

    if(work()==work()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}