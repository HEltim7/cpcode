#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1.5e3+10;
vector<int> adj[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        if(a==1) continue;
        adj[b].push_back(a);
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