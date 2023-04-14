#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10;
vector<pair<int,int>> adj[N];

int dfs(int x,int fa,int dis){
    int res=1;
    for(auto [s,d]:adj[x])
        if(s!=fa&&d<=dis)
            res+=dfs(s,x,dis-d);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(i,b);
        adj[i].emplace_back(a,b);
    }
    for(int i=1;i<=n;i++) cout<<dfs(i,-1,2)<<endl;
    return 0;
}