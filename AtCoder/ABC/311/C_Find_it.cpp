#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
vector<int> adj[N];
bool mark[N];

vector<int> stk;
bool dfs(int u,int fa) {
    stk.push_back(u);
    if(mark[u]) return 1;
    mark[u]=1;
    for(int v:adj[u]) {
        if(dfs(v,u)) return 1;
    }
    mark[u]=0;
    stk.pop_back();
    return 0;
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int u;
        cin>>u;
        adj[i].push_back(u);
    }
    dfs(1,0);
    int st=stk.back();
    reverse(stk.begin(),stk.end());
    while(stk.back()!=st) stk.pop_back();
    stk.pop_back();

    cout<<stk.size()<<endl;
    reverse(stk.begin(),stk.end());
    for(int x:stk) cout<<x<<' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}