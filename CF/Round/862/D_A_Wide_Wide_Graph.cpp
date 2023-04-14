#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
vector<int> adj[N];
int dn[N],up[N],maxdis[N],ans[N];

void init(int u,int fa) {
    for(int v:adj[u]) {
        if(v!=fa) {
            init(v,u);
            dn[u]=max(dn[u],dn[v]+1);
        }
    }
}

void dfs(int u,int fa) {
    multiset<int> st;
    st.insert(0);
    st.insert(up[u]);
    for(int v:adj[u])
        if(v!=fa) st.insert(dn[v]+1);
        else st.insert(up[v]+1);
    debug(u,st);
    for(int v:adj[u]) {
        if(v!=fa) {
            int t=dn[v]+1;
            st.erase(st.find(t));
            up[v]=*st.rbegin()+1;
            st.insert(t);
        }
    }
    for(int v:adj[u]) if(v!=fa) dfs(v,u);
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
    init(1, 0);
    dfs(1, 0);
    ans[1]=n;
    for(int i=1;i<=n;i++) maxdis[i]=max(up[i],dn[i]);
    debug(maxdis,1,n);
    for(int i=1;i<=n;i++) ans[maxdis[i]+1]--;
    for(int i=1;i<=n;i++) ans[i]+=ans[i-1];
    debug(ans,1,n);
    for(int i=1;i<=n;i++) cout<<min(n,n-ans[i]+1)<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}