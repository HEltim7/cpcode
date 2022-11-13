#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=2e5+10;
vector<int> adj[N],radj[N];
int L[N],R[N],ind[N],rind[N],ans[N],id[N];

template<typename T> void
toposort(int n,int ind[],vector<int> adj[],T update) {
    queue<int> q;
    for(int i=1;i<=n;i++) if(!ind[i]) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:adj[u]) {
            update(u,v);
            if(!--ind[v]) q.push(v);
        }
    }
    for(int i=1;i<=n;i++) adj[i].clear();
}

void solve() {
    int n,m;
    cin>>n>>m;
    memset(ind+1, 0, sizeof(int)*n);
    memset(rind+1, 0, sizeof(int)*n);
    for(int i=1,p;i<=n;i++) {
        cin>>p;
        if(p) L[i]=R[i]=p;
        else L[i]=1,R[i]=n;
    }
    while(m--) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
        ind[v]++,rind[u]++;
    }

    toposort(n, ind, adj, [](int u,int v) {
        L[v]=max(L[v],L[u]+1);
    });
    toposort(n, rind, radj, [](int u,int v) {
        R[v]=min(R[v],R[u]-1);
    });

    for(int i=1;i<=n;i++) id[i]=i;
    sort(id+1,id+1+n,[](int x,int y) {
        if(L[x]!=L[y]) return L[x]<L[y];
        return R[x]<R[y];
    });

    set<PII> st;
    for(int i=1,val=1;val<=n;val++) {
        while(i<=n&&L[id[i]]<=val) {
            st.emplace(R[id[i]],id[i]);
            i++;
        }

        if(st.empty()||st.begin()->first<val) {
            cout<<-1<<endl;
            return;
        }
        ans[st.begin()->second]=val;
        st.erase(st.begin());
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}