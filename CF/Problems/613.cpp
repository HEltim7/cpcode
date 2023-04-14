#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,M=__lg(N);
int fa[N][M+1],dep[N],id[N],idx;
vector<int> adj[N],vt[N];

void lca_init(int u,int p) {
    dep[u]=dep[p]+1;
    for(int v:adj[u]) {
        if(v==p) continue;
        fa[v][0]=u;
        for(int i=1;i<=M;i++)
            fa[v][i]=fa[fa[v][i-1]][i-1];
        lca_init(v,u);
    }
}

int lca(int a,int b) {
    if(dep[a]<dep[b]) swap(a,b);
    for(int k=M;~k;k--)
        if(dep[fa[a][k]]>=dep[b])
            a=fa[a][k];
    if(a==b) return a;
    for(int k=M;~k;k--)
        if(fa[a][k]!=fa[b][k])
            a=fa[a][k],b=fa[b][k];
    return fa[a][0];
}

void relabel(int u,int fa) {
    id[u]=++idx;
    for(int v:adj[u]) if(v!=fa) relabel(v,u);
}

LL dp[N];
bool key[N],type[N];
void dfs(int u) {
    int cnt=0;
    dp[u]=0;
    for(int v:vt[u]) {
        dfs(v);
        cnt+=type[v];
        dp[u]+=dp[v];
        if(key[v]&&key[u]&&dep[u]==dep[v]-1) dp[u]=N;
    }
    if(key[u]) dp[u]+=cnt,type[u]=1;
    else if(cnt>=2) dp[u]++,type[u]=0;
    else if(cnt==1) type[u]=1;
    else type[u]=0;
}

int stk[N],top;
void vt_build(vector<int> &vec) {
    sort(vec.begin(),vec.end(),[](int x,int y) {
        return id[x]<id[y];
    });
    vec.erase(unique(vec.begin(),vec.end()),vec.end());

    auto clear=[](int u) {
        vt[u].clear();
    };
    
    clear(1);
    stk[top=0]=1;
    for(int u:vec) {
        if(u==1) continue;
        int lc=lca(u,stk[top]);
        if(lc!=stk[top]) {
            while(id[lc]<id[stk[top-1]])
                vt[stk[top-1]].push_back(stk[top]),top--;
            if(id[lc]!=id[stk[top-1]])
                clear(lc),vt[lc].push_back(stk[top]),stk[top]=lc;
            else vt[lc].push_back(stk[top]),top--;
        }
        clear(u);
        stk[++top]=u;
    }
    for(int i=0;i<top;i++) vt[stk[i]].push_back(stk[i+1]);
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
    lca_init(1, 0);
    relabel(1, 0);

    int q;
    cin>>q;
    while(q--) {
        int k;
        cin>>k;
        vector<int> cur(k);
        for(int i=0;i<k;i++) cin>>cur[i],key[cur[i]]=1;
        vt_build(cur);
        dfs(1);
        cout<<(dp[1]>=N?-1:dp[1])<<endl;
        for(int i=0;i<k;i++) key[cur[i]]=0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}