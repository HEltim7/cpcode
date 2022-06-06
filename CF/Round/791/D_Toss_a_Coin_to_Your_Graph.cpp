#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;
const int INF=0x3f3f3f3f;

int val[N];
vector<int> adj[N];
PII edge[N];
LL k;
int n,m;
int ind[N];

bool bfs(int x) {
    queue<PII> q;
    int res=0;
    for(int i=1;i<=n;i++) if(ind[i]==0&&val[i]<=x) q.push({i,1});
    while(q.size()){
        auto [u,step]=q.front();
        q.pop();
        res=max(step,res);
        for(auto v:adj[u])
            if(--ind[v]==0) 
                q.emplace(v,step+1);
    }
    for(int i=1;i<=n;i++) if(ind[i]) return 1;
    return res>=k;
}

void build(int x) {
    memset(ind,0,sizeof ind);
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=m;i++) {
        auto [a,b]=edge[i];
        if(val[a]<=x&&val[b]<=x) adj[a].push_back(b),ind[b]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=m;i++) cin>>edge[i].first>>edge[i].second;
    int l=1,r=INF;
    while(l<r){
        int mid=l+r>>1;
        build(mid);
        if(bfs(mid)) r=mid;
        else l=mid+1;
    }
    cout<<(l==INF?-1:l)<<endl;
    return 0;
}