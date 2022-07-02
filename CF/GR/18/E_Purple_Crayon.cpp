#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;
vector<int> adj[N];
int val[N],p[N];
bool mark[N];
priority_queue<PII> heap;

void dfs(int u,int fa,int deep) {
    val[u]=deep;
    p[u]=fa;
    int cnt=0;
    for(int v:adj[u]) 
        if(v!=fa) dfs(v,u,deep+1),cnt++;
    if(!cnt) heap.emplace(val[u],u);
}

int update(int u,int s) {
    if(u==-1||mark[u]) return 0;
    int res=update(p[u],u)+1;
    for(int v:adj[u]) {
        if(v!=p[u]&&v!=s) {
            
        }
    }
}

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1,1);
    int w=n,r=0;
    LL ans=0;
    while(heap.size()) {
        auto [v,u]=heap.top();
        heap.pop();
        if(v!=val[u]) continue;
        r+=v;
        ans=max(ans,1LL*w*(2*r-n));

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}