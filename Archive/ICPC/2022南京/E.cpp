#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,M=__lg(N);
constexpr LL INF=1e18;
vector<int> adj[N],vec[N];
int fa[N][M+1],dep[N],id[N],idx;

template<typename T=int> struct SparseTable {
    constexpr static int N=1e5+10,M=20;
    T arr[N],st[M][N];

    void build(int n) {
        for(int i=0;i<n;i++) st[0][i]=arr[i];
        for(int k=1,t=1<<k;k<M;k++,t<<=1)
            for(int i=0,j=i+t-1,mid=i+t/2;j<n;i++,j++,mid++)
                st[k][i]=min(st[k-1][i],st[k-1][mid]);
    }

    T query(int l,int r) {
        if(r<l) return 0;
        int k=__lg(r-l+1);
        return min(st[k][l],st[k][r-(1<<k)+1]);
    }
};
SparseTable<> st;

void lca_init(int u,int p) {
    dep[u]=dep[p]+1;
    vec[dep[u]].push_back(u);
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
    for(int v:adj[u]) if(v!=fa) relabel(v, u);
}

int stk[N],top;
vector<int> vt[N];
void vt_build(vector<int> &vec) {
    sort(vec.begin(),vec.end(),[](int x,int y) {
        return id[x]<id[y];
    });

    auto add=[&](int u,int v) {
        vt[u].emplace_back(v);
    };
    
    vt[1].clear();
    stk[top=0]=1;
    for(int u:vec) {
        if(u==1) continue;
        int lc=lca(u,stk[top]);
        if(lc!=stk[top]) {
            while(id[lc]<id[stk[top-1]])
                add(stk[top-1],stk[top]),top--;
            if(id[lc]!=id[stk[top-1]])
                vt[lc].clear(),add(lc,stk[top]),stk[top]=lc;
            else add(lc,stk[top--]);
        }
        vt[u].clear();
        stk[++top]=u;
    }
    for(int i=0;i<top;i++) add(stk[i],stk[i+1]);
}

LL dfs(int u,int fa,int d) {
    LL res=0;
    if(vt[u].empty()) res=INF;
    else for(int v:vt[u]) res+=dfs(v,u,d);
    return min(res,1LL*st.query(d-dep[u], d-dep[fa]-1));
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) adj[i].clear(),vec[i].clear();
    for(int i=0;i<n;i++) cin>>st.arr[i];
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    idx=0;
    lca_init(1, 0);
    relabel(1, 0);
    st.build(n);

    LL ans=st.arr[0];
    for(int i=2;i<=n&&vec[i].size();i++) {
        vt_build(vec[i]);
        ans+=dfs(1,0,i);
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