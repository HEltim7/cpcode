#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=1e4+10;
vector<int> adj[N];
LD pk[N],pe[N],pf[N],pc[N];
LD x[N],y[N],z[N];

void dfs(int u,int fa) {
    LD t=0;
    for(int v:adj[u]) if(v!=fa) dfs(v,u);
    for(int v:adj[u]) {
        if(v!=fa) {
            t+=y[v];
            x[u]+=x[v];
            z[u]+=z[v]+1;
        }
    }
    t=1-t*pc[u];
    x[u]=(pk[u]+pc[u]*x[u])/t;
    y[u]=(pf[u])/t;
    z[u]=(pf[u]+pc[u]*z[u])/t;
}

bool check(int u,int fa) {
    if(pe[u]>0) return 1;
    bool res=0;
    for(int v:adj[u])
        if(v!=fa&&pc[v]>0) 
            res|=check(v,u);
    return res;
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++) {
        cin>>pk[i]>>pe[i];
        pk[i]/=100;
        pe[i]/=100;
        pc[i]=(1-pk[i]-pe[i])/adj[i].size();
        if(i>1) pf[i]=pc[i];
    }

    if(check(1,0)) {
        dfs(1,0);
        LD ans=z[1]/(1-x[1]);
        cout<<fixed<<setprecision(15)<<ans;
    }
    else cout<<"impossible";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}