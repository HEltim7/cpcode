#include <array>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
constexpr int N=2e5+10,M=32;
using LL=long long;
using ARR=array<bool,M>;

int val[N],sz[N];
vector<int> res,adj[N];
vector<ARR> state[N];
ARR dp[N],tmp;

void dfs(int u) {
    sz[u]=1;
    dp[u][val[u]]=1;
    for(int v:adj[u]) {
        dfs(v);
        sz[u]+=sz[v];
        for(int j=0;j<M;j++)
            if(dp[u][j])
                for(int k=0;k<M;k++)
                    tmp[j^k]|=dp[v][k];
        swap(dp[u],tmp);
        state[u].push_back(tmp);
        for(int i=0;i<M;i++) tmp[i]=0;
    }
    if(sz[u]%2==0) dp[u][0]=1;
}

void find(int u,int st) {
    if(st==0&&sz[u]%2==0) {
        res.push_back(u);
        res.push_back(u);
    }
    else {
        reverse(adj[u].begin(),adj[u].end());
        for(int v:adj[u]) {
            const auto &t=state[u].back();
            for(int j=0;j<M;j++) {
                if(dp[v][j]&&t[st^j]) {
                    find(v,j);
                    st^=j;
                    break;
                }
            }
            state[u].pop_back();
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=2;i<=n;i++) {
        int u;
        cin>>u;
        adj[u].push_back(i);
    }
    for(int i=1;i<=n;i++) state[i].reserve(adj[i].size());
    dfs(1);
    if(dp[1][0]) {
        find(1,0);
        if(res.size()<2*n) res.push_back(1);
        cout<<res.size()<<endl;
        for(auto x:res) cout<<x<<' ';
    }
    else cout<<-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}