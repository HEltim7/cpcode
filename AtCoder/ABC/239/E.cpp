#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
vector<int> adj[N];
int K=20;
int val[N];
vector<int> ans[N];

priority_queue<int,vector<int>,greater<int>> dfs(int x,int fa){
    priority_queue<int,vector<int>,greater<int>> heap;
    for(auto s:adj[x]){
        if(s==fa) continue;
        auto res=dfs(s,x);
        while(res.size()) heap.push(res.top()),res.pop();
    }
    heap.push(val[x]);
    while(heap.size()>K) heap.pop();
    auto bak=heap;
    while(bak.size()) ans[x].push_back(bak.top()),bak.pop();
    reverse(ans[x].begin(),ans[x].end());
    return heap;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    while(q--){
        int x,k;
        cin>>x>>k;
        cout<<ans[x][k-1]<<endl;
    }
    return 0;
}