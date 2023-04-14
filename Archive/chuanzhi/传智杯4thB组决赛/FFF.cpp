#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef unsigned long long LL;
const int N=5e5+10;
vector<pair<int,LL>> adj[N];
int n;
LL dp[N];

void dfs(int x,int fa){
    for(auto [a,b]:adj[x]){
        if(a==fa) continue;
        dp[a]=b^dp[x];
        dfs(a,x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    int m;
    cin>>m;
    for(int i=1;i<n;i++){
        int a,b;
        LL c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,-1);
    while(m--){
        int a,b;
        LL c;
        cin>>a>>b>>c;
        if((dp[a]^dp[b])==c) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}