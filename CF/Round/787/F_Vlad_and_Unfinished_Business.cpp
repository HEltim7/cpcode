#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
vector<int> adj[N];
int p[N];
bool mark[N];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void dfs(int u,int fa) {
    for(auto v:adj[u]) {
        if(v!=fa) {
            p[v]=u;
            dfs(v,u);
        }
    }
}

pair<int,int> up(int u) {
    int res=0;
    while(!mark[u]) {
        mark[u]=1;
        res++;
        u=p[u];
    }
    return {res,u};
}

void solve() {
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    memset(mark,0,sizeof (bool)*(n+1));
    for(int i=1;i<=n;i++) adj[i].clear();
    vector<int> th;
    for(int i=1;i<=k;i++) {
        int in;
        cin>>in;
        th.push_back(in);
    }
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    mark[x]=1;
    dfs(x,-1);
    int ans=0;
    for(auto x:th) ans+=up(x).first*2;

    if(mark[y]) {
        int d=0;
        while(y!=x) {
            y=p[y];
            d++;
        }
        ans-=d;
    }
    else {
        int d=0;
        while(!mark[y]) {
            y=p[y];
            d++;
        }
        while(y!=x) {
            y=p[y];
            d--;
        }
        ans+=d;
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