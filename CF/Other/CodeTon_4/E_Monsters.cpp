#include <queue>
#include <vector>
#include <random>
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
int arr[N];
bool mark[N],vis[N];

void solve() {
    int n,m;
    cin>>n>>m;
    LL sum=0;
    for(int i=1;i<=n;i++) cin>>arr[i],sum+=arr[i];
    for(int i=1;i<=n;i++) adj[i].clear(),mark[i]=0;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LL maxx=1LL*(n-1)*n/2;
    if(sum>maxx) {
        cout<<"NO"<<endl;
        return;
    }

    auto check=[&]() {
        queue<int> q;
        q.push(1);
        int tot=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            tot++;
            for(int v:adj[u]) {
                q.push(v);
            }
        }
        for(int i=1;i<=n;i++) vis[i]=0;
        return tot==n;
    };

    if(!check()) {
        cout<<"NO"<<endl;
        return;
    }

    vector<int> q;
    auto bfs=[&](int u) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> heap;
        q.clear();
        heap.push({0,u});
        int cnt=0;
        vis[u]=1;
        q.push_back(u);
        bool res=true;
        while(heap.size()) {
            auto [d,u]=heap.top();
            heap.pop();
            debug(d,u,cnt);
            if(d>cnt) {
                res=false;
                break;
            }
            if(d==0) mark[u]=1;
            cnt++;
            for(int v:adj[u]) {
                if(!vis[v]) {
                    vis[v]=1;
                    heap.push({arr[v],v});
                    q.push_back(v);
                }
            }
        }

        for(int u:q) vis[u]=0;
        return res;
    };

    vector<int> rnd;
    rnd.reserve(n);
    for(int i=1;i<=n;i++) if(arr[i]==0) rnd.push_back(i);
    shuffle(rnd.begin(), rnd.end(), mt19937(random_device{}()));

    for(int u:rnd) if(!mark[u]) if(bfs(u)) {
        debug(u);
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}