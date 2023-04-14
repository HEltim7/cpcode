#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
vector<int> adj[N];
int arr[N];
bool mark[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>arr[i];
        adj[arr[i]].push_back(arr[i]+1);
        adj[arr[i]+1].push_back(arr[i]);
    }
    for(int i=1;i<=n;i++) {
        if(!mark[i]) {
            queue<int> q;
            q.push(i);
            vector<int> res;
            while(q.size()) {
                int u=q.front();
                q.pop();
                if(mark[u]) continue;
                mark[u]=1;
                res.push_back(u);
                for(int v:adj[u]) {
                    q.push(v);
                }
            }
            sort(res.begin(),res.end(),greater<>());
            for(auto x:res) cout<<x<<' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}