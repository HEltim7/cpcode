#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define endl '\n'
using LL=long long;

const int N=2e5+10;
int fa[N],dis[N],mark[N];
vector<int> adj[N];
pair<int,int> edge[N];

int findfa(int x) {
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        edge[i]={b,a};
        adj[b].push_back(a);
    }
    int ans=m,res=0;
    queue<int> q;
    q.push(n);
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(auto v:adj[u]) {
            if(findfa(v)!=findfa(u)) {
                ans--;
                fa[u]=findfa(v);
                dis[v]=max(dis[v],dis[u]+1);
                if(v==1) res=max(res,dis[v]);
                if(!mark[v]) q.push(v);
                mark[v]=1;
            }
        }
    }
    ans+=res;
    for(int i=1;i<=m;i++) {
        if(!mark[edge[i].second]) ans--;
    }   
    cout<<ans<<endl;
    return 0;
}