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
constexpr int N=2e5+10;
vector<int> adj[N];
int arr[N],fa[N],sz[N];
bool out[N],mark[N];

int findfa(int x) {
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

void dfs(int u) {
    out[u]=mark[u]=1;
    for(int v:adj[u]) dfs(v);
}

int count(int u) {
    if(mark[u]) return 0;
    mark[u]=1;
    int res=1;
    for(int v:adj[u]) res+=count(v);
    return res;
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) adj[i].clear(),out[i]=mark[i]=0,fa[i]=i,sz[i]=1;
    for(int i=1;i<=n;i++) cin>>arr[i];

    for(int i=1;i<=n;i++) {
        int t=i+arr[i];
        if(t<1||t>n) t=0,out[i]=1;
        else {
            adj[t].push_back(i);
            
            int b=findfa(t);
            int a=findfa(i);
            if(a!=b) {
                fa[a]=b;
                sz[b]+=sz[a];
            }
        }
    }
    for(int i=1;i<=n;i++) if(out[i]) for(int v:adj[i]) out[v]=1;
    LL ans=0;
    int tot=n*2+1;

    for(int i=1;i<=n;i++) 
        if(!mark[i]&&out[i]) dfs(i);

    int ban=0;
    for(int i=1;i<=n;i++) mark[i]=0;
    for(int i=1;i<=n;i++) {
        int t=findfa(i);
        if(!mark[t]&&!out[t]&&t!=findfa(1))
            mark[t]=1,ban+=sz[t];
    }

    for(int i=1;i<=n;i++) mark[i]=0;
    if(out[1]) {
        int u=1,cnt=ban,key=0;
        while(u>=1&&u<=n) {
            key++;
            cnt+=count(u);
            ans+=tot-cnt;
            u+=arr[u];
        }

        ans+=1LL*(n-key)*tot;
    }
    else {
        int u=1,key=0;
        while(!mark[u]) {
            key++;
            mark[u]=1;
            u+=arr[u];
        }

        ban+=sz[findfa(1)];
        ans=1LL*key*(tot-ban);
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