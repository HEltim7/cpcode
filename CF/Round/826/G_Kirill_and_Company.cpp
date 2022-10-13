#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e4+10,M=1<<6;
int dis[N],id[N],fri[N];
bool mark[N][M],bak[M];
vector<int> adj[N];

void bfs() {
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:adj[u]) {
            if(dis[v]>=dis[u]+1) 
                for(int i=0;i<M;i++)
                    mark[v][i|id[v]]|=mark[u][i];
            if(dis[v]>dis[u]+1) 
                dis[v]=dis[u]+1,q.push(v);
        }
    }
}

void solve() {
    int n,m,f,k;
    cin>>n>>m;
    memset(dis, 0x3f, sizeof(int)*(n+1));
    memset(id, 0, sizeof(int)*(n+1));
    memset(bak, 0, sizeof bak);
    for(int i=0;i<=n;i++) {
        memset(mark[i], 0, sizeof(mark[i])),mark[i][0]=1;
        adj[i].clear();
    }
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cin>>f;
    multiset<int> st;
    for(int i=1;i<=f;i++) cin>>fri[i],st.insert(fri[i]);
    cin>>k;
    for(int i=0;i<k;i++) {
        int x;
        cin>>x;
        st.erase(st.find(fri[x]));
        id[fri[x]]|=1<<i;
    }
    if(k==f) {
        cout<<k<<endl;
        return;
    }

    bfs();
    vector<int> ff;
    for(auto x:st) ff.push_back(x);
    f=ff.size();

    for(int i=1;i<f;i++) {
        int x=ff[i-1],y=ff[i];
        for(int j=0;j<M;j++)
            for(int k=0;k<M;k++)
                bak[j|k]|=mark[x][j]&mark[y][k];
        for(int j=0;j<M;j++) mark[y][j]=bak[j];
    }

    int ans=0;
    for(int i=0,u=ff.back();i<M;i++) 
        if(mark[u][i]) 
            ans=max(ans,__builtin_popcount(i));
    cout<<k-ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}