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
bool mark[N];
int fa[N],sz[N];

int findfa(int x) {
    if(x==fa[x]) return x;
    return fa[x]=findfa(fa[x]);
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in) mark[i]=1;
    }

    for(int i=1;i<=n;i++) {
        int a=findfa(i);
        for(int v:adj[i]) {
            int b=findfa(v);
            if(a!=b) {
                fa[b]=a;
                sz[a]+=sz[b];
                mark[a]=mark[a]|mark[b];
            }
        }
    }

    LL ans1=0,ans2=0;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(i==fa[i]) {
            if(mark[i]) {
                cnt++;
                ans1+=1LL*sz[i]*sz[i];
            }
            else ans2+=1LL*sz[i]*sz[i];
        }
    }
    if(cnt>=2) cout<<0<<endl;
    else if(cnt==1) cout<<ans1<<endl;
    else cout<<ans1+ans2<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}