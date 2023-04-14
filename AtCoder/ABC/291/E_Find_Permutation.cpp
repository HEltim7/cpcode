#include <queue>
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
int ans[N],ind[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        ind[y]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++) if(!ind[i]) q.push(i);
    if(q.size()!=1) {
        cout<<"No"<<endl;
        return;
    }

    int cnt=0;
    vector<int> res;
    ans[q.front()]=1;
    while(q.size()) {
        int u=q.front();
        q.pop();
        cnt++;
        for(int v:adj[u]) {
            ans[v]=max(ans[v],ans[u]+1);
            if(!--ind[v]) q.push(v);
        }
    }

    for(int i=1;i<=n;i++) res.push_back(ans[i]);
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    if(cnt==n&&res.size()==n) {
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    }
    else cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}