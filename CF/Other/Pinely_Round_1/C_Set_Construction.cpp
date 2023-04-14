#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
vector<int> adj[N],ans[N];
int ind[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) adj[i].clear(),ans[i].clear(),ind[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            char c;
            cin>>c;
            if(c=='1') adj[i].push_back(j),ind[j]++;
        }

    vector<int> num(n);
    for(int i=1;i<=n;i++) num[i-1]=i;
    queue<int> q;
    for(int i=1;i<=n;i++) if(ind[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        ans[u].push_back(num.back());
        num.pop_back();
        sort(ans[u].begin(),ans[u].end());
        ans[u].erase(unique(ans[u].begin(),ans[u].end()),ans[u].end());
        for(int v:adj[u]) {
            for(auto x:ans[u]) ans[v].push_back(x);
            if(!--ind[v]) q.push(v);
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<ans[i].size()<<' ';
        for(auto x:ans[i]) cout<<x<<' ';
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}