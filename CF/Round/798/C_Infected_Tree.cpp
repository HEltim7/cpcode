#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=3e5+10;
vector<int> adj[N];
pair<int,int> ans;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void dfs(int u,int fa,int deep) {
    int res=0;
    for(auto v:adj[u]) {
        if(v!=fa) {
            dfs(v,u,deep+1);
            res++;
        }
    }
    if(res<2) {
        if(deep<ans.first) ans={deep,res};
        else if(deep==ans.first) ans.second=min(ans.second,res);
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) adj[i].clear();
    ans={n,1};
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1,1);
    debug(ans);
    cout<<n-ans.first*2+(ans.second==0)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}