#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
vector<int> adj[N];

vector<vector<int>> ans;
void dfs(int u,vector<int> &path) {
    path.push_back(u);
    if(adj[u].empty()){
        ans.push_back(path);
        return;
    }
    dfs(adj[u].back(),path);
    adj[u].pop_back();
    for(auto v:adj[u]){
        vector<int> tmp;
        dfs(v,tmp);
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) adj[i].clear();
    ans.clear();
    int rt=1;
    for(int i=1;i<=n;i++){
        int p;
        cin>>p;
        if(i!=p) adj[p].push_back(i);
        else rt=i;
    }
    vector<int> tmp;
    dfs(rt,tmp);
    cout<<ans.size()<<endl;
    for(auto x:ans) {
        cout<<x.size()<<endl;
        for(auto y:x) cout<<y<<' ';
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